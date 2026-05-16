#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

class MotorStatus
{
private:
    uint8_t motorState;        // Each bit represents the status of a motor (on/off)
    uint8_t overheatingMotors; // Motors that are overheating
    int turnCount;

    void initialize()
    {
        std::srand(time(0));
        do
        {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0); // Ensure at least one motor is ON

        overheatingMotors = 0;
        turnCount = 0;
        updateOverheating();
    }

    void updateOverheating()
    {
        // Find motors that are ON but NOT yet overheating
        uint8_t availableToOverheat = motorState & ~overheatingMotors;

        if (availableToOverheat == 0)
        {
            turnCount++;
            return;
        }

        int newMotor;
        do
        {
            newMotor = std::rand() % 8;
        } while (!(availableToOverheat & (1u << newMotor)));

        overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
        turnCount++;
    }

public:
    MotorStatus()
    {
        initialize();
    }

    bool turnOff(uint8_t guess)
    {
        // Identify motors that are BOTH overheating AND guessed.
        uint8_t motorsToTurnOff = overheatingMotors & guess;

        // Turn OFF those motors in motorState.
        // Using (motorState &= ~mask) clears specific bits.
        motorState &= ~motorsToTurnOff;

        // Check if the guess matched the overheating status EXACTLY.
        if (guess == overheatingMotors)
        {
            std::cout << "SUCCESS! You identified all overheating motors.\n";
            // Clear overheating status since they are now off
            overheatingMotors &= ~guess;
            return true;
        }
        else
        {
            std::cout << "WRONG! Your guess did not match the overheating motors.\n";
            // If incorrect: update overheating to add pressure.
            updateOverheating();
            return false;
        }
    }

    // Status check for the student
    void displayCurrentStatus() const
    {
        std::cout << "\n--- System Report ---" << std::endl;
        std::cout << "Motor State (1=ON): " << std::bitset<8>(motorState) << std::endl;
        std::cout << "Turn Count: " << turnCount << std::endl;
        // Removed overheating motors
    }
};

int checkInput(const std::string &s)
{
    if (s.empty())
        return -1;

    // Parse binary
    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos)
    {
        return std::stoi(s, nullptr, 2);
    }
    // Parse hex
    if (s.size() >= 3 && (s.substr(0, 2) == "0x" || s.substr(0, 2) == "0X"))
    {
        try
        {
            unsigned long val = std::stoul(s, nullptr, 16);
            return (val <= 255) ? static_cast<int>(val) : -1;
        }
        catch (...)
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    MotorStatus motorStatus;
    std::string input;
    bool gameOver = false;

    std::cout << "--- MOTOR MELTDOWN ---\n";

    while (!gameOver)
    {
        motorStatus.displayCurrentStatus();

        std::cout << "\nEnter guess (8-bit binary or hex) or 'q' to quit: ";
        std::cin >> input;

        if (input == "q" || input == "Q")
            break;

        int val = checkInput(input);
        if (val == -1)
        {
            std::cout << "Invalid input. Try 00101000 or 0x28.\n";
            continue;
        }

        uint8_t guess = static_cast<uint8_t>(val);

        if (motorStatus.turnOff(guess))
        {
            gameOver = true;
            std::cout << "All systems nominal. Game Over.\n";
        }
    }

    return 0;
}
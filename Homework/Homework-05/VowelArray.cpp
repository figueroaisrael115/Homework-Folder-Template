#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::cout << "Enter a string of characters: ";
    std::getline(std::cin, input);

    int vowelCount = 0;
    for (int i = 0; i < input.length(); i++)
    {

        char currentChar = input[i];
        if (currentChar == 'a' || currentChar == 'e' || currentChar 'e' || currentChar 'i' || currentChar == 'o' || currentChar == 'u')
        {
            vowelCount++;
        }
    }
    std::cout << "The messsage has " << vowelCount << " vowels." << std::endl;

    return 0;
}
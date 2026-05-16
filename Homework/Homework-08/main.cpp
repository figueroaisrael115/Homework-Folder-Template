#include <iostream>
#include <string>

class Rock
{
public:
    // Basic Attack
    void attack()
    {
        std::cout << "Basic Attack: You kick the the rock.It doesn't move. (1 damage)" << std::endl;
    }
    // Physical Attack: int damage
    void attack(int damage)
    {
        std::cout << "Physical Attack: You punch the rock for "
                  << damage << " damage. It still didn't do much." << std::endl;
    }
    // Magical Attack: string spell, int damage
    void attack(std::string spell, int damage)
    {
        std::cout << "Magical Attack: You used " << spell
                  << "! The rock takes " << damage << " aura damage." << std::endl;
    }
};
int main()
{
    Rock targetRock;

    // chooses which attack to use based on the parameters
    targetRock.attack();
    targetRock.attack(50);
    targetRock.attack("FINAL FLASH", 120);

    return 0;
}
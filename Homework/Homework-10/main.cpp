#include <iostream>
#include <string>

class Pokemon
{
protected:
    std::string name;
    int level;
    // main class for the pokemon
public:
    Pokemon(std::string n, int l) : name(n), level(l) {}

    // virtual functions for polymorphism
    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;

    virtual void display() const
    {
        std::cout << "Name: " << name << ", Level: " << level;
    }
};
// broader class of electric types
class ElectricPokemon : public Pokemon
{
protected:
    std::string type = "Electric";

public:
    ElectricPokemon(std::string n, int l) : Pokemon(n, l) {}

    void display() const override
    {
        Pokemon::display();
        std::cout << ", Type: " << type << std::endl;
    }
};

// class of pikachu inheriting electric type traits
class Pikachu : public ElectricPokemon
{
public:
    Pikachu(int l) : ElectricPokemon("Pikachu", l) {}

    // overrides earlier virtual functions
    void attack() const override
    {
        std::cout << name << " uses Thunderbolt!" << std::endl;
    }

    void defend() const override
    {
        std::cout << name << " is guarding!" << std::endl;
    }

    void evolve() override
    {
        std::cout << name << " is evolving..." << std::endl;
        name = "Raichu";
    }
};

int main()
{
    Pikachu pikachu(10);

    // displays inherited traits
    pikachu.display();
    pikachu.attack();
    pikachu.defend();
    pikachu.evolve();
    pikachu.display();

    return 0;
}
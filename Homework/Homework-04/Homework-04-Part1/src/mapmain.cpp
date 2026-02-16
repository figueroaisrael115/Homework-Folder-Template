#include "mapstuff.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    std::string userName;
    double userX, userY;
    std::cout << "Enter Your Name: " << std::endl;
    std::getline(std::cin, userName);
    std::cout << "Enter Your X and Y Coordinates:" << std::endl;
    std::cin >> userX >> userY;

    generateRandomMap();

    if (isLocationValid(userX, userY))
    {
        std::cout << userName << " is inside the map." << std::endl;
    }
    else
    {
        std::cout << userName << "is outside the map and is not valid." << std::endl;
    }

    return 0;
}
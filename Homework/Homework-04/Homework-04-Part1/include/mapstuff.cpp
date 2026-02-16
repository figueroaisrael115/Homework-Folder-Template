#include "mapstuff.hpp'
#include <iostream>
#include <ctime>
#include <cstdlib>

double mapHalfWidth;
double mapHalfHeight;
void generateRandomMap()
{
    srand(static_cast<unsigned int>(time(0)));
    double fullWidth = (rand() % 20) + 1;
    double fullHeight = (rand() % 20) + 1;
    mapHalfHeight = fullHeight / 2.0;
    mapHalfWidth = fullWidth / 2.0;

    std::cout << "Map Half Width: " << mapHalfWidth << std::endl;
    std::cout << "Map Half Height: " << mapHalfHeight << std::endl;
}

bool isLocationValid(double x, double y)
{
    if (x >= -mapHalfWidth && x <= mapHalfHeight && y >= -mapHalfHeight && y <= mapHalfHeight)
    {
        return true;
    }
    else
    {
        return false;
    }
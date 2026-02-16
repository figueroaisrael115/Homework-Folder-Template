#ifndef mapstuff_hpp
#define mapstuff_hpp
#include <string>
// Map dimensions
extern double mapHalfWidth;
extern double mapHalfHeight;
// Functions
void generateRandomMap();
bool isLocationValid(double x, double y);

#endif
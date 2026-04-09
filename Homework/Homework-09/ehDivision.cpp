#include <iostream>
#include <stdexcept> //We need this to use std::runtime_error

double divide(int numerator, int denominator)
{
    std::cin >> numerator >> denominator;
    if (denominator == 0)
    {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    // Static cast to double makes it so we get a decimal result rather than integer division
    return static_cast<double>(numerator) / denominator;
}
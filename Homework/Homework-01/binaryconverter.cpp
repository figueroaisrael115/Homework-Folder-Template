#include <iostream>
// includes necessary libraries for input/output//
#include <iomanip>
// includes necessary libraries for input/output and formatting//
#include <string>
// includes necessary libraries for input/output and string handling//
#include "actualbinaryconverter.hpp"
// includes necessary libraries and the header file with encoding functions//
#include <bitset>
// this is needed for bitset//
#include <limits>
// This is needed for the ignore function//
int main()
{
    // Welcomes and lets the user know what order to enter their inputs //
    std::cout << "Hi! Enter Your Integer, Character, and Float" << std::endl;

    int intInput;
    std::string stringinput;
    char charInput;
    float floatInput;
    // this creates the user input that we will use to convert to binary//
    std::cout << "Enter your integer: ";
    std::cin >> intInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // gets integer input and ignores the newline character left in the buffer //
    std::cout << "Enter your character/s: ";
    std::getline(std::cin, stringinput);
    // to allow for string input including spaces //
    std::cout << "Enter a float: ";
    std::cin >> floatInput;
    // this outputs the binary translation of the user input//
    std::cout << "Binary representation of integer " << intInput << " is: "
              << encodeInt(intInput) << std::endl;
    std::cout << "Binary representation of string '" << stringinput << "' is: "
              << encodeString(stringinput) << std::endl;
    std::cout << "Binary representation of character '" << stringinput << "' is: "
              << encodeString(std::string(1, stringinput[0])) << std::endl;
    std::cout << "Binary representation of float " << floatInput << " is: "
              << encodeFloat(floatInput) << std::endl;
    return 0;
}
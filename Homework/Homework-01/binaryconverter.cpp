#include <iostream>
#include <iomanip>
#include <string>
#include <actualbinaryconverter.hpp>
#include <bitset>
int main()
{
    // this creates the user input that we will use to translate into binary//
    std::cout << "Input your stuff here! Or dont't its cool I guess." << std::endl;
    std::string input;
    std::getline(std::cin, input);

    // this block of code determines what type of input the user has given//
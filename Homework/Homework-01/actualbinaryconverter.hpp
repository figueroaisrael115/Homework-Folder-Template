#pragma once
// this makes sure the header file is only read once while it runs so we don't get multidefinition errors//
#include <bitset>
// this is the library tool we will use to actually do all the hard work in translating to binary//
#include <string>
// lets us use strings to output the binary results//
#include <sstream>
// lets us use string streams to help with the float conversion//

inline std::string encodeInt(int number)
{
    return std::bitset<32>(number).to_string();
}
// this function converts an integer to a binary string using 32 bits//
inline std::string encodeString(std::string text)
{
    std::stringstream result;

    for (char c : text)
    {
        // Converts the character to 8 bit segments and adds a space immediately after for easier checking when reverse translating//
        result << std::bitset<8>(c) << " ";
    }

    return result.str(); // Convert the stream back into a regular string
}
// this function converts each character in a string to its binary representation using 8 bits per character//
inline std::string encodeFloat(float number)
{
    unsigned int bits = *reinterpret_cast<unsigned int *>(&number);
    return std::bitset<32>(bits).to_string();
    // this function converts a float input into its binary translation//
}
#include <iostream>
#include <map>
#include <string>

int main()
{
    // Initialize the two map values using strings for the 1,10 format
    std::map<int, std::string> numbers1 = {
        {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}};

    std::map<int, int> numbers2 = {
        {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50}, {6, 60}, {7, 70}, {8, 80}, {9, 90}};

    // Interlace the maps using an iterator to traverse numbers2
    // and an operator[] to update numbers1. auto so we dont have to write allat out
    for (auto it = numbers2.begin(); it != numbers2.end(); ++it)
    {
        // If the key already exists, we add to it
        // If the key doesnt exist, the operator ([]) creates it
        if (numbers1.count(it->first))
        {
            numbers1[it->first] += ", " + std::to_string(it->second);
        }
        else
        {
            numbers1[it->first] = std::to_string(it->second);
        }
    }

    // Prints the interlaced map
    std::cout << "Interlaced map (numbers1): ";
    for (const auto &pair : numbers1)
    {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}
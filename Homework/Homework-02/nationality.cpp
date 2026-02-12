#include <iostream>
#include <string>
#include <iomanip>
int main()
{
    std::string nationality;
    std::cout << "Hi. Where are you from?" << std::endl;
    std::getline(std::cin, nationality);
    std::cout << "Wow , " << nationality << " is a beautiful place!" << std::endl;
    return 0;
}

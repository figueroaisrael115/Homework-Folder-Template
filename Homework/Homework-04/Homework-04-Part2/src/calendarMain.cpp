#include <iostream>
#include <string>
#include "../include/calendar.hpp"

int main()
{
    int year;
    std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << "Enter a Year: (YYYY)" << std::endl;
    if (!(std::cin >> year))
        return 1;

    int currentDay = getStartDay(year, 1);

    std::cout << "\n*** Calendar for " << year << "***\n";

    for (int i = 0; i < 12; i++)
    {
        int days = getDaysInMonth(i + 1, year);
        printMonth(months[i], days, currentDay);
    }
    return 0;
}
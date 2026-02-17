#include "../include/calendar.hpp"
#include <iostream>
#include <iomanip>

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

int getStartDay(int year, int month)
{
    static int t[] = {
        0,
        3,
        2,
        5,
        0,
        3,
        4,
        1,
        6,
        2,
        4,
    };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + 1) % 7;
}

void printMonth(std::string name, int days, int &startDay)
{
    std::cout << "\n --" << name << "--\n";
    std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";
    for (int i = 0; i < startDay; i++)
    {
        std::cout << std::setw(4) << " ";
    }
    for (int d = 1; d <= days; d++)
    {
        std::cout << std::setw(3) << d << " ";
        startDay++;
        if (startDay == 7)
        {
            std::cout << std::endl;
            startDay = 0;
        }
    }
    std::cout << std::endl;
}
#ifndef calendar_hpp
#define calendar_hpp
#include <string>

bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
int getStartDay(int year, int month);
void printMonth(std::string name, int days, int &startDay);

#endif
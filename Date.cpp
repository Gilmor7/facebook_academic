#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::showDate() const
{
    cout << (day < 10 ? "0" : "")
         << day << "/"
         << (month < 10 ? "0" : "")
         << month << "/"
         << year;
}
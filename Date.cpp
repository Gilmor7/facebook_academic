#include "Date.h"
#include <iostream>
#include "Exceptions.h"
#include <ctime>
using namespace std;

Date::Date(int day, int month, int year)
{
    if(!isDateValid(day, month, year))
        throw DateException();

    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(ifstream &in)
{
    in.read((char*)(this), sizeof(*this));
}

void Date::showDate() const
{
    cout << (day < 10 ? "0" : "")
         << day << "/"
         << (month < 10 ? "0" : "")
         << month << "/"
         << year;
}

bool Date::isLeapYear(int year)
{
    bool isLeap;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                isLeap = true;
            else
                isLeap = false;
        }
        else
            isLeap = true;
    }
    else
        isLeap= false;
    return isLeap;
}

bool Date::isDateValid(int day, int month, int year)
{

    bool validation = true;

    // Get current time data
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    int currYear = (tPtr->tm_year) + 1900;
    int currDay = (tPtr->tm_mday);
    int currMonth = (tPtr->tm_mon) + 1;

    // Check if year within range
    if (!(year >= 1800 && year <= currYear))
        validation = false;

    // Check if date is not in the future
    if(
        year == currYear &&
       (month > currMonth || (month == currMonth && day > currDay))
    )
        validation = false;

    if (day < 1)
        validation = false;

    // check the month
    switch (month) {
        case 2: // if February, check leap year
            if (isLeapYear(year))
                if (day > 29)
                    validation = false;
                else if (day > 28)
                    validation = false;
            break;
        case 1: //January
        case 3: //March
        case 5: //May
        case 7: //July
        case 8: //August
        case 10: //October
        case 12: //December
            if (day > 31)
                validation = false;
            break;
        case 4: //April
        case 6: //Jun
        case 9: //September
        case 11: //November
            if (day > 30)
                validation = false;
            break;
        default:
            validation = false;
            break;
    }
    return validation;
}
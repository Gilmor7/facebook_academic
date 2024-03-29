#ifndef FACEBOOK_ACADEMIC_DATE_H
#define FACEBOOK_ACADEMIC_DATE_H

#include <fstream>
using namespace std;

class Date
{
private:
    int day,month,year;

public:
    Date(int day, int month, int year);
    Date(ifstream& in);
    int getDay() const {return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}
    void showDate() const;

    static bool isDateValid(int day, int month, int year);
    static bool isLeapYear(int year);
};

#endif //FACEBOOK_ACADEMIC_DATE_H

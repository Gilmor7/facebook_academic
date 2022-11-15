//
// Created by Noel Freid on 15/11/2022.
//

#include "Status.h"
#include <iostream>
using namespace std;

Status::Status(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Status::showDate() const
{
    cout << "day: " << day << ", month: " << month << ", year: " << year << endl;
}
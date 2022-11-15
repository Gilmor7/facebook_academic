//
// Created by Noel Freid on 15/11/2022.
//

#ifndef FACEBOOK_ACADEMIC_STATUS_H
#define FACEBOOK_ACADEMIC_STATUS_H

class Status
{
private:
    int day,month,year;

public:
    Status(int day, int month, int year);
    int getDay() const {return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}
    void showDate() const;

};

#endif //FACEBOOK_ACADEMIC_STATUS_H

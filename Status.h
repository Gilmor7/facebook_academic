
#ifndef FACEBOOK_ACADEMIC_STATUS_H
#define FACEBOOK_ACADEMIC_STATUS_H

#include <ctime>
#include <string.h>
#include <iostream>
using namespace std;

class Status
{
private:
    char* text;
    time_t statusTime;

    void setText(const char* text);
public:
    Status(const char* text);
    Status(const Status& other);
    Status(Status&& other);
    ~Status();
    void showStatus() const;
};

#endif //FACEBOOK_ACADEMIC_STATUS_H

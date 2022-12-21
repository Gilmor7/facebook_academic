
#ifndef FACEBOOK_ACADEMIC_STATUS_H
#define FACEBOOK_ACADEMIC_STATUS_H

#include <ctime>
#include <string.h>
#include <iostream>
using namespace std;

class Status
{
private:
    std::string text;
    time_t statusTime;

public:
    Status(const std::string& text) noexcept(false);
    void showStatus() const;

    bool operator==(const Status& other) const;
    bool operator!=(const Status& other) const;
};

#endif //FACEBOOK_ACADEMIC_STATUS_H

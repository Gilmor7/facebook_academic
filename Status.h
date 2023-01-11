
#ifndef FACEBOOK_ACADEMIC_STATUS_H
#define FACEBOOK_ACADEMIC_STATUS_H

#include <ctime>
#include <iostream>
using namespace std;

class Status
{
protected:
    const string START_CMD = "start";

protected:
    string text;
    time_t statusTime;

public:
    Status(const string& text) noexcept(false);
    virtual void showStatus() const;

    bool operator==(const Status& other) const;
    bool operator!=(const Status& other) const;

protected:
    char* getCommand(const string &srcPath) const;
};

#endif //FACEBOOK_ACADEMIC_STATUS_H

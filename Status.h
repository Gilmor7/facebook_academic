
#ifndef FACEBOOK_ACADEMIC_STATUS_H
#define FACEBOOK_ACADEMIC_STATUS_H

#include <ctime>
#include <fstream>
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
    Status(ifstream& in);
    virtual void showStatus() const;
    virtual void save(ofstream& out) const;

    bool operator==(const Status& other) const;
    bool operator!=(const Status& other) const;

protected:
    char* getCommand(const string &srcPath) const;
};

#endif //FACEBOOK_ACADEMIC_STATUS_H

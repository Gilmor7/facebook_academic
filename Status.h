
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
    static const int TYPE_LEN = 3;

    Status(const string& text) noexcept(false);
    Status(ifstream& in);
    virtual void showStatus() const;
    virtual void save(ofstream& out) const;
    virtual void saveType(ofstream& out) const;

    virtual bool operator==(const Status& other) const;
    virtual bool operator!=(const Status& other) const;

protected:
    char* getCommand(const string &srcPath) const;
};

#endif //FACEBOOK_ACADEMIC_STATUS_H

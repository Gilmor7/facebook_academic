#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include <iostream>
#include "Status.h"
#include "FriendPage.h"
#include <string.h>
#include <vector>
using namespace std;

class FanPage
{
private:
    std::string pageName;
    vector<Status> statuses;
    vector<const FriendPage*> followers;    // FanPage cannot change followers

public:
    FanPage(const std::string& name) noexcept(false);

    // Getters
    const char* getName() const {return this->pageName.c_str();}
    const int getNumOfFollowers() const { return this->followers.size(); }

    void showFollowers() const;
    void showStatuses(int amount = ALL) const;
    void addStatus(Status& status);

    void showName() const;

    const FanPage& operator+=(const FriendPage& user) noexcept(false);
    const FanPage& operator-=(const FriendPage& user) noexcept(false);
    bool operator==(const FanPage& other) const;
    bool operator>(const FanPage& other) const;
    //bool operator>(const FriendPage& other) const;  waiting for update in FriendPage to support vectors

};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

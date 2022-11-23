
#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include "FriendPage.h"
#include "Status.h"
#include <iostream>
using namespace std;

class FriendPage;

class FanPage
{
private:
    char* pageName;
    const Status** statuses;
    FriendPage** followers;
    int followersLogSize, followersPhySize;
    int statusesLogSize, statusesPhySize;

    // private utility functions
    void doubleFollowersArr();
    void doubleStatusesArr();

public:
    FanPage(const char* name);
    FanPage(const FanPage& other) = delete;
    FanPage(FanPage&& other);
    ~FanPage();

    void addFollower(FriendPage& follower);
    void showFollowers() const;

    void showStatuses() const;
    void addStatues(const Status& status);

    void showName() const;
};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

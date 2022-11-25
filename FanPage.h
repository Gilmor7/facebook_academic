#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include "StatusArray.h"
#include "FriendArray.h"
#include <iostream>
#include "Status.h"
#include "FriendPage.h"
#include <string.h>

using namespace std;

class Status;
class FriendPage;

class FanPage
{
private:
    char* pageName;
    StatusArray statusesArr;
    FriendArray followersArr;

public:
    FanPage(const char* name);
    FanPage(const FanPage& other) = delete;
    FanPage(FanPage&& other);
    ~FanPage();

    // Getters
    const char* getName() const {return this->pageName;}

    void addFollower(FriendPage& follower);
    void removeFollower(FriendPage& follower);
    void showFollowers() const;

    void showStatuses(int amount = ALL) const;
    void addStatus(Status& status);

    int findFollowerIndexInArr(FriendPage& follower);
    void showName() const;
};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "FanPage.h"
#include "Status.h"

class FriendPage
{
private:
    // Date birthDate;

    const char* name;

    FriendPage** friends;
    int physiqueNumOfFriends;
    int logicNumOfFriends;


    int physiqueNumOfFanPages;
    int logicNumOfFanPages;

public:
    FriendPage() = default; // for testing only

    void showName() const;
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

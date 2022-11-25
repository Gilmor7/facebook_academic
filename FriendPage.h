#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "FriendArray.h"
#include "StatusArray.h"
#include "FanPageArray.h"

const int NOT_FOUND = -1;

class FriendPage
{
private:
    char* name;
    Date birthDate;

    FriendArray friendsArr;
    FanPageArray fanPagesArr;
    StatusArray statusesArr;

public:
    FriendPage(const char* name, Date& birthDate);
    FriendPage(const FriendPage& other) = delete;
//    FanPage(FanPage&& other);
    ~FriendPage();

    // getters
    const char* getName() const {return this->name;}

    void showName() const;

    int findFriendIndexByName(const char* nameToFind);
    void addFriend(FriendPage* newFriend);
    void removeFriend(FriendPage* friendToRemove);
    void showFriends() const;
    void showFriendsStatuses(int amount) const;

    void followFanPage(FanPage& fanPage);
    void unfollowFanPage();

    void showStatuses() const;
    void addStatus(Status& status);
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

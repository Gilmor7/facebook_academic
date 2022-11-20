#ifndef FACEBOOK_ACADEMIC_FRIEND_PAGE_H
#define FACEBOOK_ACADEMIC_FRIEND_PAGE_H

#include "page.h"
#include "Date.h"

class FanPage;

class FriendPage : public Page
{
private:
    Date birthDate;

    FriendPage** friends;
    int physiqueNumOfFriends;
    int logicNumOfFriends;

    FanPage** followingFanPages;
    int physiqueNumOfFanPages;
    int logicNumOfFanPages;

public:
    FriendPage(char* name, Date birthDate);
    FriendPage(FriendPage& otherFriend);
    FriendPage(FriendPage&& otherFriend);
    ~FriendPage();

    //Methods
    void addFriend(FriendPage*& newFriend); //Maybe just get a pointer instead?
    void removeFriend(); //get a name or index? if index let's create new method that gets a name and returns index and it is private to the class.
    void showAllFriends() const;
    void showFriendsStatuses() const;

    void followFanPage();
    void unfollowFanPage();

};


#endif //FACEBOOK_ACADEMIC_FRIEND_PAGE_H

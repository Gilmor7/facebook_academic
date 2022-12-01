#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "FriendArray.h"
#include "StatusArray.h"
#include "FanPageArray.h"


class FriendPage
{
public:
    static constexpr int NOT_FOUND = -1;
    static constexpr const char* const PAGE_IS_FOLLOWED = "You are already following this page\n";
    static constexpr const char* const PAGE_IS_NOT_FOLLOWED = "You are not following this page\n";
private:
    char* name;
    Date birthDate;

    FriendArray friendsArr;
    FanPageArray fanPagesArr;
    StatusArray statusesArr;

public:
    FriendPage(const char* name, Date birthDate);
    FriendPage(const FriendPage& other) = delete;
    FriendPage(FriendPage&& other);
    ~FriendPage();

    // getters
    const char* getName() const {return this->name;}
    const FriendArray* getFriendsArray() const { return &this->friendsArr; }
    const FanPageArray* getFollowingPages() const { return &this->fanPagesArr; }

    void show() const;

    static int findFriendIndex(FriendPage& friendPage, const FriendArray* friends);
    void addFriend(FriendPage& newFriend);
    void removeFriend(FriendPage& friendToRemove);
    void showFriends() const;
    void showFriendsStatuses(int amount) const;
    
    bool followFanPage(FanPage& fanPage);
    bool unfollowFanPage(FanPage& fanPage);

    void showStatuses(int amount = ALL) const;
    void addStatus(Status& status);
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

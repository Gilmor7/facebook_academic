#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "Status.h"
#include <string>
#include <vector>

const int ALL = -1;

class FanPage;
class FriendPage;

class FriendPage
{
public:
    static constexpr const char* const PAGE_IS_FOLLOWED = "You are already following this page\n";
    static constexpr const char* const PAGE_IS_NOT_FOLLOWED = "You are not following this page\n";
private:
    string name;
    Date birthDate;

    vector<const FriendPage*> friendsArr;    // FriendPage cannot change friends
    vector<const FanPage*> fanPagesArr;    // FriendPage cannot change fan pages
    vector<Status> statuses;

public:
    FriendPage(const string& name, Date birthDate) noexcept(false);

    // getters
    const string getName() const {return this->name.c_str();}
    const int getNumOfFriends() const { return this->friendsArr.size(); }

    void show() const;
    void addFriend(FriendPage& newFriend);
    void removeFriend(FriendPage& friendToRemove);
    void showFriends() const;
    void showFriendsStatuses(int amount) const;
//
    void followFanPage(FanPage& fanPage) noexcept(false);
    void unfollowFanPage(FanPage& fanPage) noexcept(false);
//
    void showStatuses(int amount = ALL) const;
    void addStatus(Status& status);

    //operators
    bool operator==(const FriendPage& other) const;
    bool operator>(const FriendPage& other) const;
    bool operator>(const FanPage& other) const;
    const FriendPage& operator+=(const FriendPage& other);
    const FriendPage& operator-=(const FriendPage& other);
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

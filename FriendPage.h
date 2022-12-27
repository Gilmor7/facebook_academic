#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "Status.h"
#include <string>
#include <vector>
#include <algorithm>

const int ALL = -1;

class FanPage;
class FriendPage;

class FriendPage
{
public:
    static constexpr const char* const PAGE_IS_FOLLOWED = "You are already following this page";
    static constexpr const char* const PAGE_IS_NOT_FOLLOWED = "You are not following this page";
    static constexpr const char* const FRIEND_IS_FOLLOWED = "User already follow this friend!";
    static constexpr const char* const FRIEND_IS_NOT_FOLLOWED = "User does not follow this friend!";
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
    void addFriend(FriendPage& newFriend) noexcept(false);
    void removeFriend(FriendPage& friendToRemove) noexcept(false);
    void showFriends() const;
    void showFriendsStatuses(int amount) const;
    void showStatuses(int amount = ALL) const;
    void addStatus(Status& status);

    //operators
    bool operator==(const FriendPage& other) const;
    bool operator==(const string& str) const;
    bool operator!=(const FriendPage& other) const;
    bool operator>(const FriendPage& other) const;
    bool operator>(const FanPage& other) const;
    const FriendPage& operator+=(const FriendPage& other) noexcept(false);
    const FriendPage& operator+=(const FanPage& page) noexcept(false);
    const FriendPage& operator-=(const FriendPage& other) noexcept(false);
    const FriendPage& operator-=(const FanPage& page) noexcept(false);
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

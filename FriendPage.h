#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "Page.h"

class FanPage;
class FriendPage;

class FriendPage: public Page
{
private:
    Date birthDate;
    vector<const FanPage*> fanPagesArr;    // FriendPage cannot change fan pages

public:
    FriendPage(const string& name, Date birthDate) noexcept(false);

    virtual void show() const override;
    void addFriend(FriendPage& newFriend) noexcept(false);
    void removeFriend(FriendPage& friendToRemove) noexcept(false);
    void showFriendsStatuses(int amount) const;

    //operators
    const FriendPage& operator+=(const FriendPage& other) noexcept(false);
    const FriendPage& operator+=(const FanPage& page) noexcept(false);
    const FriendPage& operator-=(const FriendPage& other) noexcept(false);
    const FriendPage& operator-=(const FanPage& page) noexcept(false);
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

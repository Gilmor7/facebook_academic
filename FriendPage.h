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
    unordered_map<string, const FanPage*> fanPages;

public:
    FriendPage(const string& name, Date birthDate) noexcept(false);
    FriendPage(ifstream& in);

    virtual void show() const override;
    virtual void save(ofstream& out) const override;
    void addFriend(FriendPage& newFriend) noexcept(false);
    void removeFriend(FriendPage& friendToRemove) noexcept(false);
    void showFriendsStatuses(int amount) const;
    void saveFollowship(ofstream& out) const;

    //operators
    const FriendPage& operator+=(const FriendPage& other) noexcept(false);
    const FriendPage& operator+=(const FanPage& page) noexcept(false);
    const FriendPage& operator-=(const FriendPage& other) noexcept(false);
    const FriendPage& operator-=(const FanPage& page) noexcept(false);
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

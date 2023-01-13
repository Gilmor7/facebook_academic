#include "FanPage.h"

/// statuses methods

FanPage::FanPage(ifstream &in) : Page(in) {}

const FanPage& FanPage::operator+=(const FriendPage &user) noexcept(false)
{
    auto itr = this->followers.find(user.getName());
    if(itr == this->followers.end()) {
        this->followers.insert(make_pair(user.getName(), &user));
        return *this;
    }
    else
        throw AddNewFollowerFanPageException();
}

const FanPage& FanPage::operator-=(const FriendPage &user) noexcept(false)
{
    auto itr = this->followers.find(user.getName());
    if(itr != this->followers.end()) {
        this->followers.erase(itr);
        return *this;
    }
    else
        throw RemoveFollowerFanPageException();
}
#include "FanPage.h"

/// statuses methods

const FanPage& FanPage::operator+=(const FriendPage &user) noexcept(false)
{
    auto itr = std::find(this->followers.begin(), this->followers.end(), &user);
    if(itr == this->followers.end()) {
        this->followers.push_back(&user);
        return *this;
    }
    else
        throw AddNewFollowerFanPageException();
}

const FanPage& FanPage::operator-=(const FriendPage &user) noexcept(false)
{
    auto itr = std::find(this->followers.begin(), this->followers.end(), &user);
    if(itr != this->followers.end()) {
        swap(*itr, this->followers.back());
        this->followers.pop_back();
        return *this;
    }
    else
        throw RemoveFollowerFanPageException();
}
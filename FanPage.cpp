#include "FanPage.h"

FanPage::FanPage(const std::string &name) noexcept(false)
{
    if(name.empty())
        throw CreateNewPageFanPageException();
    this->pageName = name;
}

void FanPage::showName() const
{
    cout << this->pageName << endl;
}

void FanPage::showFollowers() const
{
    auto itr = this->followers.begin();
    auto itrEnd = this->followers.end();
    for(; itr != itrEnd; ++itr)
    {
        (*itr)->show();
    }
}

/// statuses methods

void FanPage::showStatuses(int amount) const
{
    cout << this->pageName << " posts: " << endl;
    auto itr = this->statuses.begin();
    auto itrEnd = this->statuses.end();
    for(; itr != itrEnd; ++itr)
    {
        itr->showStatus();
    }
}

void FanPage::addStatus(Status &status)
{
    this->statuses.push_back(status);
}

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

bool FanPage::operator>(const FanPage &other) const
{
    return this->followers.size() > other.followers.size();
}

bool FanPage::operator==(const FanPage &other) const
{
    return this->pageName == other.pageName;
}

bool FanPage::operator!=(const FanPage &other) const
{
    return this->pageName != other.pageName;
}

bool FanPage::operator>(const FriendPage &other) const
{
    return this->followers.size() > other.getNumOfFriends();
}

bool FanPage::operator==(const string &name) const {
    return this->pageName == name;
}

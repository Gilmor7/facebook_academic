#include "FanPage.h"

FanPage::FanPage(const std::string &name) noexcept(false)
{
    if(name.empty())
        throw "Name cannot be empty!\n";
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
    auto itr = this->followers.begin();
    auto itrEnd = this->followers.end();
    for(; itr != itrEnd; ++itr)
    {
        if(*itr == &user)
            throw "You are already following this page\n";
    }
    this->followers.push_back(&user);
    return *this;
}

const FanPage& FanPage::operator-=(const FriendPage &user) noexcept(false)
{
    auto itr = this->followers.begin();
    auto itrEnd = this->followers.end();
    for(; itr != itrEnd; ++itr)
    {
        if(*itr == &user)
        {
            this->followers.erase(itr);
            return *this;
        }
    }
    throw "You are not following this page\n";
}

bool FanPage::operator>(const FanPage &other) const
{
    auto size1 = this->followers.size();
    auto size2 = other.followers.size();
    return size1 > size2;
}

//bool FanPage::operator>(const FriendPage &other) const
//{
//    auto size1 = this->followers.size();
//    auto size2 = other vectors size;
//    return size1 > size2;
//}
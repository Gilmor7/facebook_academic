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
    auto itr = find(this->followers.begin(), this->followers.end(), &user);
    if(itr == this->followers.end()) {
        this->followers.push_back(&user);
        return *this;
    }
    else
        throw "User already follows this page!\n";
}

const FanPage& FanPage::operator-=(const FriendPage &user) noexcept(false)
{
    auto itr = find(this->followers.begin(), this->followers.end(), &user);
    if(itr != this->followers.end()) {
        swap(*itr, this->followers.back());
        this->followers.pop_back();
        return *this;
    }
    else
        throw "User does not follow this page!\n";
}

bool FanPage::operator>(const FanPage &other) const
{
    auto size1 = this->followers.size();
    auto size2 = other.followers.size();
    return size1 > size2;
}

bool FanPage::operator==(const FanPage &other) const {
    return this->pageName == other.pageName;
}

//bool FanPage::operator>(const FriendPage &other) const
//{
//    auto size1 = this->followers.size();
//    auto size2 = other vectors size;  // You can use getNumOfFriends method that I added to FriendPage for this purpose
//    return size1 > size2;
//}
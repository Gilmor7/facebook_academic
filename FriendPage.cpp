#include <iostream>
#include "FriendPage.h"
#include "FanPage.h"

using namespace std;

FriendPage::FriendPage(const string& name, Date birthDate) noexcept(false):
    birthDate(birthDate)
{
    if(name.empty())
        throw "Name cannot be empty!\n";

    this->name = name;
}

 void FriendPage::show() const
{
    cout << "Name: " << this->name << endl << "Birth date: ";
    this->birthDate.showDate();
    cout << endl;
}

void FriendPage::addFriend(FriendPage& newFriend)
{
    this->friendsArr.push_back(&newFriend);
}

void FriendPage::removeFriend(FriendPage& friendToRemove)
{
    auto itr = find(this->friendsArr.begin(), this->friendsArr.end(), &friendToRemove);

    if(itr != this->friendsArr.end()) {
        swap(*itr, this->friendsArr.back());
        this->friendsArr.pop_back();
    }
    else
        throw "User does not follow this friend!\n";
}

void FriendPage::showFriends() const
{
    auto itr = this->friendsArr.begin();
    auto itrEnd = this->friendsArr.end();

    for (; itr != itrEnd ; ++itr) {
        (*itr)->show();
    }
}

void FriendPage::showFriendsStatuses(int amount) const
{
    auto itr = this->friendsArr.begin();
    auto itrEnd = this->friendsArr.end();

    for (; itr != itrEnd; ++itr) {
        (*itr)->showStatuses(amount);
    }
}

void FriendPage::followFanPage(FanPage& fanPage) noexcept(false)
{
    auto itr = find(this->fanPagesArr.begin(),this->fanPagesArr.end() , fanPage);
    if(itr != this->fanPagesArr.end())
        throw PAGE_IS_FOLLOWED;

    this->fanPagesArr.push_back(&fanPage);
}

void FriendPage::unfollowFanPage(FanPage& fanPage) noexcept(false)
{
    auto itr = find(this->fanPagesArr.begin(),this->fanPagesArr.end() , fanPage);
    if(itr == this->fanPagesArr.end())
        throw PAGE_IS_NOT_FOLLOWED;

    swap(*itr, this->fanPagesArr.back());
    this->fanPagesArr.pop_back();
}

/// statuses methods
void FriendPage::showStatuses(int amount) const
{
    auto itr = this->statuses.begin();
    auto itrEnd = this->statuses.end();

    for(; itr != itrEnd; ++itr)
    {
        itr->showStatus();
    }
}

void FriendPage::addStatus(Status &status)
{
    this->statuses.push_back(status);
}

// Operators
bool FriendPage::operator==(const FriendPage &other) const
{
    return this->name == other.name;
}

bool FriendPage::operator>(const FriendPage& other) const
{
    return this->friendsArr.size() > other.friendsArr.size();
}

bool FriendPage::operator>(const FanPage& other) const
{
    return this->friendsArr.size() > other.getNumOfFollowers();
}

const FriendPage& FriendPage::operator+=(const FriendPage& other)
{

}

const FriendPage& FriendPage::operator-=(const FriendPage& other)
{

}
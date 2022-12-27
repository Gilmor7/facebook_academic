#include <iostream>
#include "FriendPage.h"
#include "FanPage.h"
#include "Exceptions.h"

using namespace std;

FriendPage::FriendPage(const string& name, Date birthDate) noexcept(false):
    birthDate(birthDate)
{
    if(name.empty())
        throw FriendPageException("Name cannot be empty!", FriendPageException::actions::CREATE_NEW_USER);

    this->name = name;
}

 void FriendPage::show() const
{
    cout << "Name: " << this->name << endl << "Birth date: ";
    this->birthDate.showDate();
    cout << endl;
}

void FriendPage::addFriend(FriendPage& newFriend) noexcept(false)
{
    try {
        (*this) += newFriend;
    }
    catch(FriendPageException& e)
    {
        throw e;
    }
}

void FriendPage::removeFriend(FriendPage& friendToRemove) noexcept(false)
{
    try {
        (*this) -= friendToRemove;
    }
    catch(FriendPageException& e)
    {
        throw e;
    }
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

/// statuses methods
void FriendPage::showStatuses(int amount) const
{
    cout << this->name << " posts: " << endl;
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

bool FriendPage::operator==(const string& str) const {
    return this->name == str;
}

bool FriendPage::operator!=(const FriendPage &other) const {
    return this->name != other.name;
}

bool FriendPage::operator>(const FriendPage& other) const
{
    return this->friendsArr.size() > other.friendsArr.size();
}

bool FriendPage::operator>(const FanPage& other) const
{
    return this->friendsArr.size() > other.getNumOfFollowers();
}

const FriendPage& FriendPage::operator+=(const FriendPage& other) noexcept(false)
{
    auto itr = std::find(this->friendsArr.begin(), this->friendsArr.end(), &other);
    if(itr != this->friendsArr.end())
        throw FriendPageException(FRIEND_IS_FOLLOWED, FriendPageException::actions::ADD_FRIEND);

    this->friendsArr.push_back(&other);
    return (*this);
}

const FriendPage& FriendPage::operator-=(const FriendPage& other) noexcept(false)
{

    auto itr = std::find(this->friendsArr.begin(), this->friendsArr.end(), &other);
    if(itr == this->friendsArr.end())
        throw FriendPageException(FRIEND_IS_NOT_FOLLOWED, FriendPageException::actions::REMOVE_FRIEND);

    // Remove friend in O(1)
    swap(*itr, this->friendsArr.back());
    this->friendsArr.pop_back();
    return (*this);
}

const FriendPage &FriendPage::operator+=(const FanPage &page) noexcept(false) {
    auto itr = std::find(this->fanPagesArr.begin(), this->fanPagesArr.end(), &page);
    if(itr != this->fanPagesArr.end())
        throw FriendPageException(PAGE_IS_FOLLOWED, FriendPageException::actions::FOLLOW_NEW_FAN_PAGE);

    this->fanPagesArr.push_back(&page);
    return (*this);
}

const FriendPage &FriendPage::operator-=(const FanPage &page) noexcept(false) {
    auto itr = std::find(this->fanPagesArr.begin(), this->fanPagesArr.end(), &page);
    if(itr == this->fanPagesArr.end())
        throw FriendPageException(PAGE_IS_NOT_FOLLOWED, FriendPageException::actions::UNFOLLOW_FAN_PAGE);

    // Remove page in O(1)
    swap(*itr, this->fanPagesArr.back());
    this->fanPagesArr.pop_back();
    return (*this);
}



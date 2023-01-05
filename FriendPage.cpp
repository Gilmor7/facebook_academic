#include <iostream>
#include "FriendPage.h"
#include "FanPage.h"
using namespace std;

FriendPage::FriendPage(const string& name, Date birthDate) noexcept(false):
    birthDate(birthDate), Page(name){}

void FriendPage::show() const
{
    Page::show();
    cout << "BirthDate: ";
    this->birthDate.showDate();
    cout << endl;
}

void FriendPage::addFriend(FriendPage& newFriend) noexcept(false)
{
        (*this) += newFriend;
}

void FriendPage::removeFriend(FriendPage& friendToRemove) noexcept(false)
{
        (*this) -= friendToRemove;
}

void FriendPage::showFriendsStatuses(int amount) const
{
    auto itr = this->followers.begin();
    auto itrEnd = this->followers.end();

    for (; itr != itrEnd; ++itr) {
        (*itr)->showStatuses(amount);
    }
}

// Operators
const FriendPage& FriendPage::operator+=(const FriendPage& other) noexcept(false)
{
    auto itr = std::find(this->followers.begin(), this->followers.end(), &other);
    if(itr != this->followers.end())
        throw AddFriendToUserUserException();

    this->followers.push_back(&other);
    return (*this);
}

const FriendPage& FriendPage::operator-=(const FriendPage& other) noexcept(false)
{

    auto itr = std::find(this->followers.begin(), this->followers.end(), &other);
    if(itr == this->followers.end())
        throw RemoveFriendFromUserUserException();

    // Remove friend in O(1)
    swap(*itr, this->followers.back());
    this->followers.pop_back();
    return (*this);
}

const FriendPage &FriendPage::operator+=(const FanPage &page) noexcept(false) {
    auto itr = std::find(this->fanPagesArr.begin(), this->fanPagesArr.end(), &page);
    if(itr != this->fanPagesArr.end())
        throw FollowNewFanPageUserException();

    this->fanPagesArr.push_back(&page);
    return (*this);
}

const FriendPage &FriendPage::operator-=(const FanPage &page) noexcept(false) {
    auto itr = std::find(this->fanPagesArr.begin(), this->fanPagesArr.end(), &page);
    if(itr == this->fanPagesArr.end())
        throw UnfollowFanPageUserException();

    // Remove page in O(1)
    swap(*itr, this->fanPagesArr.back());
    this->fanPagesArr.pop_back();
    return (*this);
}



#include <iostream>
#include "FriendPage.h"
#include "FanPage.h"
using namespace std;

FriendPage::FriendPage(const string& name, Date birthDate) noexcept(false):
    birthDate(birthDate), Page(name){}

FriendPage::FriendPage(ifstream &in) : Page(in), birthDate(in){}

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
        itr->second->showStatuses(amount);
    }
}

void FriendPage::saveFollowship(ofstream &out) const
{
    int len1 = this->pageName.size();
    auto itr = this->fanPages.begin();
    auto itrEnd = this->fanPages.end();
    for(; itr != itrEnd; ++itr)
    {
        int len2 = itr->second->getName().size();

        out.write((char*)&len1, sizeof(len1));
        out.write(&pageName[0], len1);

        out.write((char*)&len2, sizeof(len2));
        out.write(&itr->second->getName()[0], len2);
    }
}

void FriendPage::save(ofstream &out) const
{
    Page::save(out);
    out.write((char*)&birthDate, sizeof(birthDate));
}

// Operators
const FriendPage& FriendPage::operator+=(const FriendPage& other) noexcept(false)
{
    auto itr = this->followers.find(other.getName());
    if(itr != this->followers.end())
        throw AddFriendToUserUserException();

    this->followers.insert(make_pair(other.getName(), &other));
    return (*this);
}

const FriendPage& FriendPage::operator-=(const FriendPage& other) noexcept(false)
{

    auto itr = this->followers.find(other.getName());
    if(itr == this->followers.end())
        throw RemoveFriendFromUserUserException();

    // Remove friend in O(1)
    this->followers.erase(itr);
    return (*this);
}

const FriendPage &FriendPage::operator+=(const FanPage &page) noexcept(false) {
    auto itr = this->fanPages.find(page.getName());
    if(itr != this->fanPages.end())
        throw FollowNewFanPageUserException();

    this->fanPages.insert(make_pair(page.getName(), &page));
    return (*this);
}

const FriendPage &FriendPage::operator-=(const FanPage &page) noexcept(false) {
    auto itr = this->fanPages.find(page.getName());
    if(itr == this->fanPages.end())
        throw UnfollowFanPageUserException();

    // Remove page in O(1)
    this->fanPages.erase(itr);
    return (*this);
}



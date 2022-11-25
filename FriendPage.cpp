#include <iostream>
#include "FriendPage.h"

using namespace std;

FriendPage::FriendPage(const char* name, Date birthDate): birthDate(birthDate)
{
    // Set Name
    int len = strlen(name) + 1;
    this->name = new char[len];
    strcpy(this->name, name);
}

FriendPage::FriendPage(FriendPage &&other): birthDate(other.birthDate)
{
    this->name = other.name;
    other.name = nullptr;

    this->statusesArr = other.statusesArr;
    other.statusesArr.emptyArrPtr();

    this->friendsArr = other.friendsArr;
    other.friendsArr.emptyArrPtr();

    this->fanPagesArr = other.fanPagesArr;
    other.fanPagesArr.emptyArrPtr();
}

FriendPage::~FriendPage()
{
    delete[] this->name;
}

 void FriendPage::show() const
{
    cout << "Name: " << this->name << endl << "Birth date: ";
    this->birthDate.showDate();
    cout << endl;
}

int FriendPage::findFriendIndex(FriendPage& friendPage)
{
    int index = NOT_FOUND;
    int friendsArrSize = this->friendsArr.getSize();
    const char* friendsName = friendPage.getName();

    for (int i = 0; i < friendsArrSize && index == NOT_FOUND; ++i) {
        if(strcmp(
                friendsName,
                this->friendsArr.getFriendAtIndex(i)->getName()
                ) == 0)
        {
          index = i;
        }
    }

    return index;
}

void FriendPage::addFriend(FriendPage& newFriend)
{
    this->friendsArr.push(&newFriend);
}

void FriendPage::removeFriend(FriendPage& friendToRemove)
{
    int indexToRemove = findFriendIndex(friendToRemove);
    this->friendsArr.remove(indexToRemove);
}

void FriendPage::showFriends() const
{
    this->friendsArr.show();
}

void FriendPage::showFriendsStatuses(int amount) const
{
    int friendsArrSize = this->friendsArr.getSize();

    for (int i = 0; i < friendsArrSize; ++i) {
        friendsArr.getFriendAtIndex(i)->showStatuses(amount);
    }
}

void followFanPage(FanPage& fanPage)
{

}

void unfollowFanPage()
{

}

/// statuses methods

void FriendPage::showStatuses(int amount) const
{
    this->statusesArr.show(amount);
}

void FriendPage::addStatus(Status &status)
{
    this->statusesArr.push(status);
}
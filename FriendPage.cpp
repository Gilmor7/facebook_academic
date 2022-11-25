#include <iostream>
#include "FriendPage.h"

using namespace std;

FriendPage::FriendPage(const char* name, Date& birthDate):
birthDate(birthDate.getDay(), birthDate.getMonth(), birthDate.getYear())
{
    // Set Name
    int len = strlen(name) + 1;
    this->name = new char[len];
    strcpy(this->name, name);
}

FriendPage::~FriendPage()
{
    delete[] this->name;
}

 void FriendPage::showName() const
{
    cout << this->name << endl;
}

int FriendPage::findFriendIndexByName(const char* nameToFind)
{
    int index = NOT_FOUND;
    int friendsArrSize = this->friendsArr.getSize();

    for (int i = 0; i < friendsArrSize, index == NOT_FOUND; ++i) {
        if(strcmp(
                nameToFind,
                this->friendsArr.getFriendAtIndex(i)->getName()
                ) == 0)
        {
          index = i;
        }
    }

    return index;
}

void FriendPage::addFriend(FriendPage* newFriend)
{
    this->friendsArr.push(newFriend);

    //newFriend.addFriend(*this); //TODO: Handle this like the coach and team example
}

void FriendPage::removeFriend(FriendPage* friendToRemove) //TODO:[Gil] - in my opinion we even should get here a name to make our "library as easy to use as possible
{
    const char* name = friendToRemove->getName();
    int indexToRemove = findFriendIndexByName(name);
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
        friendsArr.getFriendAtIndex(i)->statusesArr.show(amount);
    }
}

void followFanPage(FanPage& fanPage)
{

}

void unfollowFanPage()
{

}

/// statuses methods

void FriendPage::showStatuses() const
{
    this->statusesArr.show();
}

void FriendPage::addStatus(Status &status)
{
    this->statusesArr.push(status);
}
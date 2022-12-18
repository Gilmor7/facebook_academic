#include <iostream>
#include "FriendPage.h"
#include "FanPage.h"

using namespace std;

FriendPage::FriendPage(const std::string& name, Date birthDate): birthDate(birthDate)
{
    this->name = name;
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
    this->statusesArr.deleteStatuses();
}

 void FriendPage::show() const
{
    cout << "Name: " << this->name << endl << "Birth date: ";
    this->birthDate.showDate();
    cout << endl;
}

int FriendPage::findFriendIndex(FriendPage& friendPage, const FriendArray* friends)
{
    int index = NOT_FOUND;
    int friendsArrSize = friends->getSize();
    const char* friendsName = friendPage.getName();

    for (int i = 0; i < friendsArrSize && index == NOT_FOUND; ++i) {
        if(strcmp(
                friendsName,
                friends->getFriendAtIndex(i)->getName()
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
    int indexToRemove = findFriendIndex(friendToRemove, &this->friendsArr);
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
        this->friendsArr.getFriendAtIndex(i)->showStatuses(amount);
    }
}

bool FriendPage::followFanPage(FanPage& fanPage)
{
    if(FanPage::findFanPageIndex(fanPage, &this->fanPagesArr) == NOT_FOUND)
    {
        this->fanPagesArr.push(&fanPage);
        return true;
    }
    else
        cout << PAGE_IS_FOLLOWED;
    return false;
}

bool FriendPage::unfollowFanPage(FanPage& fanPage)
{
    int indexToRemove = FanPage::findFanPageIndex(fanPage, &this->fanPagesArr);
    if(indexToRemove != NOT_FOUND){

        this->fanPagesArr.remove(indexToRemove);
        return true;
    }
    else
        cout << PAGE_IS_NOT_FOLLOWED;
    return false;
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

bool FriendPage::operator==(const FriendPage &other)
{
    return this->name == other.name;
}
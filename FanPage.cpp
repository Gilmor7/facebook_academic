#include "FanPage.h"

/// C'tors and D'tors

FanPage::FanPage(const char *name)
{
    int len = strlen(name) + 1;
    this->pageName = new char[len];
    strcpy(this->pageName, name);
}

FanPage::FanPage(FanPage &&other)
{
    this->pageName = other.pageName;
    other.pageName = nullptr;

    this->statusesArr = other.statusesArr;
    other.statusesArr.emptyArrPtr();

    this->followersArr = other.followersArr;
    other.followersArr.emptyArrPtr();
}

FanPage::~FanPage()
{
    this->statusesArr.deleteStatuses();
    delete[] this->pageName;
}

void FanPage::showName() const
{
    cout << this->pageName << endl;
}

int FanPage::findFanPageIndex(FanPage& fanPage, const FanPageArray* fanPages)
{
    int index = NOT_FOUND;
    int fanPagesArrSize = fanPages->getSize();
    const char* friendsName = fanPage.getName();

    for (int i = 0; i < fanPagesArrSize && index == NOT_FOUND; ++i) {
        if(strcmp(
                friendsName,
                fanPages->getFanPageAtIndex(i)->getName()
        ) == 0)
        {
            index = i;
        }
    }
    return index;
}

/// followers methods

bool FanPage::addFollower(FriendPage &follower)
{
    if(FriendPage::findFriendIndex(follower, &this->followersArr) == NOT_FOUND)
    {
        this->followersArr.push(&follower);
        return true;
    }
    else
        cout << "You are already following this page" << endl;
    return false;
}

bool FanPage::removeFollower(FriendPage &follower)
{
    int indexToRemove = FriendPage::findFriendIndex(follower, &this->followersArr);
    if(indexToRemove != NOT_FOUND)
    {
        this->followersArr.remove(indexToRemove);
        return true;
    }
    else
        cout << "You are not following this page" << endl;
    return false;
}

void FanPage::showFollowers() const
{
    this->followersArr.show();
}

/// statuses methods

void FanPage::showStatuses(int amount) const
{
    this->statusesArr.show(amount);
}

void FanPage::addStatus(Status &status)
{
    this->statusesArr.push(status);
}

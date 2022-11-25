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

    //TODO: Make sure we handle this part correctly
    this->statusesArr = other.statusesArr;
    other.statusesArr.changePtrForMoveCtor();
    this->followersArr = other.followersArr;
    other.followersArr.changePtrForMoveCtor();

}

FanPage::~FanPage()
{
    delete[] this->pageName;
}

void FanPage::showName() const
{
    cout << this->pageName << endl;
}

/// followers methods

void FanPage::addFollower(FriendPage &follower)
{
    if(this->findFollowerIndexInArr(follower) == NOT_FOUND)
        this->followersArr.push(&follower);
    cout << "You are already following this page" << endl;
}

void FanPage::removeFollower(FriendPage &follower)
{
    int indexToRemove = this->findFollowerIndexInArr(follower);
    if(indexToRemove != NOT_FOUND)
        this->followersArr.remove(indexToRemove);
    cout << "You are not following this page" << endl;
}

int FanPage::findFollowerIndexInArr(FriendPage& follower)
{
    int index = NOT_FOUND;
    int i;
    const int arrSize = this->followersArr.getSize();
    const FriendPage* friendPtr = nullptr;
    for(i=0; i < arrSize && index == NOT_FOUND; i++){
        friendPtr = this->followersArr.getFriendAtIndex(i);
        if(strcmp(friendPtr->getName(), follower.getName()) == 0)    // same name = same follower
            index = i;
    }
    return index;
}

void FanPage::showFollowers() const
{
    this->followersArr.show();
}

/// statuses methods

void FanPage::showStatuses() const
{
    this->statusesArr.show();
}

void FanPage::addStatus(Status &status)
{
    this->statusesArr.push(status);
}

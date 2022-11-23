
#include "FanPage.h"


/// C'tors and D'tors

FanPage::FanPage(const char *name)
{
    this->statuses = new const Status*[1];
    this->followers = new FriendPage*[1];

    this->followersLogSize = this->statusesLogSize = 0;
    this->followersPhySize = this->statusesPhySize = 1;

    int len = strlen(name) + 1;
    this->pageName = new char[len];
    strcpy(this->pageName, name);
}

FanPage::FanPage(FanPage &&other)
{
    this->pageName = other.pageName;
    other.pageName = nullptr;

    this->statuses = other.statuses;
    other.statuses = nullptr;

    this->followers = other.followers;
    other.followers = nullptr;

    this->followersPhySize = other.followersPhySize;
    this->followersLogSize = other.followersLogSize;

    this->statusesPhySize = other.statusesPhySize;
    this->statusesLogSize = other.statusesLogSize;

}

FanPage::~FanPage()
{
    delete[] this->pageName;
    delete[] this->followers;
    delete[] this->statuses;
}


/// followers methods

void FanPage::addFollower(FriendPage &follower)
{
    if(this->followersLogSize == this->followersPhySize)
    {
        this->doubleFollowersArr();
    }
    this->followers[this->followersLogSize] = &follower;
    this->followersLogSize++;

    //follower.followFanPage(*this);
}

void FanPage::showFollowers() const
{
    int i;
    for(i=0; i<this->followersLogSize; i++)
    {
        this->followers[i]->showName();
    }
}


/// statuses methods

void FanPage::showStatuses() const
{
    int i;
    for(i=0; i<this->statusesLogSize; i++)
    {
        this->statuses[i]->showStatus();
    }
}

void FanPage::addStatues(const Status &status)
{
    if(this->statusesLogSize == this->statusesPhySize)
    {
        this->doubleStatusesArr();
    }
    this->statuses[this->statusesLogSize] = &status;

}



/// realloc methods

void FanPage::doubleFollowersArr()
{
    this->followersPhySize *= 2;
    FriendPage** temp = new FriendPage*[this->followersPhySize];
    int i;
    for(i=0; i<this->followersLogSize; i++)
    {
        temp[i] = this->followers[i];
    }
    delete[] this->followers;
    this->followers = temp;
}

void FanPage::doubleStatusesArr()
{
    this->statusesPhySize *= 2;
    const Status** temp = new const Status*[this->statusesPhySize];
    int i;
    for(i=0; i<this->statusesLogSize; i++)
    {
        temp[i] = this->statuses[i];
    }
    delete[] this->statuses;
    this->statuses = temp;
}

void FanPage::showName() const
{
    cout << this->pageName << endl;
}

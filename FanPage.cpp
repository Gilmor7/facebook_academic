
#include "FanPage.h"
#include <iostream>
using namespace std;

FanPage::FanPage(const char* pageName) : Page(pageName)
{
    cout << "FanPage constructor" << endl;
    this->followers = new FriendPage*[1];
    this->followersLogSize = 1;
    this->followersPhySize = 0;
}

FanPage::FanPage(const FanPage &other) : Page(other)
{
    cout << "FanPage copy constructor" << endl;
    this->followers = new FriendPage*[other.followersPhySize];
    this->followersLogSize = other.followersLogSize;
    this->followersPhySize = other.followersPhySize;

    for (int i = 0; i < other.followersLogSize; i++)
    {
        this->followers[i] = other.followers[i];
    }
}

FanPage::FanPage(FanPage &&other) : Page(std::move(other))
{
    cout << "FanPage move constructor" << endl;
    this->followers = other.followers;
    other.followers = nullptr;

    this->followersLogSize = other.followersLogSize;
    this->followersPhySize = other.followersPhySize;
}

FanPage::~FanPage()
{
    cout << "FanPage destructor" << endl;
    delete[] this->followers;
}

void FanPage::addFollower(FriendPage &user)
{
    cout << "FanPage::addFollower" << endl;
    if (this->followersLogSize == this->followersPhySize)
    {
        this->doubleFollowersSize();
    }

    this->followers[this->followersLogSize] = &user;
    this->followersLogSize++;
}

void FanPage::doubleFollowersSize()
{
    cout << "FanPage::doubleFollowersSize" << endl;
    int i;
    this->followersPhySize *= 2;
    FriendPage** newArr = new FriendPage* [this->followersPhySize];
    for(i=0; i<this->followersLogSize; i++)
    {
        newArr[i] = this->followers[i];
    }
    delete[] this->followers;
    this->followers = newArr;
}

void FanPage::showFollowers() const
{
    cout << "FanPage::showFollowers" << endl;
    int i;
    for(i=0; i<this->followersLogSize; i++)
    {
        cout << this->followers[i]->getName() << endl;
    }
}

#include <iostream>
#include "FriendPage.h"

using namespace std;

FriendPage::FriendPage(const char* name)
{
    int len = strlen(name) + 1;
    this->name = new char[len];
    strcpy(this->name, name);
}

 void FriendPage::showName() const
{
    cout << this->name << endl;
}
#include <iostream>
#include "FriendArray.h"
#include "FriendPage.h"
using namespace std;

FriendArray::FriendArray()
{
    this->logSize = 0;
    this->phySize = 2;
    this->friends = new FriendPage*[phySize];
}

FriendArray::~FriendArray()
{
    delete[] this->friends;
}

/// Methods
void FriendArray::push(FriendPage* newFriend)
{
    if(this->logSize == this->phySize)
        realloc();

    this->friends[this->logSize] = newFriend;
    this->logSize += 1;
}

bool FriendArray::remove(int& indexToRemove)
{
    if(indexToRemove == NOT_FOUND || this->logSize == 0) // Nothing to remove
        return false;

    if(indexToRemove < this->logSize - 1) {
        for (int i = indexToRemove; i < this->logSize - 1; ++i)
            this->friends[i] = this->friends[i + 1];
    }

    this->logSize--;
    return true;
}

void FriendArray::show() const
{
    for(int i = 0; i < this->logSize; i++)
        this->friends[i]->show();
}

const bool FriendArray::isFriendInArr(FriendPage &user) const
{
    for(int i = 0; i < this->logSize; i++)
        if(strcmp(user.getName(), this->friends[i]->getName()) == 0)
            return true;
    return false;
}

void FriendArray::deleteAllUsers() {
    for (int i = 0; i < this->logSize; i++)
    {
        cout << "Deleting: " << this->friends[i]->getName() << endl;
        delete this->friends[i];
    }
    this->logSize = 0;
}

/// Private Methods
void FriendArray::realloc()
{
    this->phySize *= 2;
    FriendPage** updatedFriendArray = new FriendPage*[this->phySize];

    for (int i = 0; i < this->logSize; ++i) {
        updatedFriendArray[i] = this->friends[i];
    }

    delete[] this->friends;
    this->friends = updatedFriendArray;
}
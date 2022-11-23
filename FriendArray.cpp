#include <iostream>
#include "FriendArray.h"
#include "FriendPage.h"

FriendArray::FriendArray()
{
    std::cout << "in empty constructor of FriendArray"<< std::endl; //To remove
    this->logSize = 0;
    this->phySize = 2;
    friends = new FriendPage*[phySize];
}

FriendArray::~FriendArray()
{
    std::cout << "in D'tor of FriendArray"<< std::endl; //To remove
    delete[] friends;
}

/// Methods
void FriendArray::push(FriendPage& newFriend)
{
    if(this->logSize == this->phySize)
        realloc();

    this->friends[this->logSize] = &newFriend;
    this->logSize += 1;
}

bool FriendArray::remove(int& indexToRemove)
{
    if(indexToRemove == NOT_FOUND || this->logSize == 0) // Nothing to remove
        return false;

    for (int i = indexToRemove; i < this->logSize - 1; ++i)
        this->friends[i] = this->friends[i + 1];

    this->logSize--;
    return true;
}

void FriendArray::show() const
{
    for(int i = 0; i < this->logSize; i++)
        this->friends[i]->showName();
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
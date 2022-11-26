
#include "Bookface.h"

/// C'tor and D'tor
BookFace::BookFace()
{
    this->is_running = true;
}

BookFace::~BookFace()
{
    cout << "Goodbye!" << endl;
    users.deleteAllUsers();
    fanPages.deleteAllPages();
}


/// Menu functions
void BookFace::addUser(FriendPage &newUser)
{
    const bool isExists = this->users.isFriendInArr(newUser);
    if(isExists)
        cout << "User already exists" << endl;
    else
        this->users.push(&newUser);
}

void BookFace::addPage(FanPage &newFanPage)
{
    const bool isExists = this->fanPages.isFanPageInArr(newFanPage);
    if(isExists)
        cout << "Page already exists" << endl;
    else
        this->fanPages.push(&newFanPage);
}


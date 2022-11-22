
#include "Bookface.h"

BookFace::BookFace()
{
    // allocate arrays here
    // set logical & physical sizes here

    this->is_running = true;
}

bool BookFace::addUser(const char *name, Date date)
{
    if(isEntityInArr(name, true))
    {
        cout << "User already exists in the system!" << endl;
        return false;
    }
    else
    {
        if(this->usersLogSize == this->usersPhySize)
        {
            doubleArrSize(true);
        }
        this->usersArr[this->usersLogSize] = new FriendPage(name, date);
        this->usersLogSize++;
        return true;
    }
}

bool BookFace::addPage(const char *name)
{
    if(isEntityInArr(name, false))
    {
        cout << "Page already exists in the system!" << endl;
        return false;
    }
    else
    {
        if(this->fanPageLogSize == this->fanPagePhySize)
        {
            doubleArrSize(false);
        }
        this->fanPagesArr[this->fanPageLogSize] = new FanPage(name);
        this->fanPageLogSize++;
        return true;
    }
}

void BookFace::doubleArrSize(bool isUserArr)
{
    if(isUserArr)
    {
        FriendPage** temp = new FriendPage*[this->usersPhySize * 2];
        for(int i = 0; i < this->usersLogSize; i++)
        {
            temp[i] = this->usersArr[i];
        }
        delete[] this->usersArr;
        this->usersArr = temp;
        this->usersPhySize *= 2;
    }
    else
    {
        FanPage** temp = new FanPage*[this->fanPagePhySize * 2];
        for(int i = 0; i < this->fanPageLogSize; i++)
        {
            temp[i] = this->fanPagesArr[i];
        }
        delete[] this->fanPagesArr;
        this->fanPagesArr = temp;
        this->fanPagePhySize *= 2;
    }
}
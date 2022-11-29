
#include "UserInterface.h"
// d'tor
UserInterface::~UserInterface()
{
    this->system.deleteUsers();
    this->system.deleteFanPages();
}


// system functions
void UserInterface::addUser()
{
    FriendPage* newFriend = nullptr;
    char name[MAX_NAME_LEN];
    int day,month,year;
    cout << ENTER_NAME;
    cin >> name;
    cout << ENTER_BIRTH_DATE;
    cin >> day >> month >> year;
    newFriend = new FriendPage(name, Date(day,month,year));
    if(!this->system.addUser(*newFriend))   // user already exists.
        delete newFriend;
}

void UserInterface::addPage()
{
    FanPage* newPage = nullptr;
    char name[MAX_NAME_LEN];
    cout << ENTER_NAME;
    cin >> name;
    newPage = new FanPage(name);
    if(!system.addPage(*newPage))   // page already exists
        delete newPage;
}






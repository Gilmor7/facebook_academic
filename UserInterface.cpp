
#include "UserInterface.h"


// system functions
void UserInterface::addUser(BookFace &system)
{
    char name[MAX_NAME_LEN];
    int day,month,year;
    cin >> name;
    cin >> day >> month >> year;
    FriendPage* newUser = new FriendPage(name, Date(day,month,year));
    if(!system.addUser(*newUser))
        delete newUser;
}

void UserInterface::addPage(BookFace &system)
{
    char name[MAX_NAME_LEN];
    cin >> name;
    FanPage* newPage = new FanPage(name);
    if(!system.addPage(*newPage))
        delete newPage;
}

void UserInterface::showAllRegistered(BookFace &system) const
{
    system.showAllRegistered();
}

void UserInterface::addStatus(BookFace &system)
{
    int choice;
    char name[MAX_NAME_LEN];
    char text[MAX_STATUS_TEXT_LEN];
    cin >> choice;
    cin >> name;
    cin >> text;
    if(choice == 1)
    {
        FriendPage* user = getFriendByNameFromSystem(name, system);
        if(user)
            system.addStatusToFriendPage(*user, *(new Status(text)));
    }
    else if(choice == 2)
    {
        FanPage* fanPage = getFanPageByNameFromSystem(name, system);
        if(fanPage)
            system.addStatusToFanPage(*fanPage, *(new Status(text)));
    }
    else
        cout << INVALID_CHOICE_MSG;
}

void UserInterface::showAllStatusesFromEntity(BookFace &system) const
{
    int choice;
    char name[MAX_NAME_LEN];
    cin >> choice;
    cin >> name;
    if(choice == 1)
    {
        FriendPage* user = getFriendByNameFromSystem(name, system);
        if(user)
            system.showAllStatusesFromFriend(*user);
    }
    else if(choice == 2)
    {
        FanPage* fanPage = getFanPageByNameFromSystem(name, system);
        if(fanPage)
            system.showAllStatusesFromFanPage(*fanPage);
    }
    else
        cout << INVALID_CHOICE_MSG;
}

void UserInterface::showAllStatusesFromUsersFriends(BookFace &system) const
{
    char name[MAX_NAME_LEN];
    cin >> name;
    FriendPage* user = getFriendByNameFromSystem(name, system);
    if(user)
        system.showAllStatusesFromUsersFriends(*user);
}


void UserInterface::connectUsers(BookFace &system)
{
    char name1[MAX_NAME_LEN];
    char name2[MAX_NAME_LEN];
    cin >> name1;
    cin >> name2;
    FriendPage* friend1 = getFriendByNameFromSystem(name1, system);
    FriendPage* friend2 = getFriendByNameFromSystem(name2, system);
    if(friend1 && friend2)
        system.connectUsers(*friend1, *friend2);
}

void UserInterface::removeUsersConnection(BookFace &system)
{
    char name1[MAX_NAME_LEN];
    char name2[MAX_NAME_LEN];
    cin >> name1;
    cin >> name2;
    FriendPage* friend1 = getFriendByNameFromSystem(name1, system);
    FriendPage* friend2 = getFriendByNameFromSystem(name2, system);
    if(friend1 && friend2)
        system.removeUsersConnection(*friend1, *friend2);
}

void UserInterface::followFanPage(BookFace &system)
{
    char userName[MAX_NAME_LEN];
    char pageName[MAX_NAME_LEN];
    cin >> userName;
    cin >> pageName;
    FriendPage* user = getFriendByNameFromSystem(userName, system);
    FanPage* page = getFanPageByNameFromSystem(pageName, system);
    if(user && page)
        system.followFanPage(*user, *page);
}

void UserInterface::unfollowFanPage(BookFace &system)
{
    char userName[MAX_NAME_LEN];
    char pageName[MAX_NAME_LEN];
    cin >> userName;
    cin >> pageName;
    FriendPage* user = getFriendByNameFromSystem(userName, system);
    FanPage* page = getFanPageByNameFromSystem(pageName, system);
    if(user && page)
        system.unfollowFanPage(*user, *page);
}

void UserInterface::showAllFollowersOfEntity(BookFace &system)
{
    int choice;
    char name[MAX_NAME_LEN];
    cin >> choice;
    cin >> name;
    if(choice == 1)
    {
        FriendPage* user = getFriendByNameFromSystem(name, system);
        if(user)
            system.showAllFriendsOfAUser(*user);
    }
    else if(choice == 2)
    {
        FanPage* fanPage = getFanPageByNameFromSystem(name, system);
        if(fanPage)
            system.showAllFollowersOfFanPage(*fanPage);
    }
    else
        cout << INVALID_CHOICE_MSG;
}

void UserInterface::stopTheProgram(BookFace &system)
{
    system.deleteFanPages();
    system.deleteUsers();
    system.stopTheProgram();
}


// interaction functions

void UserInterface::displayMenu() const
{
    cout << DISPLAY_MENU_MESSAGE;
}

void UserInterface::setOption(UserInterface::eOption newOption)
{
    this->currOption = newOption;
}

void UserInterface::activateOption(BookFace &system)
{
    switch(this->currOption)
    {
        case ADD_USER:
            this->addUser(system);
            break;
        case ADD_PAGE:
            this->addPage(system);
            break;
        case ADD_STATUS:
            this->addStatus(system);
            break;
        case SHOW_ENTITY_STATUSES:
            this->showAllStatusesFromEntity(system);
            break;
        case CONNECT_USERS:
            this->connectUsers(system);
            break;
        case REMOVE_USERS_CONNECTION:
            this->removeUsersConnection(system);
            break;
        case SHOW_LAST_STATUSES:
            this->showAllStatusesFromUsersFriends(system);
            break;
        case ADD_USER_TO_PAGE:
            this->followFanPage(system);
            break;
        case REMOVE_USER_FROM_PAGE:
            this->unfollowFanPage(system);
            break;
        case SHOW_ALL_ENTITIES:
            this->showAllRegistered(system);
            break;
        case SHOW_ALL_FOLLOWERS_OF_ENTITY:
            this->showAllFollowersOfEntity(system);
            break;
        case EXIT:
            this->stopTheProgram(system);
            break;
        default:
            cout << INVALID_CHOICE_MSG;
            break;
    }
}
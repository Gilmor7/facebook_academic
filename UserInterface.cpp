
#include "UserInterface.h"


/// functions
// system functions
void UserInterface::addUser(BookFace &system)
{
    string name = this->getNameAsString();
    int day,month,year;
    this->getBirthDate(&day, &month, &year);

    FriendPage newUser(name, Date(day,month,year));
    system.addUser(newUser);
}

void UserInterface::addPage(BookFace &system)
{
    string name = this->getNameAsString();
    FanPage newPage(name);
    system.addPage(newPage);
}

void UserInterface::showAllRegistered(BookFace &system) const
{
    system.showAllRegistered();
}

void UserInterface::addStatus(BookFace &system)
{
    int choice;
    string name;
    string text;
    this->getChoice(&choice);
    if(!this->validateChoice(choice))
        throw INVALID_CHOICE_MSG;

    name = this->getNameAsString();
    text = this->getStatusTextAsString();

    //TODO: Complete fixes here
    if(choice == 1)
    {
        FriendPage* user = getFriendByNameFromSystem(name, system);
        if(user)
            system.addStatusToFriendPage(*user, *(new Status(text)));
        else
            cout << USER_NOT_FOUND;
    }
    else if(choice == 2)
    {
        FanPage* fanPage = getFanPageByNameFromSystem(name, system);
        if(fanPage)
            system.addStatusToFanPage(*fanPage, *(new Status(text)));
        else
            cout << FANPAGE_NOT_FOUND;
    }
}

void UserInterface::showAllStatusesFromEntity(BookFace &system) const
{
    int choice;
    string name;

    this->getChoice(&choice);
    if(!this->validateChoice(choice))
        throw INVALID_CHOICE_MSG;

    name = this->getNameAsString();
    //Todo: complete fix here
    if(choice == 1)
    {
        FriendPage* user = getFriendByNameFromSystem(name, system);
        if(user)
            system.showAllStatusesFromFriend(*user);
        else
            cout << USER_NOT_FOUND;
    }
    else if(choice == 2)
    {
        FanPage* fanPage = getFanPageByNameFromSystem(name, system);
        if(fanPage)
            system.showAllStatusesFromFanPage(*fanPage);
        else
            cout << FANPAGE_NOT_FOUND;
    }
}

void UserInterface::showAllStatusesFromUsersFriends(BookFace &system) const
{
    string name = this->getNameAsString();
    //TODO: Complete here
    FriendPage* user = getFriendByNameFromSystem(name, system);
    if(user)
        system.showAllStatusesFromUsersFriends(*user);
    else
        cout << USER_NOT_FOUND;
}


void UserInterface::connectUsers(BookFace &system)
{
    string name1 = this->getNameAsString();
    string name2 = this->getNameAsString();

    //TODO: Continue here
    FriendPage* friend1 = getFriendByNameFromSystem(name1, system);
    FriendPage* friend2 = getFriendByNameFromSystem(name2, system);
    if(friend1 && friend2)
        system.connectUsers(*friend1, *friend2);
    else
        cout << ONE_OF_USERS_NOT_FOUND;
}

void UserInterface::removeUsersConnection(BookFace &system)
{
    string name1 = this->getNameAsString();
    string name2 = this->getNameAsString();

    FriendPage* friend1 = getFriendByNameFromSystem(name1, system);
    FriendPage* friend2 = getFriendByNameFromSystem(name2, system);
    if(friend1 && friend2)
        system.removeUsersConnection(*friend1, *friend2);
    else
        cout << ONE_OF_USERS_NOT_FOUND;
}

void UserInterface::followFanPage(BookFace &system)
{
    string userName;
    string pageName;
    cout << ENTER_USER_THEN_FANPAGE;
    userName = this->getNameAsString();
    pageName = this->getNameAsString();

    FriendPage* user = getFriendByNameFromSystem(userName, system);
    FanPage* page = getFanPageByNameFromSystem(pageName, system);
    if(user && page)
        system.followFanPage(*user, *page);
    else
        cout << USER_OR_FANPAGE_NOT_FOUND;
}

void UserInterface::unfollowFanPage(BookFace &system)
{
    string userName;
    string pageName;
    cout << ENTER_USER_THEN_FANPAGE;
    userName = this->getNameAsString();
    pageName = this->getNameAsString();

    FriendPage* user = getFriendByNameFromSystem(userName, system);
    FanPage* page = getFanPageByNameFromSystem(pageName, system);
    if(user && page)
        system.unfollowFanPage(*user, *page);
    else
        cout << USER_OR_FANPAGE_NOT_FOUND;
}

void UserInterface::showAllFollowersOfEntity(BookFace &system)
{
    int choice;
    string name;

    this->getChoice(&choice);
    if(!this->validateChoice(choice))
        throw INVALID_CHOICE_MSG;

    name = this->getNameAsString();

    if(choice == 1)
    {
        FriendPage* user = getFriendByNameFromSystem(name, system);
        if(user)
            system.showAllFriendsOfAUser(*user);
        else
            cout << USER_NOT_FOUND;
    }
    else if(choice == 2)
    {
        FanPage* fanPage = getFanPageByNameFromSystem(name, system);
        if(fanPage)
            system.showAllFollowersOfFanPage(*fanPage);
        else
            cout << FANPAGE_NOT_FOUND;
    }
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
    cout << endl << DISPLAY_MENU_MESSAGE << endl;
}

void UserInterface::setOption(UserInterface::eOption newOption)
{
    this->currOption = newOption;
}

void UserInterface::activateOption(BookFace &system)
{
    try {
        switch (this->currOption) {
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
                throw INVALID_CHOICE_MSG;
        }
    }
    catch(char* MSG){
        cout << MSG << endl;
    }
}

void UserInterface::getName(char *name) const
{
    cout << ENTER_NAME;
    cin.getline(name, MAX_NAME_LEN);
}

string UserInterface::getNameAsString() const
{
    string res;

    cout << ENTER_NAME;
    getline(cin, res);

    return res;
}

void UserInterface::getBirthDate(int* day, int* month, int* year) const
{
    cout << ENTER_BIRTH_DATE;
    cin >> *day >> *month >> *year;
}

void UserInterface::getChoice(int* choice) const
{
    cout << CHOOSE_PAGE_OR_FRIEND;
    cin >> *choice;
    cin.get();
}

void UserInterface::getStatusText(char *text) const
{
    cout << ADD_STATUS_TEXT_MSG;
    cin.getline(text, MAX_STATUS_TEXT_LEN);
}

string UserInterface::getStatusTextAsString() const
{
    string text;

    cout << ADD_STATUS_TEXT_MSG;
    getline(cin, text);

    return text;
}

bool UserInterface::validateChoice(int choice) const
{
    if(choice != 1 && choice != 2)
        return false;

    return true;
}
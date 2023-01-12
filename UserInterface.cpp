
#include "UserInterface.h"
#include "ImageStatus.h"
#include "VideoStatus.h"
#include "Exceptions.h"

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

void UserInterface::addStatus(BookFace &system) noexcept(false)
{
    int choice;
    int statusChoice;
    string name;
    string text;
    this->getChoice(&choice);
    if(!this->validateChoice(choice))
        throw INVALID_CHOICE_MSG;

    name = this->getNameAsString();

    this->getStatusChoice(&statusChoice);
    if(!this->validateStatusChoice(statusChoice))
        throw INVALID_CHOICE_MSG;

    text = this->getStatusTextAsString();

    Status* status;
    switch(statusChoice)
    {
        case eStatusType::TEXT_STATUS:
            status = new Status(text);
            break;
        case eStatusType::IMAGE_STATUS:
            status = new ImageStatus(text, getAssetUrl("image"));
            break;
        case eStatusType::VIDEO_STATUS:
            status = new VideoStatus(text, getAssetUrl("video"));
            break;
    };

    try {
        if (choice == 1) {
            FriendPage user(name, dummyDate);
            system.addStatusToPage(user, *status);
        } else if (choice == 2) {
            FanPage page(name);
            system.addStatusToPage(page, *status);
        }
        delete status;
    }
    catch(AddNewStatusBookFaceException& e)
    {
        e.what();
        delete status;
    }
}

void UserInterface::showAllStatusesFromEntity(BookFace &system) const noexcept(false)
{
    int choice;
    string name;

    this->getChoice(&choice);
    if(!this->validateChoice(choice))
        throw INVALID_CHOICE_MSG;

    name = this->getNameAsString();

    if(choice == 1)
    {
        FriendPage user(name, dummyDate);
        system.showAllStatusesFromPage(user);
    }
    else if(choice == 2)
    {
        FanPage page(name);
        system.showAllStatusesFromPage(page);
    }
}

void UserInterface::showAllStatusesFromUsersFriends(BookFace &system) const
{
    string name = this->getNameAsString();
    FriendPage user(name, dummyDate);
    system.showAllStatusesFromUsersFriends(user);
}


void UserInterface::connectUsers(BookFace &system)
{
    string name1 = this->getNameAsString();
    string name2 = this->getNameAsString();
    FriendPage user1(name1, dummyDate);
    FriendPage user2(name2, dummyDate);
    system.connectUsers(user1, user2);
}

void UserInterface::removeUsersConnection(BookFace &system)
{
    string name1 = this->getNameAsString();
    string name2 = this->getNameAsString();
    FriendPage user1(name1, dummyDate);
    FriendPage user2(name2, dummyDate);
    system.removeUsersConnection(user1, user2);
}

void UserInterface::followFanPage(BookFace &system)
{
    string userName;
    string pageName;
    cout << ENTER_USER_THEN_FANPAGE;
    userName = this->getNameAsString();
    pageName = this->getNameAsString();
    FriendPage user(userName, dummyDate);
    FanPage page(pageName);
    system.followFanPage(user, page);
}

void UserInterface::unfollowFanPage(BookFace &system)
{
    string userName;
    string pageName;
    cout << ENTER_USER_THEN_FANPAGE;
    userName = this->getNameAsString();
    pageName = this->getNameAsString();
    FriendPage user(userName, dummyDate);
    FanPage page(pageName);
    system.unfollowFanPage(user, page);
}

void UserInterface::showAllFollowersOfEntity(BookFace &system) noexcept(false)
{
    int choice;
    string name;

    this->getChoice(&choice);
    if(!this->validateChoice(choice))
        throw INVALID_CHOICE_MSG;

    name = this->getNameAsString();

    if(choice == 1)
    {
        FriendPage user(name, dummyDate);
        system.showAllFollowersOfPage(user);
    }
    else if(choice == 2)
    {
        FanPage page(name);
        system.showAllFollowersOfPage(page);
    }
}

void UserInterface::stopTheProgram(BookFace &system)
{
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
    catch(const DateException& e){
        cout << e.what() << endl;
    }
    catch(const StatusException& e){
        cout << e.what() << endl;
    }
    catch(const FriendPageException& e){
        cout << e.what() << endl;
    }
    catch(const FanPageException& e){
        cout << e.what() << endl;
    }
    catch(const BookFaceException& e){
        cout << e.what() << endl;
    }
    catch(const char* msg){
        cout << msg << endl;
    }
    catch(...){
        cout << UNKNOWN_ERROR_MSG << endl;
    }
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

void UserInterface::getStatusChoice(int *statusChoice) const
{
    cout << CHOOSE_STATUS_TYPE;
    cin >> *statusChoice;
    cin.get();
}

string UserInterface::getStatusTextAsString() const
{
    string text;

    cout << ADD_STATUS_TEXT_MSG;
    getline(cin, text);

    return text;
}

string UserInterface::getAssetUrl(string assetName) const
{
    string url;

    cout << "Please enter " << assetName << " url including file suffix: ";
    getline(cin, url);

    return url;
}

bool UserInterface::validateChoice(int choice) const
{
    if(choice != 1 && choice != 2)
        return false;

    return true;
}

bool UserInterface::validateStatusChoice(int statusChoice) const
{
    return (
            statusChoice == eStatusType::IMAGE_STATUS ||
            statusChoice == eStatusType::TEXT_STATUS ||
            statusChoice == eStatusType::VIDEO_STATUS);
}


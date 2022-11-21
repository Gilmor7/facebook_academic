
#include "Bookface.h"

BookFace::BookFace(): menu()
{
    // allocate arrays here
    // set logical & physical sizes here

    this->is_running = true;
}

bool BookFace::addUser()
{
    char name[MAX_NAME_LEN];
    int day, month, year;
    cout << "Enter name: [max 50 characters]";
    cin >> name;
    cout << "Enter birth date (day month year): ";
    cin >> day >> month >> year;
    if(this->isEntityInArr(name, true))
    {
        cout << "User already exists!" << endl;
        return false;
    }
    if(this->usersLogSize == this->usersPhySize)
    {
        reallocArr(true);
    }
    this->usersArr[usersLogSize] = new FriendPage(name, Date(day, month, year));
    this->usersLogSize++;
    return true;
}


void BookFace::showMenu()
{
    this->menu.displayMenu();
}

void BookFace::setOptionInMenu()
{
    this->menu.setChoiceFromUserInput();
}

void BookFace::activateMenuOption()
{
    switch(this->menu.getChoice())
    {
        case Menu::eOption::ADD_USER:
            addUser();
            break;
        case Menu::eOption::ADD_PAGE:
            break;
        case Menu::eOption::ADD_STATUS:
            break;
        case Menu::eOption::SHOW_ENTITY_STATUSES:
            break;
        case Menu::eOption::SHOW_LAST_STATUSES:
            break;
        case Menu::eOption::CONNECT_USERS:
            break;
        case Menu::eOption::REMOVE_USERS_CONNECTION:
            break;
        case Menu::eOption::ADD_USER_TO_PAGE:
            break;
        case Menu::eOption::REMOVE_USER_FROM_PAGE:
            break;
        case Menu::eOption::SHOW_ALL_ENTITIES:
            break;
        case Menu::eOption::SHOW_ALL_FOLLOWERS_OF_ENTITY:
            break;
        case Menu::eOption::EXIT:
            break;
    }

}

void BookFace::reallocArr(bool isUserArr)
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
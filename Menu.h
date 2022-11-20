
#ifndef FACEBOOK_ACADEMIC_MENU_H
#define FACEBOOK_ACADEMIC_MENU_H

#include <iostream>
using namespace std;

class Menu
{
public:
    enum class eOption {ADD_USER, ADD_PAGE, ADD_STATUS, SHOW_ENTITY_STATUSES, SHOW_LAST_STATUSES, CONNECT_USERS
                        ,REMOVE_USERS_CONNECTION, ADD_USER_TO_PAGE, REMOVE_USER_FROM_PAGE, SHOW_ALL_ENTITIES
                        ,SHOW_ALL_FOLLOWERS_OF_ENTITY, EXIT};
private:
    eOption currOption;
public:
    Menu() = default;

    void displayMenu();
    void setChoiceFromUserInput();

    eOption getChoice() {return this->currOption;}


};

#endif //FACEBOOK_ACADEMIC_MENU_H

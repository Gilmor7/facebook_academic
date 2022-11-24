
#ifndef FACEBOOK_ACADEMIC_UTILITIES_H
#define FACEBOOK_ACADEMIC_UTILITIES_H

#include "Bookface.h"
#include <iostream>
using namespace std;

enum eOption {ADD_USER, ADD_PAGE, ADD_STATUS, SHOW_ENTITY_STATUSES, SHOW_LAST_STATUSES, CONNECT_USERS
    ,REMOVE_USERS_CONNECTION, ADD_USER_TO_PAGE, REMOVE_USER_FROM_PAGE, SHOW_ALL_ENTITIES
    ,SHOW_ALL_FOLLOWERS_OF_ENTITY, EXIT};


void displayMenu();
eOption getUserInput();
void activateEOption(eOption option, BookFace& system);


#endif //FACEBOOK_ACADEMIC_UTILITIES_H

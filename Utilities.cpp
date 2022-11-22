
#include "Utilities.h"

const int MAX_NAME_LEN = 51;

const char* DISPLAY_MENU_MESSAGE=
        "1. Add new user to the system\n"
        "2. Add new fanPage to the system.\n"
        "3. Add new status to user/fanPage.\n"
        "4. Show all statuses of user/fanPage.\n"
        "5. Show 10 most recent statuses from specific user's friends.\n"
        "6. Connect 2 users.\n"
        "7. Remove friendship between 2 users\n"
        "8. Add a user to a fanPage.\n"
        "9. Remove a user from a fanPage.\n"
        "10. Show All the registered entities in the system.\n"
        "11. Show all the friends/followers of a user/fanPage.\n"
        "12. Exit the Program.\n";

const char* INVALID_CHOICE_MSG= "Invalid choice, try again!\n";

const char* ADD_USER_NAME_MSG= "Enter a name [max 50 characters]: ";
const char* ADD_USER_DATE_MSG= "\nEnter birthdate [day month year]: ";


void displayMenu()
{
    cout << DISPLAY_MENU_MESSAGE;
}

eOption getUserInput()
{
    int option;
    cout << "Choice an option from above: ";
    cin >> option;
    return (eOption) option;
}

void activateEOption(eOption option, BookFace* systemPtr)
{
    switch (option)
    {
        case ADD_USER:
            char name[MAX_NAME_LEN];
            int day,month,year;
            cout << ADD_USER_NAME_MSG;
            cin >> name;
            cout << ADD_USER_DATE_MSG;
            cin >> day >> month >> year;
            systemPtr->addUser(name, Date(day, month, year));
            break;
        case ADD_PAGE:

            break;
        case ADD_STATUS:
            break;
        case SHOW_ENTITY_STATUSES:
            break;
        case SHOW_LAST_STATUSES:
            break;
        case CONNECT_USERS:
            break;
        case REMOVE_USERS_CONNECTION:
            break;
        case ADD_USER_TO_PAGE:
            break;
        case REMOVE_USER_FROM_PAGE:
            break;
        case SHOW_ALL_ENTITIES:
            break;
        case SHOW_ALL_FOLLOWERS_OF_ENTITY:
            break;
        case EXIT:
            break;
        default:
            cout << INVALID_CHOICE_MSG;
            break;
    }
}


#include "Utilities.h"

const int MAX_NAME_LEN = 51;
const int MAX_STATUS_TEXT_LEN = 101;
const int MAX_USER_CHOICE = 5;

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


const char* ENTER_NAME = "Enter a name [max 50 characters]: ";
const char* ENTER_BIRTH_DATE = "\nEnter birthdate [day month year]: ";

const char* CHOOSE_PAGE_OR_FRIEND = "Choose one [User/Page]: ";

const char* ADD_STATUS_TEXT_MSG= "Enter text for status [max 100 characters]: ";

const char* ENTER_USER_THEN_FANPAGE = "first enter the fanPage name, then the user's name\n";

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

void activateEOption(eOption option, BookFace& system)
{
    /// init helper variables
    char name[MAX_NAME_LEN];
    char name2[MAX_NAME_LEN];
    char text[MAX_STATUS_TEXT_LEN];
    char choice[MAX_USER_CHOICE];
    Status* status = nullptr;

    switch (option)
    {
        case ADD_USER:
            int day,month,year;
            cout << ENTER_NAME;
            cin >> name;
            cout << ENTER_BIRTH_DATE;
            cin >> day >> month >> year;
            system.addUser(name, Date(day, month, year));
            break;

        case ADD_PAGE:
            cout << ENTER_NAME;
            cin >> name;
            system.addPage(name);
            break;

        case ADD_STATUS:
            cout << ADD_STATUS_TEXT_MSG;
            cin >> text;
            status = new Status(text);

            cout << CHOOSE_PAGE_OR_FRIEND;
            cin >> choice;

            cout << ENTER_NAME;
            cin >> name;

            if(strcmp(choice, "User") == 0)
                system.addStatusToFriendPage(name, *status);
            else
                system.addStatusToFanPage(name, *status);

            break;

        case SHOW_ENTITY_STATUSES:
            cout << CHOOSE_PAGE_OR_FRIEND;
            cin >> choice;

            cout << ENTER_NAME;
            cin >> name;
            if(strcmp(choice, "User") == 0)
                system.showAllStatusesFromFriend(name);
            else
                system.showAllStatusesFromFanPage(name);

            break;

        case SHOW_LAST_STATUSES:
            cout << ENTER_NAME;
            cin >> name;
            system.showAllStatusesFromFriend(name);
            break;

        case CONNECT_USERS:
            cout << ENTER_NAME;
            cin >> name;
            cout << endl;
            cout << ENTER_NAME;
            cin >> name2;
            system.connectUsers(name, name2);
            break;

        case REMOVE_USERS_CONNECTION:
            cout << ENTER_NAME;
            cin >> name;
            cout << endl;
            cout << ENTER_NAME;
            cin >> name2;
            system.removeUsersConnection(name, name2);
            break;

        case ADD_USER_TO_PAGE:
            cout << ENTER_USER_THEN_FANPAGE;
            cout << ENTER_NAME;
            cin >> name;
            cout << endl;
            cout << ENTER_NAME;
            cin >> name2;
            system.followFanPage(name, name2);
            break;

        case REMOVE_USER_FROM_PAGE:
            cout << ENTER_USER_THEN_FANPAGE;
            cout << ENTER_NAME;
            cin >> name;
            cout << endl;
            cout << ENTER_NAME;
            cin >> name2;
            system.unfollowFanPage(name, name2);
            break;
        case SHOW_ALL_ENTITIES:
            system.showAllRegistered();
            break;
        case SHOW_ALL_FOLLOWERS_OF_ENTITY:
            cout << CHOOSE_PAGE_OR_FRIEND;
            cin >> choice;
            cout << endl;
            cout << ENTER_NAME;
            cin >> name;
            if(strcpy(choice, "User") == 0)
                system.showAllFriendsOfAUser(name);
            else
                system.showAllFollowersOfFanPage(name);
            break;
        case EXIT:
            system.stopTheProgram();
            break;
        default:
            cout << INVALID_CHOICE_MSG;
            break;
    }
}

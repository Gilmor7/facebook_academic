
#ifndef FACEBOOK_ACADEMIC_USERINTERFACE_H
#define FACEBOOK_ACADEMIC_USERINTERFACE_H

#include "Bookface.h"

// consts
const int MAX_NAME_LEN = 51;
const int MAX_STATUS_TEXT_LEN = 101;
const int MAX_USER_CHOICE = 5;


// msg consts
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
const char* ADD_STATUS_TEXT_MSG= "Enter text for status [max 200 characters]: ";
const char* ENTER_USER_THEN_FANPAGE = "first enter the fanPage name, then the user's name\n";



class UserInterface
{
public:

    enum class eOption {ADD_USER, ADD_PAGE, ADD_STATUS, SHOW_ENTITY_STATUSES, SHOW_LAST_STATUSES, CONNECT_USERS
        ,REMOVE_USERS_CONNECTION, ADD_USER_TO_PAGE, REMOVE_USER_FROM_PAGE, SHOW_ALL_ENTITIES
        ,SHOW_ALL_FOLLOWERS_OF_ENTITY, EXIT};


private:
    BookFace system;
    eOption currOption;

    // system functions - (should not be accessed from outside the class)
    void addUser();
    void addPage();
    void showAllRegistered() const;
    void addStatusToFriendPage();
    void addStatusToFanPage();
    void showAllStatusesFromFriend() const;
    void showAllStatusesFromFanPage() const;
    void showAllStatusesFromUsersFriends() const;
    void connectUsers();
    void removeUsersConnection();
    void followFanPage();
    void unfollowFanPage();
    void showAllFriendsOfAUser() const;
    void showAllFollowersOfFanPage() const;
    void stopTheProgram();

public:
    // c'tors and d'tor
    UserInterface() = default;
    UserInterface(const UserInterface& other) = delete;
    UserInterface(UserInterface&& other) = delete;
    ~UserInterface();

    // interaction functions
    void displayMenu() const;
    void setOption(eOption newOption);
    void activateOption();

};

#endif //FACEBOOK_ACADEMIC_USERINTERFACE_H


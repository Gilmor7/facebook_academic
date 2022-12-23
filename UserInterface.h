
#ifndef FACEBOOK_ACADEMIC_USERINTERFACE_H
#define FACEBOOK_ACADEMIC_USERINTERFACE_H

#include "Utilities.h"

class UserInterface
{
public:

    enum eOption {ADD_USER = 1, ADD_PAGE, ADD_STATUS, SHOW_ENTITY_STATUSES, SHOW_LAST_STATUSES, CONNECT_USERS
        ,REMOVE_USERS_CONNECTION, ADD_USER_TO_PAGE, REMOVE_USER_FROM_PAGE, SHOW_ALL_ENTITIES
        ,SHOW_ALL_FOLLOWERS_OF_ENTITY, EXIT};

    // consts
    constexpr static int MAX_NAME_LEN = 51;
    constexpr static int MAX_STATUS_TEXT_LEN = 101;
    static Date dummyDate;

    // msg consts
    constexpr static const char* const DISPLAY_MENU_MESSAGE=
            "Choose an Option: [from 1 to 12]\n"
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
            "12. Exit the Program.\n"
            "Enter your Option: ";
    constexpr static const char* const INVALID_CHOICE_MSG= "Error! Invalid choice!";
    constexpr static const char* const ENTER_NAME = "Enter a name [max 50 characters]: ";
    constexpr static const char* const ENTER_BIRTH_DATE = "\nEnter birthdate [day month year]: ";
    constexpr static const char* const CHOOSE_PAGE_OR_FRIEND =
            "Choose one [pick 1 or 2]:\n"
            "1. user\n"
            "2. fanPage\n";
    constexpr static const char* const ADD_STATUS_TEXT_MSG= "Enter text for status [max 200 characters]: ";
    constexpr static const char* const ENTER_USER_THEN_FANPAGE = "First enter the user name, then the fan page name!\n";
    constexpr static const char* const UNKNOWN_ERROR_MSG = "Unknown error occurred!\n";

private:

    eOption currOption;

    // system functions - (should not be accessed from outside the class)
    void addUser(BookFace& system);
    void addPage(BookFace& system);
    void showAllRegistered(BookFace& system) const;
    void addStatus(BookFace& system) noexcept(false);
    void showAllStatusesFromEntity(BookFace& system) const noexcept(false);
    void showAllStatusesFromUsersFriends(BookFace& system) const;
    void connectUsers(BookFace& system);
    void removeUsersConnection(BookFace& system);
    void followFanPage(BookFace& system);
    void unfollowFanPage(BookFace& system);
    void showAllFollowersOfEntity(BookFace& system) noexcept(false);
    void stopTheProgram(BookFace& system);

    // small Utility functions
    void getName(char* name) const;
    string getNameAsString() const;
    void getBirthDate(int* day, int* month, int* year) const;
    void getChoice(int* choice) const;
    void getStatusText(char* text) const;
    string getStatusTextAsString() const;
    bool validateChoice(int choice) const;

public:
    // c'tors and d'tor
    UserInterface() = default;
    UserInterface(const UserInterface& other) = delete;
    UserInterface(UserInterface&& other) = delete;


    // interaction functions
    void displayMenu() const;
    void setOption(eOption newOption);
    void activateOption(BookFace& system);

};

#endif //FACEBOOK_ACADEMIC_USERINTERFACE_H


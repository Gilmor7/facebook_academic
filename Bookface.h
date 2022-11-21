
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H

#include "Menu.h"
#include "friend_page.h"
#include "page.h"

const int MAX_NAME_LEN = 50;

class BookFace
{
private:
    FriendPage** usersArr;
    FanPage** fanPagesArr;
    int usersLogSize, usersPhySize, fanPageLogSize, fanPagePhySize;
    Menu menu;
    bool is_running;

    // menu functions (can be called only from activateMenuOption()
    bool addUser();
    bool addPage();
    void showAllRegistered() const;
    bool connectUsers(const char* name1, const char* name2);
    bool removeUsersConnection(const char* name1, const char* name2);
    bool followFanPage(const char* userName, const char* fanPage);
    bool unfollowFanPage(const char* userName, const char* fanPage);
    bool showAllFromPage(const char* pageName);
public:
    BookFace();   // initialize some users and pages here  (in the future, load from files)

    // copy and move, maybe not needed?
    BookFace(const BookFace& other);
    BookFace(BookFace&& other);

    ~BookFace();  // (in the future, save to file)

    // created these functions to call manu methods inside BookFace, instead of returning menu (as copy)
    // and then calling the methods
    void showMenu();
    void setOptionInMenu();

    // this function will user the menu.choice and activate the private method
    void activateMenuOption();

    bool isEntityInArr(const char* nameOfEntity, bool isUser);
    bool getRunningState() const {return this->is_running;}
    void reallocArr(bool isUserArr);
};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

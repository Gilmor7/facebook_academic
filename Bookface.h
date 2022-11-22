
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "friend_page.h"
#include "page.h"
#include <iostream>
using namespace std;

class BookFace
{
private:
    FriendPage** usersArr;
    FanPage** fanPagesArr;
    int usersLogSize, usersPhySize, fanPageLogSize, fanPagePhySize;
    bool is_running;


public:

    BookFace();   // initialize some users and pages here  (in the future, load from files)

    // copy and move, maybe not needed?
    BookFace(const BookFace& other);
    BookFace(BookFace&& other);
    ~BookFace();

    // main program methods
    bool addUser(const char* name, Date date);
    bool addPage(const char* name);
    void showAllRegistered() const;
    bool connectUsers(const char* name1, const char* name2);
    bool removeUsersConnection(const char* name1, const char* name2);
    bool followFanPage(const char* userName, const char* fanPage);
    bool unfollowFanPage(const char* userName, const char* fanPage);
    bool showAllFromPage(const char* pageName);

    // helper methods
    bool isEntityInArr(const char* nameOfEntity, bool isUser);
    bool getRunningState() const {return this->is_running;}
    void doubleArrSize(bool isUserArr);
};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

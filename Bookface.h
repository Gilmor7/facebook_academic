
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "FriendPage.h"
#include "FanPage.h"
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

    BookFace();

    BookFace(const BookFace& other) = delete;
    BookFace(BookFace&& other) = delete;
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
};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

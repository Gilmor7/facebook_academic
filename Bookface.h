
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "FriendPage.h"
#include "FanPage.h"
#include <iostream>
using namespace std;

class BookFace
{
private:
     FriendArray users;
     // FanPageArr
     bool is_running;


public:

    BookFace();

    BookFace(const BookFace& other) = delete;
    BookFace(BookFace&& other) = delete;
    ~BookFace();

    // main program methods
    void addUser(const char* name, Date date);
    void addPage(const char* name);
    void showAllRegistered() const;
    void addStatusToFriendPage(const char* pageName, Status& status);
    void addStatusToFanPage(const char* pageName, Status& status);
    void showAllStatusesFromFriend(const char* pageName) const;
    void showAllStatusesFromFanPage(const char* pageName) const;
    void showAllStatusesFromUsersFriends(const char* pageName) const;
    void connectUsers(const char* name1, const char* name2);
    void removeUsersConnection(const char* name1, const char* name2);
    void followFanPage(const char* userName, const char* fanPage);
    void unfollowFanPage(const char* userName, const char* fanPage);
    void showAllFriendsOfAUser(const char* userName);
    void showAllFollowersOfFanPage(const char* FanPage);
    void stopTheProgram();

    // helper methods
    bool isUserInArr() const;
    bool isFanPageInArr() const;

};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

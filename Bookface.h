
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
     FanPageArray fanPages;
     bool is_running;

public:

    BookFace();

    BookFace(const BookFace& other) = delete;
    BookFace(BookFace&& other) = delete;
    ~BookFace();

    // main program methods
    /// TODO: change parameters to references
    /// TODO: implement addUser,AddPage, showALL....
    void addUser(FriendPage& newUser);
    void addPage(FanPage& newFanPage);
    void showAllRegistered() const;
    void addStatusToFriendPage(FriendPage& user, Status& status);
    void addStatusToFanPage(FanPage& fanPage, Status& status);
    void showAllStatusesFromFriend(FriendPage& user) const;
    void showAllStatusesFromFanPage(FanPage& fanPage) const;
    void showAllStatusesFromUsersFriends(FriendPage& user) const;
    void connectUsers(FriendPage& user1, FriendPage& user2);
    void removeUsersConnection(FriendPage& user1, FriendPage& user2);
    void followFanPage(FriendPage& user, FanPage& fanPage);
    void unfollowFanPage(FriendPage& user, FanPage& fanPage);
    void showAllFriendsOfAUser(FriendPage& user) const;
    void showAllFollowersOfFanPage(FanPage& fanPage) const;
    void stopTheProgram() {this->is_running = false;}

    // helper methods
    bool isUserInArr() const;
    bool isFanPageInArr() const;

};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

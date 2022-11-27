
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "FriendPage.h"
#include "FanPage.h"
#include <iostream>
using namespace std;

const int NUM_OF_FRIENDS_STATUSESS = 10;

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

    /// TODO: change the needed function to return bool to handle user/page deletion from the outside
    /// (for example: a new user is malloced from outside, but the name already exists in users. so return false to the outside
    /// and delete the new user. (the user inside the users will be freed in the D'tor)
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

    bool getRunningState() const {return this->is_running;}
    void deleteUsers();
    void deleteFanPages();

};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

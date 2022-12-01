
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "FriendPage.h"
#include "FanPage.h"
#include <iostream>
using namespace std;

class BookFace
{
public:
    static constexpr int NUM_OF_FRIENDS_STATUSESS = 10;
    static constexpr const char* const USER_ALREADY_EXISTS = "User already exists in the system\n";
    static constexpr const char* const PAGE_ALREADY_EXISTS = "Page already exists\n";
    static constexpr const char* const USER_NOT_EXISTS = "User doesn't exist\n";
    static constexpr const char* const PAGE_NOT_EXISTS = "Page doesn't exist\n";
    static constexpr const char* const USERS_ALREADY_CONNECTED = "Users are already connected\n";
    static constexpr const char* const ONE_OF_USERS_NOT_FOUND = "One of the users doesn't exists\n";
    static constexpr const char* const USERS_NOT_CONNECTED = "Users are not connects\n";

private:
    FriendArray users;
    FanPageArray fanPages;
    bool is_running;


public:
    BookFace();
    BookFace(const BookFace& other) = delete;
    BookFace(BookFace&& other) = delete;

    // main system methods
    bool addUser(FriendPage& newUser);
    bool addPage(FanPage& newFanPage);
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

    // getters
    FriendArray* getFriendArrayPtr() {return &this->users;}
    FanPageArray* getFanPagesArrayPtr() {return &this->fanPages;}
    bool getRunningState() const {return this->is_running;}

    // deletion functions
    void deleteUsers();
    void deleteFanPages();
};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H
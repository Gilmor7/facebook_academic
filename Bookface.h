
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "FriendPage.h"
#include "FanPage.h"
#include <list>
#include <iostream>
using namespace std;

class BookFace
{
public:
    static constexpr int NUM_OF_FRIENDS_STATUSESS = 10;
    static constexpr int NOT_FOUND = -1;
    static constexpr const char* const USER_ALREADY_EXISTS_EXCEPTION = "User already exists in the system";
    static constexpr const char* const PAGE_ALREADY_EXISTS_EXCEPTION = "Page already exists";
    static constexpr const char* const USER_NOT_EXISTS_EXCEPTION = "User doesn't exist";
    static constexpr const char* const PAGE_NOT_EXISTS_EXCEPTION = "One Of The Pages entered doesn't exist";
    static constexpr const char* const USERS_ALREADY_CONNECTED_EXCEPTION = "Users are already connected";
    static constexpr const char* const ONE_OF_USERS_NOT_FOUND_EXCEPTION = "One of the users doesn't exists";
    static constexpr const char* const USERS_NOT_CONNECTED_EXCEPTION = "Users are not connects";
    static constexpr const char* const USER_TO_SELF_EXCEPTION = "Can't apply on Self!";

private:
    list<FriendPage> users;
    list<FanPage> fanPages;
    bool is_running;


public:
    BookFace();
    BookFace(const BookFace& other) = delete;
    BookFace(BookFace&& other) = delete;

    // main system methods
    void addUser(FriendPage& newUser) noexcept(false);
    void addPage(FanPage& newFanPage) noexcept(false);
    void showAllRegistered() const;
    void addStatusToFriendPage(FriendPage& user, Status& status) noexcept(false);
    void addStatusToFanPage(FanPage& fanPage, Status& status) noexcept(false);
    void showAllStatusesFromFriend(FriendPage& user) const noexcept(false);
    void showAllStatusesFromFanPage(FanPage& fanPage) const noexcept(false);
    void showAllStatusesFromUsersFriends(FriendPage& user) const noexcept(false);
    void connectUsers(FriendPage& user1, FriendPage& user2) noexcept(false);
    void removeUsersConnection(FriendPage& user1, FriendPage& user2) noexcept(false);
    void followFanPage(FriendPage& user, FanPage& fanPage) noexcept(false);
    void unfollowFanPage(FriendPage& user, FanPage& fanPage) noexcept(false);
    void showAllFriendsOfAUser(FriendPage& user) const noexcept(false);
    void showAllFollowersOfFanPage(FanPage& fanPage) const noexcept(false);
    void stopTheProgram() {this->is_running = false;}

    // getters
    bool getRunningState() const {return this->is_running;}
    FriendPage* getUserByName(const string& name);
    FanPage* getFanPageByName(const string& name);

};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H
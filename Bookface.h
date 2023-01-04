
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H
#include "FriendPage.h"
#include "FanPage.h"
#include "Exceptions.h"
#include <list>
#include <iostream>
using namespace std;

class BookFace
{
public:
    static constexpr int NUM_OF_FRIENDS_STATUSESS = 10;

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
    void showAllFollowersOfPage(const Page& page) const noexcept(false);
    void stopTheProgram() {this->is_running = false;}

    // getters
    bool getRunningState() const {return this->is_running;}

};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H
#ifndef FACEBOOK_ACADEMIC_EXCEPTIONS_H
#define FACEBOOK_ACADEMIC_EXCEPTIONS_H

#include <iostream>
#include <string>
using namespace std;

// Date and Status
class DateException: public std::exception
{
public:
    virtual const char* what() const noexcept override{return "Date Error - Invalid date was given!";}
};

class StatusException: public std::exception
{
public:
    virtual const char* what() const noexcept override{return "Status Error - Invalid Status was given!";}
};

// Friend Page
class FriendPageException: public std::exception
{
public:
    virtual const char* what() const noexcept override {return "User Error!";}
};

class CreateUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to create new user!";}
};

class AddFriendToUserUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to add new friend to a user!";}
};

class RemoveFriendFromUserUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to remove friendship between users!";}
};

class FollowNewFanPageUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to follow a new fan page!";}
};

class UnfollowFanPageUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to unfollow a fan page!";}
};

// FanPage
class FanPageException: public std::exception
{
public:
    virtual const char* what() const noexcept override {return "Fan page Error!";}
};

class CreateNewPageFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to create a new fan page!";}
};

class AddNewFollowerFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to add a new follower!";}
};

class RemoveFollowerFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while trying to remove a follower!";}
};

// BookFace
class BookFaceException: public std::exception
{
public:
    virtual const char* what() const noexcept override {return "BookFace system Error!";}
};

class AddNewUserBookFaceException: public BookFaceException
{
public:
    virtual const char* what() const noexcept override {return "Error while try adding new user!";}
};

class AddNewPageBookFaceException: public BookFaceException
{
public:
    virtual const char* what() const noexcept override {return "Error while try adding new fan page!";}
};

class AddNewStatusBookFaceException: public BookFaceException
{
public:
    virtual const char* what() const noexcept override {return "Error while try adding new status!";}
};

class UserNotFoundBookFaceException: public BookFaceException
{
public:
    virtual const char* what() const noexcept override {return "User not found!";}
};

class PageNotFoundBookFaceException: public BookFaceException
{
public:
    virtual const char* what() const noexcept override {return "Page not found!";}
};

class ApplyToSelfBookFaceException: public BookFaceException
{
public:
    virtual const char* what() const noexcept override {return "You can't apply to yourself!";}
};

#endif //FACEBOOK_ACADEMIC_EXCEPTIONS_H

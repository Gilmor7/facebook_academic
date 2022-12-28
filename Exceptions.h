#ifndef FACEBOOK_ACADEMIC_EXCEPTIONS_H
#define FACEBOOK_ACADEMIC_EXCEPTIONS_H

#include <iostream>
#include <string>
using namespace std;

class DateException: public std::exception
{
public:
    virtual const char* what() const noexcept override{return "Date Error!";}
};

class StatusException: public std::exception
{
public:
    virtual const char* what() const noexcept override{return "Status Error!";}
};

class FriendPageException: public std::exception
{
public:
    virtual const char* what() const noexcept override {return "User Error!";}
};

class CreateUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while creating new user!";}
};

class AddNewUserUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while adding new user!";}
};

class AddFriendToUserUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while adding new friend to user!";}
};

class RemoveFriendFromUserUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while removing friend from user!";}
};

class FollowNewFanPageUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while following new fan page!";}
};

class UnfollowFanPageUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while unfollowing fan page!";}
};

class AddNewStatusUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while adding new status to user!";}
};

class FindUserUserException: public FriendPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while finding user!";}
};

class FanPageException: public std::exception
{
public:
    virtual const char* what() const noexcept override {return "Fan page Error!";}
};

class CreateNewPageFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while creating new fan page!";}
};

class AddNewFollowerFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while adding new follower!";}
};

class RemoveFollowerFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while removing follower!";}
};

class AddNewStatusFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while adding new status to fan page!";}
};

class FindPageFanPageException: public FanPageException
{
public:
    virtual const char* what() const noexcept override {return "Error while finding fan page!";}
};


#endif //FACEBOOK_ACADEMIC_EXCEPTIONS_H

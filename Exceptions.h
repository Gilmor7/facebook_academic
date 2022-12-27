#ifndef FACEBOOK_ACADEMIC_EXCEPTIONS_H
#define FACEBOOK_ACADEMIC_EXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

class Exception {
protected:
    string msg;

public:
    Exception(const string &msg) : msg(msg) {}
    const string& what() const { return msg; }
};

class DateException: public Exception
{
public:
    static constexpr const char* const DEFAULT_MESSAGE = "Invalid date was given";
public:
    DateException(const string &msg = DEFAULT_MESSAGE) : Exception(msg) {}
    const string what() const { return "Error while getting birth date: " + Exception::what(); }
};

class StatusException: public Exception
{
public:
    StatusException(const string& msg): Exception(msg) {};
    const string what() const { return "Error while getting new status: " + Exception::what(); }
};

class FriendPageException: public Exception
{
public:
    enum class actions {
        CREATE_NEW_USER, ADD_NEW_USER, ADD_FRIEND, REMOVE_FRIEND, FOLLOW_NEW_FAN_PAGE, UNFOLLOW_FAN_PAGE, ADD_NEW_STATUS, FIND_USER
    };
    const string actionStr[8] = {
            "create new user", "add new user", "follow new friend", "unfollow a friend",
            "follow new fan page", "unfollow a fan page", "add new status", "find user"
    };

private:
    actions actionType;

public:
    FriendPageException(const string& msg, actions actionType): Exception(msg),actionType(actionType) {};
    const string what() const { return "Friend Page error: Unable to " + actionStr[(int)actionType] + " - " + Exception::what(); }
};


class FanPageException: public Exception
{
public:
    enum class actions {
        CREATE_NEW_PAGE, ADD_FOLLOWER, REMOVE_FOLLOWER, ADD_NEW_STATUS, FIND_PAGE
    };
    const string actionStr[8] = {
            "create new page", "add new follower", "remove a follower",
            "add new status", "find page"
    };

private:
    actions actionType;
public:
    FanPageException(const string& msg, actions actionType): Exception(msg),actionType(actionType) {};
    const string what() const { return "Fan Page error: Unable to " + actionStr[(int)actionType] + " - " + Exception::what(); }
};


#endif //FACEBOOK_ACADEMIC_EXCEPTIONS_H


#include "Bookface.h"

/// C'tor
BookFace::BookFace()
{
    this->is_running = true;
}

/// Menu functions
bool BookFace::addUser(FriendPage &newUser)
{
    const bool isExists = this->users.isFriendInArr(newUser);
    if (isExists)
    {
        cout << USER_ALREADY_EXISTS;
        return false;
    }
    else
    {
        this->users.push(&newUser);
        return true;
    }

}

bool BookFace::addPage(FanPage &newFanPage)
{
    const bool isExists = this->fanPages.isFanPageInArr(newFanPage);
    if(isExists)
    {
        cout << PAGE_ALREADY_EXISTS;
        return false;
    }
    else
    {
        this->fanPages.push(&newFanPage);
        return true;
    }
}

void BookFace::showAllRegistered() const
{
    cout << "Users: " << endl;
    this->users.show();
    cout << "Pages: " << endl;
    this->fanPages.show();
}

void BookFace::addStatusToFriendPage(FriendPage &user, Status& status)
{
    const bool isExists = this->users.isFriendInArr(user);
    if(isExists)
        user.addStatus(status);
    else
        cout << USER_NOT_EXISTS;
}

void BookFace::addStatusToFanPage(FanPage &fanPage, Status& status)
{
    const bool isExists = this->fanPages.isFanPageInArr(fanPage);
    if(isExists)
        fanPage.addStatus(status);
    else
        cout << PAGE_NOT_EXISTS;
}

void BookFace::showAllStatusesFromFriend(FriendPage &user) const
{
    const bool isExists = this->users.isFriendInArr(user);
    if(isExists)
        user.showStatuses();
    else
        cout << USER_NOT_EXISTS;
}

void BookFace::showAllStatusesFromFanPage(FanPage &fanPage) const
{
    const bool isExists = this->fanPages.isFanPageInArr(fanPage);
    if(isExists)
        fanPage.showStatuses();
    else
        cout << PAGE_NOT_EXISTS;
}

void BookFace::showAllStatusesFromUsersFriends(FriendPage &user) const
{
    const bool isExists = this->users.isFriendInArr(user);
    if(isExists)
        user.showFriendsStatuses(NUM_OF_FRIENDS_STATUSESS);
    else
        cout << USER_NOT_EXISTS;
}

void BookFace::connectUsers(FriendPage &user1, FriendPage &user2)
{
    const bool user1Exists = this->users.isFriendInArr(user1);
    const bool user2Exists = this->users.isFriendInArr(user2);

    int indexOfFriend2 = FriendPage::findFriendIndex(user2, user1.getFriendsArray());
    if(user1Exists && user2Exists)
    {
        if(indexOfFriend2 == NOT_FOUND)    // means they are not connected
        {
            user1.addFriend(user2);
            user2.addFriend(user1);
        }
        else
        {
            cout << USERS_ALREADY_CONNECTED;
        }
    }
    else
        cout << ONE_OF_USERS_NOT_FOUND;
}

void BookFace::removeUsersConnection(FriendPage &user1, FriendPage &user2)
{
    const bool user1Exists = this->users.isFriendInArr(user1);
    const bool user2Exists = this->users.isFriendInArr(user2);

    int indexOfFriend2 = FriendPage::findFriendIndex(user2, user1.getFriendsArray());
    if(user1Exists && user2Exists)
    {
        if (indexOfFriend2 != NOT_FOUND)     // means they are friends
        {
            user1.removeFriend(user2);
            user2.removeFriend(user1);
        }
        else
        {
            cout << USERS_NOT_CONNECTED;
        }
    }
    else
        cout << ONE_OF_USERS_NOT_FOUND;
}

void BookFace::followFanPage(FriendPage &user, FanPage &fanPage)
{
    const bool userExists = this->users.isFriendInArr(user);
    const bool fanPageExists = this->fanPages.isFanPageInArr(fanPage);
    if(userExists && fanPageExists)
    {
        if(user.followFanPage(fanPage))
            fanPage.addFollower(user);
    }
    else if (!userExists)
        cout << USER_NOT_EXISTS;
    else
        cout << PAGE_NOT_EXISTS;
}

void BookFace::unfollowFanPage(FriendPage &user, FanPage &fanPage)
{
    const bool userExists = this->users.isFriendInArr(user);
    const bool fanPageExists = this->fanPages.isFanPageInArr(fanPage);
    if(userExists && fanPageExists)
    {
        if(user.unfollowFanPage(fanPage))
            fanPage.removeFollower(user);
    }
    else if (!userExists)
        cout << USER_NOT_EXISTS;
    else
        cout << PAGE_NOT_EXISTS;
}

void BookFace::showAllFriendsOfAUser(FriendPage &user) const
{
    const bool isExists = this->users.isFriendInArr(user);
    if(isExists)
    {
        user.showFriends();
    }
    else
        cout << USER_NOT_EXISTS;
}

void BookFace::showAllFollowersOfFanPage(FanPage &fanPage) const
{
    const bool isExists = this->fanPages.isFanPageInArr(fanPage);
    if(isExists)
    {
        fanPage.showFollowers();
    }
    else
        cout << PAGE_NOT_EXISTS;
}

void BookFace::deleteUsers()
{
    this->users.deleteAllUsers();
}

void BookFace::deleteFanPages()
{
    this->fanPages.deleteAllPages();
}



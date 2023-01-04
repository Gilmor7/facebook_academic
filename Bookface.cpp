
#include "Bookface.h"

/// C'tor
BookFace::BookFace()
{
    this->is_running = true;
}

/// Menu functions
void BookFace::addUser(FriendPage &newUser) noexcept(false)
{
    auto findItr = std::find(this->users.begin(), this->users.end(), newUser);
    if(findItr == this->users.end())
        this->users.push_back(newUser);
    else
        throw AddNewUserBookFaceException();

}

void BookFace::addPage(FanPage &newFanPage) noexcept(false)
{
    auto findItr = std::find(this->fanPages.begin(), this->fanPages.end(), newFanPage);
    if(findItr == this->fanPages.end())
        this->fanPages.push_back(newFanPage);
    else
        throw AddNewPageBookFaceException();
}

void BookFace::showAllRegistered() const
{
    cout << "Users: " << endl;
    auto userItr = this->users.begin();
    for(; userItr != this->users.end(); ++userItr)
        userItr->show();
    cout << "Pages: " << endl;
    auto pageItr = this->fanPages.begin();
    for(; pageItr != this->fanPages.end(); ++pageItr)
        pageItr->showName();
}

void BookFace::addStatusToFriendPage(FriendPage &user, Status& status) noexcept(false)
{
   auto itr = std::find(this->users.begin(), this->users.end(), user);
   if(itr != this->users.end())
         itr->addStatus(status);
   else
       throw AddNewStatusBookFaceException();
}

void BookFace::addStatusToFanPage(FanPage &fanPage, Status& status) noexcept(false)
{
    auto itr = std::find(this->fanPages.begin(), this->fanPages.end(), fanPage);
    if(itr != this->fanPages.end())
        itr->addStatus(status);
    else
        throw AddNewStatusBookFaceException();
}

void BookFace::showAllStatusesFromFriend(FriendPage &user) const noexcept(false)
{
    auto itr = std::find(this->users.begin(), this->users.end(), user);
    if(itr != this->users.end())
        itr->showStatuses();
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::showAllStatusesFromFanPage(FanPage &fanPage) const noexcept(false)
{
    auto itr = std::find(this->fanPages.begin(), this->fanPages.end(), fanPage);
    if(itr != this->fanPages.end())
        itr->showStatuses();
    else
        throw PageNotFoundBookFaceException();
}

void BookFace::showAllStatusesFromUsersFriends(FriendPage &user) const noexcept(false)
{
    auto itr = std::find(this->users.begin(), this->users.end(), user);
    if(itr != this->users.end())
        itr->showFriendsStatuses(NUM_OF_FRIENDS_STATUSESS);
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::connectUsers(FriendPage &user1, FriendPage &user2) noexcept(false)
{
    if (user1 == user2)
        throw ApplyToSelfBookFaceException();
    auto itr1 = std::find(this->users.begin(), this->users.end(), user1);
    auto itr2 = std::find(this->users.begin(), this->users.end(), user2);
    if(itr1 != this->users.end() && itr2 != this->users.end())
    {
        *itr1 += *itr2;
        *itr2 += *itr1;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::removeUsersConnection(FriendPage &user1, FriendPage &user2)
{
    if(user1 == user2)
        throw ApplyToSelfBookFaceException();
    auto itr1 = std::find(this->users.begin(), this->users.end(), user1);
    auto itr2 = std::find(this->users.begin(), this->users.end(), user2);
    if(itr1 != this->users.end() && itr2 != this->users.end())
    {
        itr1->removeFriend(*itr2);
        itr2->removeFriend(*itr1);
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::followFanPage(FriendPage &user, FanPage &fanPage)
{
    auto itr1 = std::find(this->users.begin(), this->users.end(), user);
    auto itr2 = std::find(this->fanPages.begin(), this->fanPages.end(), fanPage);
    if(itr1 != this->users.end() && itr2 != this->fanPages.end())
    {
        *itr1 += (*itr2);
        *itr2 += (*itr1);
    }
    else if(itr1 == this->users.end())
        throw UserNotFoundBookFaceException();
    else
        throw PageNotFoundBookFaceException();
}

void BookFace::unfollowFanPage(FriendPage &user, FanPage &fanPage)
{
    auto itr1 = std::find(this->users.begin(), this->users.end(), user);
    auto itr2 = std::find(this->fanPages.begin(), this->fanPages.end(), fanPage);
    if(itr1 != this->users.end() && itr2 != this->fanPages.end())
    {
        *itr1 -= (*itr2);
        *itr2 -= (*itr1);
    }
    else if(itr1 == this->users.end())
        throw UserNotFoundBookFaceException();
    else
        throw PageNotFoundBookFaceException();
}

void BookFace::showAllFriendsOfAUser(FriendPage &user) const
{
    auto itr = std::find(this->users.begin(), this->users.end(), user);
    if(itr != this->users.end())
        itr->showFollowers();
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::showAllFollowersOfFanPage(FanPage &fanPage) const
{
    auto itr = std::find(this->fanPages.begin(), this->fanPages.end(), fanPage);
    if(itr != this->fanPages.end())
        itr->showFollowers();
    else
        throw PageNotFoundBookFaceException();
}



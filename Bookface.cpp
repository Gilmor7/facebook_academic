
#include "Bookface.h"

/// C'tor
BookFace::BookFace()
{
    this->is_running = true;
}

/// Menu functions
void BookFace::addUser(FriendPage &newUser) noexcept(false)
{
    if(this->users.find(newUser.getName()) != this->users.end())
        throw AddNewUserBookFaceException();
    this->users.insert(make_pair(newUser.getName(), newUser));
}

void BookFace::addPage(FanPage &newFanPage) noexcept(false)
{
    if(this->fanPages.find(newFanPage.getName()) != this->fanPages.end())
        throw AddNewPageBookFaceException();
    this->fanPages.insert(make_pair(newFanPage.getName(), newFanPage));
}

void BookFace::showAllRegistered() const
{
    cout << "Users: " << endl;
    auto userItr = this->users.begin();
    for(; userItr != this->users.end(); ++userItr)
        userItr->second.show();
    cout << "Pages: " << endl;
    auto pageItr = this->fanPages.begin();
    for(; pageItr != this->fanPages.end(); ++pageItr)
        pageItr->second.show();
}

void BookFace::addStatusToPage(const Page &page, const Status& status) noexcept(false)
{
    const FriendPage* temp1 = dynamic_cast<const FriendPage*>(&page);
    const FanPage* temp2 = dynamic_cast<const FanPage*>(&page);
    if(temp1)
    {
        auto itr = this->users.find(temp1->getName());
        if(itr == this->users.end())
            throw AddNewStatusBookFaceException();
        itr->second.addStatus(status);
    }
    else
    {
        auto itr = this->fanPages.find(temp2->getName());
        if(itr == this->fanPages.end())
            throw AddNewStatusBookFaceException();
        itr->second.addStatus(status);
    }
}

void BookFace::showAllStatusesFromUsersFriends(FriendPage &user) const noexcept(false)
{
    auto itr = this->users.find(user.getName());
    if(itr == this->users.end())
        throw UserNotFoundBookFaceException();
    itr->second.showFriendsStatuses(NUM_OF_FRIENDS_STATUSESS);
}

void BookFace::showAllStatusesFromPage(const Page &page) const noexcept(false) {
    const FriendPage* temp1 = dynamic_cast<const FriendPage*>(&page);
    const FanPage* temp2 = dynamic_cast<const FanPage*>(&page);
    if(temp1)
    {
        auto itr = this->users.find(temp1->getName());
        if(itr == this->users.end())
            throw UserNotFoundBookFaceException();
        itr->second.showStatuses();
    }
    else
    {
        auto itr = this->fanPages.find(temp2->getName());
        if(itr == this->fanPages.end())
            throw PageNotFoundBookFaceException();
        itr->second.showStatuses();
    }
}

void BookFace::connectUsers(FriendPage &user1, FriendPage &user2) noexcept(false)
{
    if (user1 == user2)
        throw ApplyToSelfBookFaceException();
    auto itr1 = this->users.find(user1.getName());
    auto itr2 = this->users.find(user2.getName());
    if(itr1 != this->users.end() && itr2 != this->users.end())
    {
        itr1->second += itr2->second;
        itr2->second += itr1->second;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::removeUsersConnection(FriendPage &user1, FriendPage &user2)
{
    if (user1 == user2)
        throw ApplyToSelfBookFaceException();
    auto itr1 = this->users.find(user1.getName());
    auto itr2 = this->users.find(user2.getName());
    if(itr1 != this->users.end() && itr2 != this->users.end())
    {
        itr1->second -= itr2->second;
        itr2->second -= itr1->second;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::followFanPage(FriendPage &user, FanPage &fanPage)
{
    auto itr1 = this->users.find(user.getName());
    auto itr2 = this->fanPages.find(fanPage.getName());
    if(itr1 != this->users.end() && itr2 != this->fanPages.end())
    {
        itr1->second += itr2->second;
        itr2->second += itr1->second;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::unfollowFanPage(FriendPage &user, FanPage &fanPage)
{
    auto itr1 = this->users.find(user.getName());
    auto itr2 = this->fanPages.find(fanPage.getName());
    if(itr1 != this->users.end() && itr2 != this->fanPages.end())
    {
        itr1->second -= itr2->second;
        itr2->second -= itr1->second;
    }
    else
        throw PageNotFoundBookFaceException();
}

void BookFace::showAllFollowersOfPage(const Page &page) const noexcept(false) {
    const FriendPage* temp1 = dynamic_cast<const FriendPage*>(&page);
    const FanPage* temp2 = dynamic_cast<const FanPage*>(&page);
    if(temp1)
    {
        auto itr = this->users.find(page.getName());
        if (itr == this->users.end())
            throw UserNotFoundBookFaceException();
        itr->second.showFollowers();
    }
    else
    {
        auto itr = this->fanPages.find(page.getName());
        if (itr == this->fanPages.end())
            throw PageNotFoundBookFaceException();
        itr->second.showFollowers();
    }
}



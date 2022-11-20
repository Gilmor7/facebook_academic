#include "friend_page.h"

FriendPage::FriendPage(char* name, Date birthDate):Page(name)
{
    this->birthDate = birthDate;
}

FriendPage::FriendPage(FriendPage& otherFriend)
{

}

FriendPage::FriendPage(FriendPage&& otherFriend)
{

}

FriendPage::~FriendPage()
{
   delete[] this->friends;
   delete[] this->followingFanPages;
}

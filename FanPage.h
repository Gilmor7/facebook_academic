
#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include "friend_page.h"

class FanPage: public Page
{
private:
    FriendPage** followers;
    int followersLogSize, followersPhySize;
public:

    FanPage(const char* pageName);
    FanPage(const FanPage& other);
    FanPage(FanPage&& other);
    ~FanPage();

    void addFollower(FriendPage& user);
    void showFollowers() const;
    void doubleFollowersSize();
};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

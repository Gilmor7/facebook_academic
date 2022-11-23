#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include "StatusArray.h"
#include "FriendArray.h"

class Status;
class FriendPage;

class FanPage
{
private:
    char* pageName;
    StatusArray statusesArr;
    FriendArray followersArr;

public:
    FanPage(const char* name);
    FanPage(const FanPage& other) = delete;
    FanPage(FanPage&& other);
    ~FanPage();

    void addFollower(FriendPage& follower);
    void showFollowers() const;

    void showStatuses() const;
    void addStatus(Status& status);

    void showName() const;
};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

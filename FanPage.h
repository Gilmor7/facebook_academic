#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include "StatusArray.h"
#include "FriendArray.h"
#include <iostream>
#include "Status.h"
#include "FriendPage.h"
#include <string.h>

using namespace std;

class FanPageArray;

class FanPage
{
public:
    static constexpr const char* const PAGE_IS_FOLLOWED = "You are already following this page\n";
    static constexpr const char* const PAGE_IS_NOT_FOLLOWED = "You are not following this page\n";
private:
    char* pageName;
    StatusArray statusesArr;
    FriendArray followersArr;

public:
    FanPage(const char* name);
    FanPage(const FanPage& other) = delete;
    FanPage(FanPage&& other);
    ~FanPage();

    // Getters
    const char* getName() const {return this->pageName;}

    bool addFollower(FriendPage& follower);
    bool removeFollower(FriendPage& follower);
    void showFollowers() const;

    static int findFanPageIndex(FanPage& fanPage, const FanPageArray* friends);
    void showStatuses(int amount = ALL) const;
    void addStatus(Status& status);

    void showName() const;
};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

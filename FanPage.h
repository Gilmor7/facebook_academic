#ifndef FACEBOOK_ACADEMIC_FANPAGE_H
#define FACEBOOK_ACADEMIC_FANPAGE_H

#include "Page.h"
#include "FriendPage.h"


class FanPage: public Page
{
public:
    FanPage(const std::string& name) noexcept(false): Page(name){};
    FanPage(ifstream& in);

    const FanPage& operator+=(const FriendPage& user) noexcept(false);
    const FanPage& operator-=(const FriendPage& user) noexcept(false);
};


#endif //FACEBOOK_ACADEMIC_FANPAGE_H

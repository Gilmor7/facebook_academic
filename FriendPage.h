#ifndef FACEBOOK_ACADEMIC_FRIENDPAGE_H
#define FACEBOOK_ACADEMIC_FRIENDPAGE_H

#include "Date.h"
#include "FriendArray.h"
#include "StatusArray.h"
//#include "FanPageArray.h"

const int NOT_FOUND = -1;

class FriendPage
{
private:
    // Date birthDate;

    const char* name;

    FriendArray friends;
    StatusArray statuses;
//    FanPageArray fanPages;


public:
    FriendPage() = default; // for testing only

    void showName() const;
};


#endif //FACEBOOK_ACADEMIC_FRIENDPAGE_H

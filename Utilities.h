
#ifndef FACEBOOK_ACADEMIC_UTILITIES_H
#define FACEBOOK_ACADEMIC_UTILITIES_H

#include "Bookface.h"

FriendPage* getFriendByNameFromSystem(const char* name, BookFace& system);
FanPage* getFanPageByNameFromSystem(const char* name, BookFace& system);
void initilizeStartingDataIntoSystem(BookFace& system);

// testing functions
void gilTest();
void EliTest();

#endif //FACEBOOK_ACADEMIC_UTILITIES_H

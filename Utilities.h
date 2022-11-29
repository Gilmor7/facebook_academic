
#ifndef FACEBOOK_ACADEMIC_UTILITIES_H
#define FACEBOOK_ACADEMIC_UTILITIES_H

#include "Bookface.h"
#include <iostream>
#include <string.h>
using namespace std;

void displayMenu();
eOption getUserInput();
void activateEOption(eOption option, BookFace& system);

FriendPage* getFriendByNameFromSystem(const char* name, BookFace& system);
FanPage* getFanPageByNameFromSystem(const char* name, BookFace& system);


// testing functions
void gilTest();

#endif //FACEBOOK_ACADEMIC_UTILITIES_H

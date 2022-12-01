
#include "Utilities.h"

FriendPage* getFriendByNameFromSystem(const char* name, BookFace& system)
{
    FriendArray* usersPtr = system.getFriendArrayPtr();
    FriendPage* foundUser = nullptr;
    for(int i=0; i < usersPtr->getSize(); i++)
    {
        if(strcmp(usersPtr->getFriendAtIndex(i)->getName(), name) == 0)
            foundUser = usersPtr->getFriendAtIndex(i);
    }
    return foundUser;
}

FanPage* getFanPageByNameFromSystem(const char* name, BookFace& system)
{
    FanPageArray* pagesPtr = system.getFanPagesArrayPtr();
    FanPage* foundPage = nullptr;
    for(int i=0; i < pagesPtr->getSize(); i++)
    {
        if(strcmp(name, pagesPtr->getFanPageAtIndex(i)->getName()) == 0)
            foundPage = pagesPtr->getFanPageAtIndex(i);
    }
    return foundPage;
}

void initilizeStartingDataIntoSystem(BookFace& system)
{
    FriendPage* f1 = new FriendPage("Eli", Date(12,9,1998));
    FriendPage* f2 = new FriendPage("Labron james", Date(30,12,1984));
    FriendPage* f3 = new FriendPage("Gil", Date(9,1,1997));

    FanPage* p1 = new FanPage("Labron james Fans");
    FanPage* p2 = new FanPage("c++ programmers");
    FanPage* p3 = new FanPage("The cup 'O' coffee drinkers");

    Status* f1s1 = new Status("I don't feel so good mr Stark - peter parker");
    Status* f1s2 = new Status("love and passion for the profession");
    Status* f2s1 = new Status("another good game today!");
    Status* f2s2 = new Status("the LA lakers are the best team in the NBA!");
    Status* f3s1 = new Status("Hello world...?");
    Status* f3s2 = new Status("Time is money!");
    Status* f3s3 = new Status("I think, therefore I am :)");
    Status* p1s1 = new Status("Wow!!!!! such a great game from Labron today");
    Status* p1s2 = new Status("We got the new Labron merchandise!!!!");
    Status* p2s1 = new Status("new c++ update coming out next week!");
    Status* p2s2 = new Status("class is a struct with functions... change my mind");
    Status* p3s1 = new Status("The best kind of coffee, is an irish coffee ;)");
    Status* p3s2 = new Status("if you like decaff coffee... please unfollow this page");




    system.addUser(*f1);
    system.addUser(*f2);
    system.addUser(*f3);

    system.addPage(*p1);
    system.addPage(*p2);
    system.addPage(*p3);

    system.addStatusToFriendPage(*f1, *f1s1);
    system.addStatusToFriendPage(*f1, *f1s2);
    system.addStatusToFriendPage(*f2, *f2s1);
    system.addStatusToFriendPage(*f2, *f2s2);
    system.addStatusToFriendPage(*f3, *f3s1);
    system.addStatusToFriendPage(*f3, *f3s2);
    system.addStatusToFriendPage(*f3, *f3s3);

    system.addStatusToFanPage(*p1, *p1s1);
    system.addStatusToFanPage(*p1, *p1s2);
    system.addStatusToFanPage(*p2, *p2s1);
    system.addStatusToFanPage(*p2, *p2s2);
    system.addStatusToFanPage(*p3, *p3s1);
    system.addStatusToFanPage(*p3, *p3s2);

    system.connectUsers(*f1,*f2);
    system.connectUsers(*f2,*f3);

    system.followFanPage(*f1,*p2);
    system.followFanPage(*f3,*p3);
    system.followFanPage(*f1,*p3);
    system.followFanPage(*f1,*p1);

}

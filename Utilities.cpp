
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
    FriendPage* f1 = new FriendPage("Eli Freid", Date(12,9,1998));
    FriendPage* f2 = new FriendPage("Bob bobinson", Date(6,6,1666));
    FriendPage* f3 = new FriendPage("Gil", Date(1,2,3));

    FanPage* p1 = new FanPage("John cena fans");
    FanPage* p2 = new FanPage("golden state warriors");
    FanPage* p3 = new FanPage("java script hate club");

    Status* f1s1 = new Status("good morning! ELI");
    Status* f1s2 = new Status("good night! ELI");
    Status* f2s1 = new Status("good morning! bob");
    Status* f2s2 = new Status("good morning! bobinson");
    Status* f3s1 = new Status("good morning! GIL");
    Status* f3s2 = new Status("good morning! GILGIL");
    Status* p1s1 = new Status("good morning! JOHN CEN");
    Status* p1s2 = new Status("good morning! CENA FANS");
    Status* p2s1 = new Status("good morning! WARRIORS");
    Status* p2s2 = new Status("good morning! SAN FRANSISCO");
    Status* p3s1 = new Status("good morning! JAVA SCRIPT");
    Status* p3s2 = new Status("good morning! REACT");




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

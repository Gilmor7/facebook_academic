
#include "Utilities.h"

void gilTest()
{
    //Test Fan Page
    const char* fanPageName = "Labron James Fan Page";
    FanPage testPage(fanPageName);
    testPage.showName();

    Date d1(9, 1, 1997);
    Date d2(9, 1, 1998);
    Date d3(9, 1, 1999);
    FriendPage f1("Gil", d1);
    FriendPage f2("Eli", d2);
    FriendPage f3("Keren", d3);
    testPage.addFollower(f1);
    testPage.addFollower(f2);
    testPage.addFollower(f3);

    testPage.showFollowers();
    //Test fanPage status methods
    Status s1("Hello 1");
    Status s2("Hello 2");
    Status s3("Hello 3");
    testPage.addStatus(s1);
    testPage.addStatus(s2);
    testPage.addStatus(s3);

    cout << "printing all testPage statuses" << endl;
    testPage.showStatuses(15);

    f2.addStatus(s1);
    f2.addStatus(s2);
    f2.addStatus(s3);

    //Test Fan Page friend methods
    cout << "adding friends to f1: " << endl;
    f1.addFriend(f2);
    f1.addFriend(f3);

    cout << "printing friends of f1: " << endl;
    f1.showFriends();

    cout << "removing a friend from f1: " << endl;
    f1.removeFriend(f3); //Should it be the name of f2 ?

    cout << "printing friends of f1: " << endl;
    f1.showFriends();
    int num = 2;
    cout << "calling showFriendsStatuses from f1 with 2: " << endl;
    f1.showFriendsStatuses(num);

    //test friendPage fanPages methods
    cout << endl << "testing fanPage array under friend instance" << endl;
    cout << endl<< "index of test page in arr" << FanPage::findFanPageIndex(testPage, f1.getFollowingPages()) << endl;
    f1.followFanPage(testPage);
    cout << "index of test page in arr" << FanPage::findFanPageIndex(testPage, f1.getFollowingPages()) << endl;

    f1.unfollowFanPage(testPage);
    cout << "index of test page in arr" << FanPage::findFanPageIndex(testPage, f1.getFollowingPages()) << endl;

}

void eliTest()
{
    FriendPage* f1 = new FriendPage("Eli Freid", Date(12,9,1998));
    FriendPage* f2 = new FriendPage("Bob bobinson", Date(6,6,1666));
    FriendPage* f3 = new FriendPage("Gil", Date(1,2,3));
    FriendPage* notInSystemUser = new FriendPage("Test", Date(1,1,1));

    FanPage* p1 = new FanPage("John cena fans");
    FanPage* p2 = new FanPage("golden state warriors");
    FanPage* p3 = new FanPage("java script hate club");
    FanPage* notInSystemPage = new FanPage("TESTTTTTT");

    Status* s1 = new Status("this is my first status!");
    Status* s2 = new Status("a good day for the fans");
    Status* s3 = new Status("no gonna work");
    Status* s4 = new Status("also not gonna work");

    Status* s5 = new Status("test1");
    Status* s6 = new Status("test2");
    Status* s7 = new Status("test3");

    {
        BookFace system;

        system.addUser(*f1);
        system.addUser(*f2);
        system.addPage(*p1);
        system.addPage(*p2);

        cout << "\n\n";

        system.addUser(*f1);   // should give error msg and not add -> works

        cout << "\n\n";

        system.addPage(*p2);  // should give error msg -> works
        cout << "\n\n";


        system.connectUsers(*f1, *f2);
        system.connectUsers(*f1, *f2);  // should give msg users are connected -> works
        cout << "\n\n";


        system.connectUsers(*f1, *notInSystemUser); // should give error msg
        cout << "\n\n";


        system.removeUsersConnection(*f1, *f2);
        system.removeUsersConnection(*f1, *f2); // should give msg users not connected -> works
        cout << "\n\n";

        system.removeUsersConnection(*f1, *notInSystemUser); // should give error msg -> works
        cout << "\n\n";


        system.showAllRegistered();

        system.addStatusToFanPage(*p1, *s2);
        system.addStatusToFanPage(*notInSystemPage, *s3); // error msg -> works
        cout << "\n\n";


        system.addStatusToFriendPage(*f2, *s1);
        system.addStatusToFriendPage(*notInSystemUser, *s4); // error msg(with implicit casting) -> works
        cout << "\n\n";

        system.showAllStatusesFromFriend(*f2);
        system.showAllStatusesFromFanPage(*p1);

        system.showAllStatusesFromFriend(*notInSystemUser); // error -> works
        system.showAllStatusesFromFanPage(*notInSystemPage);    // error -> works
        cout << "\n\n";

        system.addStatusToFriendPage(*f1, *s5);
        system.addStatusToFriendPage(*f1, *s6);
        system.addStatusToFriendPage(*f1, *s7);
        system.connectUsers(*f1, *f2);
        system.showAllStatusesFromUsersFriends(*f2);
        cout << endl;
        system.showAllStatusesFromUsersFriends(*f1);
        cout << endl;
        system.showAllStatusesFromUsersFriends(*notInSystemUser); // should give error
    }

    delete notInSystemUser;
    delete notInSystemPage;
}

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

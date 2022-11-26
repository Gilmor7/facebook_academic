#include <iostream>
#include "Bookface.h"
using namespace std;

int main()
{
    FriendPage* f1 = new FriendPage("Eli", Date(12,9,1998));
    FriendPage* f2 = new FriendPage("Bob", Date(6,6,1666));
    FriendPage* notInSystemUser = new FriendPage("Test", Date(1,1,1));

    FanPage* p1 = new FanPage("John cena fans");
    FanPage* p2 = new FanPage("golden state warriors");
    FanPage* notInSystemPage = new FanPage("TESTTTTTT");

    Status* s1 = new Status("this is my first status!");
    Status* s2 = new Status("a good day for the fans");
    Status* s3 = new Status("no gonna work");
    Status* s4 = new Status("also not gonna work");

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

    }

    delete notInSystemUser;
    delete notInSystemPage;
    delete s3;
    delete s4;
}

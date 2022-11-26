#include <iostream>
#include "Bookface.h"
using namespace std;

int main()
{
    FriendPage* f1 = new FriendPage("Eli", Date(12,9,1998));
    FriendPage* f2 = new FriendPage("Bob", Date(6,6,1666));

    FanPage* p1 = new FanPage("John cena fans");
    FanPage* p2 = new FanPage("golden state warriors");

    {
        BookFace system;
        system.addUser(*f1);
        system.addUser(*f2);

        system.addUser(*f1);   // should give error msg and not add -> works

        system.addPage(*p1);
        system.addPage(*p2);

        system.addPage(*p2);  // should give error msg -> works

        system.connectUsers(*f1, *f2);
        system.connectUsers(*f1, *f2);  // should give msg users are connected -> works

        system.removeUsersConnection(*f1, *f2);
        system.removeUsersConnection(*f1, *f2); // should give msg users not connected -> works


    }
}

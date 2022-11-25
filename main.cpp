#include <iostream>
#include "FanPage.h"
#include "Status.h"
#include "FriendPage.h"

using namespace std;

int main()
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

    f2.addStatus(s1);
    f2.addStatus(s2);
    f2.addStatus(s3);

    //Test Fan Page friend methods
    cout << "adding friends to f1: " << endl;
    f1.addFriend(&f2);
    f1.addFriend(&f3);

    cout << "printing friends of f1: " << endl;
    f1.showFriends();

    cout << "removing a friend from f1: " << endl;
    f1.removeFriend(&f3); //Should it be the name of f2 ?

    cout << "printing friends of f1: " << endl;
    f1.showFriends();
    int num = 2;
    cout << "calling showFriendsStatuses from f1 with 2: " << endl;
    f1.showFriendsStatuses(num);

    return 0;
}

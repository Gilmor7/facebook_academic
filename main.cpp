#include "FanPage.h"
#include "Status.h"
#include "FriendPage.h"

int main()
{
    //Test Fan Page
    const char* fanPageName = "Labron James Fan Page";
    FanPage testPage(fanPageName);
    testPage.showName();

    //Test Fan Page friend methods
    FriendPage f1("Gil");
    FriendPage f2("Eli");
    FriendPage f3("Keren");

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

    testPage.showStatuses();

    return 0;
}

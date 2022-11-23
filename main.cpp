#include "FanPage.h"
#include "FriendPage.h"

int main()
{

    const char* fanPageName = "Labron James Fan Page";
    FriendPage f1;

    FanPage testPage(fanPageName);
    testPage.showName();

    return 0;
}


#include "UserInterface.h"
#include "Utilities.h"
Date UserInterface::dummyDate(1,1,2000);

/// PLEASE NOTICE: the files already contain data! (if you want to reset the data, look at utilities.h)
int main()
{
    BookFace system;
    UserInterface interface;

    int option;

    do
    {
        interface.displayMenu();
        cin >> option;
        cin.get();
        interface.setOption((UserInterface::eOption) option);
        interface.activateOption(system);

    }   while(system.getRunningState());
    return 0;
}

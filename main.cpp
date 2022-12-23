
#include "UserInterface.h"
#include "Utilities.h"
Date UserInterface::dummyDate(1,1,2000);

int main()
{
    BookFace system;
    UserInterface interface;
    int option;

    initilizeStartingDataIntoSystem(system);

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

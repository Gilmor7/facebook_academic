

#include "UserInterface.h"
#include "Utilities.h"

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

}

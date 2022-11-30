

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
        if(option < 1 || option > 12)
            cout << UserInterface::INVALID_CHOICE_MSG;
        else
        {
            interface.setOption((UserInterface::eOption) option);
            interface.activateOption(system);
        }

    }   while(system.getRunningState());

}

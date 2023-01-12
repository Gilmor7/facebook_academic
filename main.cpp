
#include "UserInterface.h"
#include "Utilities.h"
Date UserInterface::dummyDate(1,1,2000);

int main()
{
//    BookFace system;
//    UserInterface interface;
//    int option;

//    Status s1("test");
//    ofstream output("Status.bin", ios::binary | ios::trunc);
//    s1.save(output);
//    output.close();

    ifstream input("Status.bin", ios::binary);
    Status s1(input);
    s1.showStatus();
    input.close();

//    initilizeStartingDataIntoSystem(system);
//
//    do
//    {
//        interface.displayMenu();
//        cin >> option;
//        cin.get();
//        interface.setOption((UserInterface::eOption) option);
//        interface.activateOption(system);
//
//    }   while(system.getRunningState());
//    return 0;
}

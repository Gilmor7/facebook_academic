
#include "Bookface.h"

int main()
{
    BookFace system;
    do {
        system.showMenu();
        system.setOptionInMenu();
        system.activateMenuOption();

    } while(system.getRunningState());

    return 0;
}

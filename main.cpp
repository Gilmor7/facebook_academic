
#include "Bookface.h"
#include "Utilities.h"

int main()
{
    BookFace system;
    eOption currChoice;
    do {

        displayMenu();
        currChoice = getUserInput();
        activateEOption(currChoice, &system);

    } while(system.getRunningState());

    return 0;
}

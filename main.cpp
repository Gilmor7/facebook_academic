
#include "Menu.h"


int main()
{
    Menu m;
    m.displayMenu();
    m.setChoiceFromUserInput();
    cout << (int)m.getChoice();
    return 0;
}


#include "Bookface.h"

BookFace::BookFace(): menu()
{
    // allocate arrays here
    // set logical & physical sizes here

    this->is_running = true;
}


void BookFace::showMenu()
{
    this->menu.displayMenu();
}

void BookFace::setOptionInMenu()
{
    this->menu.setChoiceFromUserInput();
}
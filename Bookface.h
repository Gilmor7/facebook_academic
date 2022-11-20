
#ifndef FACEBOOK_ACADEMIC_BOOKFACE_H
#define FACEBOOK_ACADEMIC_BOOKFACE_H

#include "Menu.h"

class BookFace
{
private:
    // users Arr
    // fanPages arr
    // numOf... (logical and physical)
    Menu menu;
    bool is_running;
public:
    BookFace();   // initialize some users and pages here  (in the future, load from files)

    // copy and move, maybe not needed?
    BookFace(const BookFace& other);
    BookFace(BookFace&& other);

    ~BookFace();  // (in the future, save to file)

    // created these functions to call manu methods inside BookFace, instead of returning menu (as copy)
    // and then calling the methods
    void showMenu();
    void setOptionInMenu();

    void activateMenuOption();
    bool getRunningState() const {return this->is_running;}
};

#endif //FACEBOOK_ACADEMIC_BOOKFACE_H

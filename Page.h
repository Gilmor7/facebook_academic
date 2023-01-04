
#ifndef FACEBOOK_ACADEMIC_PAGE_H
#define FACEBOOK_ACADEMIC_PAGE_H
#include <string.h>
#include <iostream>
#include "Status.h"
#include <vector>
#include "Exceptions.h"
#include <algorithm>
using namespace std;

constexpr int ALL = -1;

class Page
{
protected:
    string pageName;
    vector<const Page*> followers;      // will use polymorphism to store followers/friends (depend on the page)
    vector<Status*> statuses;           // * for later support of polymorphism in statuses

    // make Page abstract class
    Page(const string& pageName) noexcept(false);
public:
    // virtual D'tor
    virtual ~Page();

    // virtual methods
    virtual void showName() const;

    // regular methods
    void showStatuses(int amount = ALL) const;
    void showFollowers() const;
    void addStatus(const Status& newStatus);

    // operators
    bool operator>(const Page& other) const;
    bool operator==(const Page& other) const;
    bool operator==(const string &name) const;
    bool operator!=(const Page& other) const;
};


#endif //FACEBOOK_ACADEMIC_PAGE_H

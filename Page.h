
#ifndef FACEBOOK_ACADEMIC_PAGE_H
#define FACEBOOK_ACADEMIC_PAGE_H
#include <string.h>
#include <iostream>
#include "VideoStatus.h"
#include "ImageStatus.h"
#include <vector>
#include "Exceptions.h"
#include <unordered_map>
using namespace std;

constexpr int ALL = -1;

class Page
{
protected:
    string pageName;
    unordered_map<string, const Page*> followers;      // will use polymorphism to store followers/friends (depend on the page)
    vector<Status*> statuses;           // * for later support of polymorphism in statuses

    // make Page abstract class
    Page(const string& pageName) noexcept(false);
    Page(ifstream& in);
public:
    // virtual D'tor
    virtual ~Page();

    // virtual methods
    virtual void show() const;
    virtual void save(ofstream& out) const;

    // regular methods
    void showStatuses(int amount = ALL) const;
    void showFollowers() const;
    void addStatus(const Status& status);
    const string& getName() const;

    // operators
    bool operator>(const Page& other) const;
    bool operator==(const Page& other) const;
    bool operator==(const string &name) const;
    bool operator!=(const Page& other) const;
};


#endif //FACEBOOK_ACADEMIC_PAGE_H

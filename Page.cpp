
#include "Page.h"

Page::Page(const string &pageName) noexcept(false)
{
//    if(pageName == "")
//        throw CreatePageException
    this->pageName = pageName;
}

Page::~Page()
{
    auto itr = this->statuses.begin();
    auto itrEnd = this->statuses.end();
    for(; itr != itrEnd; ++itr)
    {
        delete *itr;
    }
}

void Page::showFollowers() const
{
    auto itr = this->followers.begin();
    auto itrEnd = this->followers.end();
    for(; itr != itrEnd; ++itr)
    {
        (*itr)->show();
    }
}

void Page::showStatuses(int amount) const
{
    int size;
    if(amount == ALL)
        size = this->statuses.size();
    else
        size = amount;
    auto itr = this->statuses.begin();
    auto itrEnd = this->statuses.end();
    cout << this->pageName << "'s Statuses: " << endl;
    for(int i = 0; itr != itrEnd && i < size; ++itr, ++i)
    {
        (*itr)->showStatus();
    }
}

void Page::addStatus(const Status &newStatus)
{
    this->statuses.push_back(new Status(newStatus));    // need to check if working properly
}



void Page::show() const
{
    cout << "Name: " << this->pageName << endl;
}

bool Page::operator>(const Page &other) const
{
    int p1Size = this->followers.size();
    int p2Size = other.followers.size();
    if(p1Size > p2Size)
        return true;
    return false;
}

bool Page::operator==(const Page &other) const
{
    return this->pageName == other.pageName;
}

bool Page::operator!=(const Page &other) const
{
    bool res = *this == other;
    return !res;
}

bool Page::operator==(const string &name) const
{
    return this->pageName == name;
}
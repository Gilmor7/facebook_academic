#include <string.h>
#include "page.h"
#include "status.h"

Page::Page(const char* name)
{
    setName(name);
    statuses = nullptr;
    numOfStatuses = 0;
}

Page::Page(const Page& otherPage)
{
    setName(name);

    this->numOfStatuses = otherPage.numOfStatuses;
    this->statuses = new Status*[this->numOfStatuses];

    for (int i = 0; i < this->numOfStatuses; ++i) {
        this->statuses[i] = new Status(*otherPage.statuses[i]);
    }
}

Page::Page(Page&& otherPage)
{
    this->name = otherPage.name;
    otherPage.name = nullptr;

    this->statuses = otherPage.statuses;
    otherPage.statuses = nullptr;

    this->numOfStatuses = otherPage.numOfStatuses;
}

Page::~Page()
{
    delete[] name;

    for (int i = 0; i < this->numOfStatuses; ++i) {
        delete this->statuses[i];
    }
    delete[] statuses;
}

char* Page::getName()
{
    return this->name;
}

void Page::setName(const char* name)
{
    strcpy(this->name, name);
}

void Page::addStatus(Status& status)
{
    if(numOfStatuses == 0)
    {
        this->statuses = new Status*[2];
    }
    // Need To agree how to handle allocatoion
    // Should we have logic and phsy sizes?

    this->statuses[this->numOfStatuses] = &status;
    this->numOfStatuses += 1;

}

void Page::showStatuses(const int amount) const
{
    // need to discuss regarding it's for specific friend or for all friend last 10
    // if all friends - we need to move this method from here.
}

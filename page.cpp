#include <string.h>
#include <iostream>
#include "page.h"
#include "status.h"

Page::Page(const char* name)
{
    setName(name);
    this->logicNumOfStatuses = 0;
    this->physiqueNumOfStatuses = 2;
    statuses = new Status*[this->physiqueNumOfStatuses];
}

Page::Page(const Page& otherPage)
{
    setName(name);

    this->logicNumOfStatuses = otherPage.logicNumOfStatuses;
    this->physiqueNumOfStatuses = otherPage.physiqueNumOfStatuses;
    this->statuses = new Status*[this->physiqueNumOfStatuses];

    for (int i = 0; i < this->logicNumOfStatuses; ++i) {
        this->statuses[i] = new Status(*otherPage.statuses[i]);
    }
}

Page::Page(Page&& otherPage)
{
    this->name = otherPage.name;
    otherPage.name = nullptr;

    this->statuses = otherPage.statuses;
    otherPage.statuses = nullptr;

    this->logicNumOfStatuses = otherPage.logicNumOfStatuses;
    this->physiqueNumOfStatuses = otherPage.physiqueNumOfStatuses;
}

Page::~Page()
{
    delete[] name;

    for (int i = 0; i < this->logicNumOfStatuses; ++i) {
        delete this->statuses[i];
    }
    delete[] statuses;
}

char* Page::getName() const
{
    return this->name;
}

void Page::setName(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Page::addStatus(Status*& status)
{
    if(this->logicNumOfStatuses == this->physiqueNumOfStatuses)
    {
        this->physiqueNumOfStatuses *= 2;
        reallocStatuses(this->logicNumOfStatuses, this->physiqueNumOfStatuses);
    }

    this->statuses[this->logicNumOfStatuses] = status;
    this->logicNumOfStatuses += 1;
}

// Display statuses from the newest to oldest.
// Default value amount = -1 Means Show All Statuses.
void Page::showStatuses(int amount) const
{
    if (amount == -1 || (amount < -1 )|| (amount > this->logicNumOfStatuses))
        amount = this->logicNumOfStatuses;

    int stopIndex = this->logicNumOfStatuses - amount;
    int startIndex = this->logicNumOfStatuses - 1;

    for (int i = startIndex; i >= stopIndex; --i) {
        this->statuses[i]->showStatus();
    }
}

void Page::reallocStatuses(const int size, const int newSize)
{
    std::cout <<"was here" <<std::endl;
    Status** UpdatedStatuses = new Status*[newSize];

    for (int i = 0; i < size; ++i) {
        UpdatedStatuses[i] = this->statuses[i];
    }

    delete[] this->statuses;
    this->statuses = UpdatedStatuses;
}

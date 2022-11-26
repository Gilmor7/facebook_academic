#include "StatusArray.h"
#include "Status.h"

StatusArray::StatusArray()
{
    this->logSize = 0;
    this->phySize = 2;
    statuses = new Status*[phySize];
}

StatusArray::~StatusArray()
{
    delete[] statuses;
}

/// Methods
void StatusArray::push(Status& newStatus)
{
    if(this->logSize == this->phySize)
        realloc();

    this->statuses[this->logSize] = &newStatus;
    this->logSize += 1;
}

void StatusArray::show(int amount) const
{
    int statusesAmount;
    if(amount == ALL || amount > this->logSize)
        statusesAmount = this->logSize;

    else if (amount < -1)
        statusesAmount = 0;

    else statusesAmount = amount;

    int stopIndex = this->logSize - statusesAmount;
    int startIndex = this->logSize - 1;

    for(int i = startIndex; i >= stopIndex; i--)
        this->statuses[i]->showStatus();
}

void StatusArray::deleteStatuses()
{
    for(int i = 0; i < this->logSize; i++)
        delete this->statuses[i];
}

/// Private Methods
void StatusArray::realloc()
{
    this->phySize *= 2;
    Status** updatedStatuses = new Status*[this->phySize];

    for (int i = 0; i < this->logSize; ++i)
        updatedStatuses[i] = this->statuses[i];

    delete[] this->statuses;
    this->statuses = updatedStatuses;
}

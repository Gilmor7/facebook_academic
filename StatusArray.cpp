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
    for (int i = 0; i < this->logSize; ++i) {
        delete this->statuses[i];
    }
    delete[] statuses;
}

// Methods
void StatusArray::push(Status& newStatus)
{
    if(this->logSize == this->phySize)
        realloc();

    this->statuses[this->logSize] = &newStatus;
    this->logSize += 1;
}

void StatusArray::realloc()
{
    this->phySize *= 2;
    Status** updatedStatuses = new Status*[this->phySize];

    for (int i = 0; i < this->logSize; ++i)
        updatedStatuses[i] = this->statuses[i];

    delete[] this->statuses;
    this->statuses = updatedStatuses;
}

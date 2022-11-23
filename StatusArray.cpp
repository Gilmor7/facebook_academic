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
    {
        this->phySize *= 2;
        realloc(this->logSize, this->phySize);
    }

    this->statuses[this->logSize] = &newStatus;
    this->logSize += 1;
}

void StatusArray::realloc(const int size, const int newSize)
{
    Status** updatedStatuses = new Status*[newSize];

    for (int i = 0; i < size; ++i) {
        updatedStatuses[i] = this->statuses[i];
    }

    delete[] this->statuses;
    this->statuses = updatedStatuses;
}

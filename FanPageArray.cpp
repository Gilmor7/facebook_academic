#include <iostream>
#include "FanPageArray.h"
#include "FanPage.h"

FanPageArray::FanPageArray()
{
    this->logSize = 0;
    this->phySize = 2;
    this->fanPages = new FanPage*[phySize];
}

FanPageArray::~FanPageArray()
{
    delete[] fanPages;
}

/// Methods
void FanPageArray::push(FanPage& newFanPage)
{
    if(this->logSize == this->phySize)
        realloc();

    this->fanPages[this->logSize] = &newFanPage;
    this->logSize += 1;
}

bool FanPageArray::remove(int& indexToRemove)
{
    if(indexToRemove == NOT_FOUND || this->logSize == 0) // Nothing to remove
        return false;

    for (int i = indexToRemove; i < this->logSize - 1; ++i)
        this->fanPages[i] = this->fanPages[i + 1];

    this->logSize--;
    return true;
}

void FanPageArray::show() const
{
    for(int i = 0; i < this->logSize; i++)
        this->fanPages[i]->showName();
}

/// Private Methods
void FanPageArray::realloc()
{
    this->phySize *= 2;
    FanPage** updatedFanPageArray = new FanPage*[this->phySize];

    for (int i = 0; i < this->logSize; ++i) {
        updatedFanPageArray[i] = this->fanPages[i];
    }

    delete[] this->fanPages;
    this->fanPages = updatedFanPageArray;
}
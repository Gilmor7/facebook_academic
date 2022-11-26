#ifndef FACEBOOK_ACADEMIC_FANPAGEARRAY_H
#define FACEBOOK_ACADEMIC_FANPAGEARRAY_H

class FanPage;

class FanPageArray
{
private:
    FanPage** fanPages;
    int phySize;
    int logSize;

public:
    FanPageArray();
    FanPageArray(const FanPageArray& arr) = delete;
    ~FanPageArray();

    // getters
    const int getSize() const {return this->logSize;}
    const FanPage* getFanPageAtIndex(const int index) const {return this->fanPages[index];}

    // Methods
    void push(FanPage* newFanPage);
    bool remove(int& indexToRemove);
    void show() const;

    void emptyArrPtr() {fanPages = nullptr;}

    const bool isFanPageInArr(FanPage& fanPage) const;
    void deleteAllPages();

private:
    void realloc();
};

#endif //FACEBOOK_ACADEMIC_FANPAGEARRAY_H

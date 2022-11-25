#ifndef FACEBOOK_ACADEMIC_STATUSARRAY_H
#define FACEBOOK_ACADEMIC_STATUSARRAY_H
const int ALL = -1;

class Status;

class StatusArray
{
private:
    Status** statuses;
    int phySize;
    int logSize;

public:
    StatusArray();
    StatusArray(const StatusArray& arr) = delete;
    ~StatusArray();

    // Methods
    void push(Status& newStatus);
    void show(int amount = ALL) const;

    void emptyArrPtr() {statuses = nullptr;}

private:
    void realloc();
};

#endif //FACEBOOK_ACADEMIC_STATUSARRAY_H

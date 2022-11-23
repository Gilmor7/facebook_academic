#ifndef FACEBOOK_ACADEMIC_STATUSARRAY_H
#define FACEBOOK_ACADEMIC_STATUSARRAY_H

class Status;

class StatusArray
{
    Status** statuses;
    int phySize;
    int logSize;

public:
    StatusArray();
    ~StatusArray();

    // Methods
    void push(Status& newStatus);

private:
    StatusArray(const StatusArray& arr);

    void realloc(const int size, const int newSize);
};

#endif //FACEBOOK_ACADEMIC_STATUSARRAY_H

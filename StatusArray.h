#ifndef FACEBOOK_ACADEMIC_STATUSARRAY_H
#define FACEBOOK_ACADEMIC_STATUSARRAY_H

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
    //TODO: Move Ctor??
    ~StatusArray();

    // Methods
    void push(Status& newStatus);
    void show() const;


private:
    void realloc();
};

#endif //FACEBOOK_ACADEMIC_STATUSARRAY_H

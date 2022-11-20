#ifndef FACEBOOK_ACADEMIC_PAGE_H
#define FACEBOOK_ACADEMIC_PAGE_H

class Status;

class Page
{
protected:
    char* name;
    Status** statuses;
    int physiqueNumOfStatuses;
    int logicNumOfStatuses;

public:
    Page(const char* name);
    Page(const Page& otherPage);
    Page(Page&& otherPage);
    ~Page();

    //Getters and Setters
    char* getName() const;
    void setName(const char* name);

    //Methods
    void addStatus(Status*& status);
    void showStatuses(int amount = -1) const;

private:
    //private methods
    void reallocStatuses(const int size, const int newSize);

};

#endif //FACEBOOK_ACADEMIC_PAGE_H

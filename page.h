#ifndef FACEBOOK_ACADEMIC_PAGE_H
#define FACEBOOK_ACADEMIC_PAGE_H

class Status;

class Page
{
private:
    char* name;
    Status** statuses;
    int numOfStatuses;

public:
    Page(const char* name);
    Page(const Page& otherPage);
    Page(Page&& otherPage);
    ~Page();

    //Getters and Setters
    char* getName();
    void setName(const char* name);

    //Methods
    void addStatus(Status& status);
    void showStatuses(const int amount = -1) const;
};

#endif //FACEBOOK_ACADEMIC_PAGE_H

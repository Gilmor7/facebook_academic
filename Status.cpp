
#include "Status.h"

Status::Status(const char *text)
{
    setText(text);
    this->statusTime = time(nullptr);
}

Status::Status(const Status &other)
{
    setText(other.text);
    this->statusTime = other.statusTime;
}

Status::Status(Status &&other)
{
    this->text = other.text;
    other.text = nullptr;

    this->statusTime = other.statusTime;
}

Status::~Status()
{
    cout << "deleting status" << this->text << endl;
    delete[] text;
}

void Status::setText(const char *text)
{
    this->text = new char[strlen(text) + 1];
    strcpy(this->text, text);
}

void Status::showStatus() const
{
    cout << this->text << endl << ctime(&(this->statusTime)) << endl;
}
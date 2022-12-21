
#include "Status.h"

Status::Status(const std::string& text) noexcept(false)
{
    if(text.empty())
        throw "Text cannot be empty!\n";
    this->text = text;
    this->statusTime = time(nullptr);
}


void Status::showStatus() const
{
    cout << this->text << endl << ctime(&(this->statusTime)) << endl;
}

bool Status::operator==(const Status &other) const
{
    return this->text == other.text;
}

bool Status::operator!=(const Status &other) const
{
    return !(*this == other);
}
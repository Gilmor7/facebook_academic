#include "ImageStatus.h"

ImageStatus::ImageStatus(const string& text, const string &imgSrc)
: Status(text), imgSrc(imgSrc) {}

void ImageStatus::showStatus() const
{
    Status::showStatus();
    cout << "Opening Image..." << endl;

    char* cmd = Status::getCommand(this->imgSrc);
    system(cmd);

    delete[] cmd;
}

bool ImageStatus::operator==(const Status &other) const
{
    if(Status::operator!=(other))
        return false;

    const ImageStatus *otherStatus = dynamic_cast<const ImageStatus *>(&other);
    if(otherStatus == nullptr)
        return false;

    else
        return this->imgSrc == otherStatus->imgSrc;
}

bool ImageStatus::operator!=(const Status &other) const
{
    return !(*this == other);
}

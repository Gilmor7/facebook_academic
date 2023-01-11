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

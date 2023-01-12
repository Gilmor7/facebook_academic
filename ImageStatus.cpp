#include "ImageStatus.h"

ImageStatus::ImageStatus(const string& text, const string &imgSrc)
: Status(text), imgSrc(imgSrc) {}

ImageStatus::ImageStatus(ifstream &in) : Status(in)
{
    int size;
    in.read((char*)&size, sizeof(size));
    this->imgSrc.resize(size);
    in.read(&imgSrc[0], size);
}

void ImageStatus::showStatus() const
{
    Status::showStatus();
    cout << "Opening Image..." << endl;

    char* cmd = Status::getCommand(this->imgSrc);
//    system(cmd);

    delete[] cmd;
}

void ImageStatus::save(ofstream &out) const
{
    Status::save(out);
    int size = this->imgSrc.size();
    out.write((char*)&size, sizeof(size));
    out.write((char*)&imgSrc[0], size);
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

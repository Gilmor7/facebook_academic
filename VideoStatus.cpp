#include "VideoStatus.h"

VideoStatus::VideoStatus(const string& text, const string &videoSrc)
        : Status(text), videoSrc(videoSrc) {}

VideoStatus::VideoStatus(ifstream& in) : Status(in)
{
    int size;
    in.read((char*)&size, sizeof(size));
    videoSrc.resize(size);
    in.read(&videoSrc[0], size);
}

void VideoStatus::showStatus() const
{
    Status::showStatus();
    cout << "Opening Video..." << endl;

    char* cmd = Status::getCommand(this->videoSrc);
//    system(cmd);

    delete[] cmd;
}

bool VideoStatus::operator==(const Status &other) const
{
    if (Status::operator!=(other))
        return false;

    const VideoStatus *otherStatus = dynamic_cast<const VideoStatus *>(&other);
    if (otherStatus == nullptr)
        return false;

    else
        return this->videoSrc == otherStatus->videoSrc;
}

bool VideoStatus::operator!=(const Status &other) const
{
    return !(*this == other);
}

void VideoStatus::save(ofstream& out) const
{
    Status::save(out);
    int size = videoSrc.size();
    out.write((char*)&size, sizeof(size));
    out.write(&videoSrc[0], size);
}
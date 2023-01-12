#include "VideoStatus.h"

VideoStatus::VideoStatus(const string& text, const string &videoSrc)
        : Status(text), videoSrc(videoSrc) {}

void VideoStatus::showStatus() const
{
    Status::showStatus();
    cout << "Opening Video..." << endl;

    char* cmd = Status::getCommand(this->videoSrc);
    system(cmd);

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

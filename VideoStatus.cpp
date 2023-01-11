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

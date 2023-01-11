#ifndef FACEBOOK_ACADEMIC_VIDEOSTATUS_H
#define FACEBOOK_ACADEMIC_VIDEOSTATUS_H

#include "Status.h"

class VideoStatus : public Status
{
protected:
    string videoSrc;

public:
    VideoStatus(const string& text, const string &videoSrc);

public:
    virtual void showStatus() const override;
};

#endif //FACEBOOK_ACADEMIC_VIDEOSTATUS_H

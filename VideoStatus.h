#ifndef FACEBOOK_ACADEMIC_VIDEOSTATUS_H
#define FACEBOOK_ACADEMIC_VIDEOSTATUS_H

#include "Status.h"

class VideoStatus : public Status
{
protected:
    string videoSrc;

public: // Constructor
    VideoStatus(const string& text, const string &videoSrc);

public: // Public Methods
    virtual void showStatus() const override;

public: // Operators
    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;
};

#endif //FACEBOOK_ACADEMIC_VIDEOSTATUS_H

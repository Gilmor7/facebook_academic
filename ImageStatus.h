#ifndef FACEBOOK_ACADEMIC_IMAGESTATUS_H
#define FACEBOOK_ACADEMIC_IMAGESTATUS_H

#include "Status.h"

class ImageStatus : public Status
{
protected:
    string imgSrc;

public:
    ImageStatus(const string& text, const string &imgSrc);

public:
    virtual void showStatus() const override;
};

#endif //FACEBOOK_ACADEMIC_IMAGESTATUS_H

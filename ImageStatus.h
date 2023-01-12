#ifndef FACEBOOK_ACADEMIC_IMAGESTATUS_H
#define FACEBOOK_ACADEMIC_IMAGESTATUS_H

#include "Status.h"

class ImageStatus : public Status
{
protected:
    string imgSrc;

public: // Constructor
    ImageStatus(const string& text, const string &imgSrc);
    ImageStatus(ifstream& in);

public: // Public methods
    virtual void showStatus() const override;
    virtual void save(ofstream& out) const override;

public: // Operators
    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;
};

#endif //FACEBOOK_ACADEMIC_IMAGESTATUS_H

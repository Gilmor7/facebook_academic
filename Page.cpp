
#include "Page.h"

Page::Page(const string &pageName) noexcept(false)
{
    if(pageName.empty())
        throw CreateNewPageFanPageException();
    this->pageName = pageName;
}

Page::Page(ifstream &in)
{
    int nameLen;
    int statusLen;
    char type[Status::TYPE_LEN+1];

    // read pageName
    in.read((char*)&nameLen, sizeof(nameLen));
    pageName.resize(nameLen);
    in.read(&pageName[0], nameLen);

    // read statuses
    in.read((char*)&statusLen, sizeof(statusLen));
    for (int i = 0; i < statusLen; ++i) {
        in.read((char*)&type[0], Status::TYPE_LEN);
        type[Status::TYPE_LEN] = '\0';
        if(strncmp(type, typeid(Status).name(), Status::TYPE_LEN) == 0)
        {
            statuses.push_back(new Status(in));
        }
        else if(strncmp(type, typeid(ImageStatus).name(), Status::TYPE_LEN) == 0)
        {
            statuses.push_back(new ImageStatus(in));
        }
        else
        {
            statuses.push_back(new VideoStatus(in));
        }
    }
}

Page::~Page()
{
    auto itr = this->statuses.begin();
    auto itrEnd = this->statuses.end();
    for(; itr != itrEnd; ++itr)
    {
        delete *itr;
    }
}

void Page::showFollowers() const
{
    auto itr = this->followers.begin();
    auto itrEnd = this->followers.end();
    for(; itr != itrEnd; ++itr)
    {
        itr->second->show();
    }
}

void Page::showStatuses(int amount) const
{
    int size;
    if(amount == ALL)
        size = this->statuses.size();
    else
        size = amount;
    auto itr = this->statuses.begin();
    auto itrEnd = this->statuses.end();
    cout << this->pageName << "'s Statuses: " << endl;
    for(int i = 0; itr != itrEnd && i < size; ++itr, ++i)
    {
        (*itr)->showStatus();
    }
}

void Page::addStatus(const Status& status)
{
    const ImageStatus* is = dynamic_cast<const ImageStatus*>(&status);
    const VideoStatus* vs = dynamic_cast<const VideoStatus*>(&status);
    const Status* s = dynamic_cast<const Status*>(&status);
    if(is)
        this->statuses.push_back(new ImageStatus(*is));
    else if(vs)
        this->statuses.push_back(new VideoStatus(*vs));
    else
        this->statuses.push_back(new Status(*s));
}

void Page::show() const
{
    cout << "Name: " << this->pageName << endl;
}

void Page::save(ofstream &out) const
{
    int nameLen = pageName.size();
    int statSize = statuses.size();

    // save Page's Name
    out.write((char*)&nameLen, sizeof(nameLen));
    out.write(&pageName[0], nameLen);

    // save Page's Statuses
    out.write((char*)&statSize, sizeof(statSize));
    for (int i = 0; i < statSize; ++i) {
        statuses[i]->saveType(out);
        statuses[i]->save(out);
    }
}

void Page::saveConnections(ofstream &out) const
{
    int len1 = this->pageName.size();
    auto itr = this->followers.begin();
    auto itrE = this->followers.end();
    for(; itr != itrE; ++itr)
    {
        int len2 = itr->second->getName().size();
        // save current objects name
        out.write((char*)&len1, sizeof(len1));
        out.write(&pageName[0], len1);
        // save follower name
        out.write((char*)&len2, sizeof(len2));
        out.write(&itr->second->getName()[0], len2);
    }
}

const string& Page::getName() const
{
    return this->pageName;
}

bool Page::operator>(const Page &other) const
{
    int p1Size = this->followers.size();
    int p2Size = other.followers.size();
    if(p1Size > p2Size)
        return true;
    return false;
}

bool Page::operator==(const Page &other) const
{
    return this->pageName == other.pageName;
}

bool Page::operator!=(const Page &other) const
{
    bool res = *this == other;
    return !res;
}

bool Page::operator==(const string &name) const
{
    return this->pageName == name;
}
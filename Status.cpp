
#include "Status.h"
#include "Exceptions.h"

Status::Status(const std::string& text) noexcept(false)
{
    if(text.empty())
        throw StatusException();
    this->text = text;
    this->statusTime = time(nullptr);
}

Status::Status(ifstream &in)
{
    in.read((char*)this, sizeof(*this));
}

void Status::showStatus() const
{
    cout << this->text << endl << "At " << ctime(&(this->statusTime)) << endl;
}

bool Status::operator==(const Status &other) const
{
    return this->text == other.text;
}

bool Status::operator!=(const Status &other) const
{
    return !(*this == other);
}

char *Status::getCommand(const string &srcPath) const {
    string s_cmd = START_CMD + " " + srcPath;

    char* cmd = new char[srcPath.size() + 1 + START_CMD.size() + 1];
    strcpy(cmd, s_cmd.c_str());

    return cmd;
}

void Status::save(ofstream& out) const
{
    out.write((char*)this, sizeof(*this));
}

void Status::saveType(ofstream &out) const
{
    char type[TYPE_LEN+1];
    strncpy(type, typeid(*this).name(), TYPE_LEN);
    out.write((char*)&type[0], TYPE_LEN);
}
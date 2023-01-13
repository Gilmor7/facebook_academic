
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
    int textLen;
    in.read((char*)&textLen, sizeof(textLen));
    this->text.resize(textLen);
    in.read(&text[0], textLen);
    in.read((char*)&statusTime, sizeof(::time_t));
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
    int textLen = this->text.size();
    out.write((char*)&textLen, sizeof(textLen));
    out.write(&text[0], textLen);
    out.write((char*)&this->statusTime, sizeof(::size_t));
}

void Status::saveType(ofstream &out) const
{
    char type[TYPE_LEN+1];
    strncpy(type, typeid(*this).name(), TYPE_LEN);
    out.write((char*)&type[0], TYPE_LEN);
}
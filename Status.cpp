
#include "Status.h"
#include "Exceptions.h"

Status::Status(const std::string& text) noexcept(false)
{
    if(text.empty())
        throw StatusException();
    this->text = text;
    this->statusTime = time(nullptr);
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

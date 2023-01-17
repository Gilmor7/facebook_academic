
#include "Bookface.h"

/// C'tor
BookFace::BookFace()
{
    load();
    this->is_running = true;
}

BookFace::~BookFace()
{
    auto itr1 = this->users.begin();
    auto itrEnd1 = this->users.end();
    for(; itr1 != itrEnd1; ++itr1)
        delete itr1->second;

    auto itr2 = this->fanPages.begin();
    auto itrEnd2 = this->fanPages.end();
    for(; itr2 != itrEnd2; ++itr2)
        delete itr2->second;
}

/// Menu functions
void BookFace::addUser(FriendPage &newUser) noexcept(false)
{
    if(this->users.find(newUser.getName()) != this->users.end())
        throw AddNewUserBookFaceException();
    this->users.insert(make_pair(newUser.getName(), new FriendPage(newUser)));
}

void BookFace::addPage(FanPage &newFanPage) noexcept(false)
{
    if(this->fanPages.find(newFanPage.getName()) != this->fanPages.end())
        throw AddNewPageBookFaceException();
    this->fanPages.insert(make_pair(newFanPage.getName(), new FanPage(newFanPage)));
}

void BookFace::showAllRegistered() const
{
    cout << "Users: " << endl;
    auto userItr = this->users.begin();
    for(; userItr != this->users.end(); ++userItr)
        userItr->second->show();
    cout << "Pages: " << endl;
    auto pageItr = this->fanPages.begin();
    for(; pageItr != this->fanPages.end(); ++pageItr)
        pageItr->second->show();
}

void BookFace::addStatusToPage(const Page &page, const Status& status) noexcept(false)
{
    const FriendPage* temp1 = dynamic_cast<const FriendPage*>(&page);
    const FanPage* temp2 = dynamic_cast<const FanPage*>(&page);
    if(temp1)
    {
        auto itr = this->users.find(temp1->getName());
        if(itr == this->users.end())
            throw AddNewStatusBookFaceException();
        itr->second->addStatus(status);
    }
    else
    {
        auto itr = this->fanPages.find(temp2->getName());
        if(itr == this->fanPages.end())
            throw AddNewStatusBookFaceException();
        itr->second->addStatus(status);
    }
}

void BookFace::showAllStatusesFromUsersFriends(FriendPage &user) const noexcept(false)
{
    auto itr = this->users.find(user.getName());
    if(itr == this->users.end())
        throw UserNotFoundBookFaceException();
    itr->second->showFriendsStatuses(NUM_OF_FRIENDS_STATUSESS);
}

void BookFace::showAllStatusesFromPage(const Page &page) const noexcept(false) {
    const FriendPage* temp1 = dynamic_cast<const FriendPage*>(&page);
    const FanPage* temp2 = dynamic_cast<const FanPage*>(&page);
    if(temp1)
    {
        auto itr = this->users.find(temp1->getName());
        if(itr == this->users.end())
            throw UserNotFoundBookFaceException();
        itr->second->showStatuses();
    }
    else
    {
        auto itr = this->fanPages.find(temp2->getName());
        if(itr == this->fanPages.end())
            throw PageNotFoundBookFaceException();
        itr->second->showStatuses();
    }
}

void BookFace::connectUsers(FriendPage &user1, FriendPage &user2) noexcept(false)
{
    if (user1 == user2)
        throw ApplyToSelfBookFaceException();
    auto itr1 = this->users.find(user1.getName());
    auto itr2 = this->users.find(user2.getName());
    if(itr1 != this->users.end() && itr2 != this->users.end())
    {
        *itr1->second += *itr2->second;
        *itr2->second += *itr1->second;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::removeUsersConnection(FriendPage &user1, FriendPage &user2)
{
    if (user1 == user2)
        throw ApplyToSelfBookFaceException();
    auto itr1 = this->users.find(user1.getName());
    auto itr2 = this->users.find(user2.getName());
    if(itr1 != this->users.end() && itr2 != this->users.end())
    {
        *itr1->second -= *itr2->second;
        *itr2->second -= *itr1->second;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::followFanPage(FriendPage &user, FanPage &fanPage)
{
    auto itr1 = this->users.find(user.getName());
    auto itr2 = this->fanPages.find(fanPage.getName());
    if(itr1 != this->users.end() && itr2 != this->fanPages.end())
    {
        *itr1->second += *itr2->second;
        *itr2->second += *itr1->second;
    }
    else
        throw UserNotFoundBookFaceException();
}

void BookFace::unfollowFanPage(FriendPage &user, FanPage &fanPage)
{
    auto itr1 = this->users.find(user.getName());
    auto itr2 = this->fanPages.find(fanPage.getName());
    if(itr1 != this->users.end() && itr2 != this->fanPages.end())
    {
        *itr1->second -= *itr2->second;
        *itr2->second -= *itr1->second;
    }
    else
        throw PageNotFoundBookFaceException();
}

void BookFace::showAllFollowersOfPage(const Page &page) const noexcept(false) {
    const FriendPage* temp1 = dynamic_cast<const FriendPage*>(&page);
    const FanPage* temp2 = dynamic_cast<const FanPage*>(&page);
    if(temp1)
    {
        auto itr = this->users.find(page.getName());
        if (itr == this->users.end())
            throw UserNotFoundBookFaceException();
        itr->second->showFollowers();
    }
    else
    {
        auto itr = this->fanPages.find(page.getName());
        if (itr == this->fanPages.end())
            throw PageNotFoundBookFaceException();
        itr->second->showFollowers();
    }
}

void BookFace::stopTheProgram()
{
    this->save();
    this->is_running = false;
}


// save functions
void BookFace::save() const
{
    ofstream usersOut("Users.bin", ios::binary | ios::trunc);
    ofstream pagesOut("FanPages.bin", ios::binary | ios::trunc);
    ofstream connectionsOut("Connections.bin", ios::binary | ios::trunc);
    ofstream followshipOut("Followships.bin", ios::binary | ios::trunc);

    this->saveUsers(usersOut);
    this->savePages(pagesOut);
    this->saveConnections(connectionsOut);
    this->saveFollowship(followshipOut);

    usersOut.close();
    pagesOut.close();
    connectionsOut.close();
    followshipOut.close();
}

void BookFace::saveConnections(ofstream &out) const
/// this will save pairs of (user1Name, user2Name) so later we can user1 += user2 (and only this!)
/// (user2 will += user1 later when the pair [user2,user1] will be read)
/// this will be saved to Connections.bin
{
    auto itr = this->users.begin();
    auto itrEnd = this->users.end();
    for(; itr != itrEnd; ++itr)
    {
        itr->second->saveConnections(out);
    }
}

void BookFace::saveFollowship(ofstream &out) const
/// this will save the pairs of (fanPageName, FollowersName) so later on we can fanP += user and user += fanP
/// this will be saved to Followship.bin
{
    auto itr = this->fanPages.begin();
    auto itrEnd = this->fanPages.end();
    for(; itr != itrEnd ; ++itr)
    {
        itr->second->saveConnections(out);
    }
}

void BookFace::saveUsers(ofstream &out) const
{
    int size = this->users.size();
    out.write((char*)&size, sizeof(size));
    auto itr = this->users.begin();
    auto itrEnd = this->users.end();
    for(; itr != itrEnd; ++itr)
    {
        itr->second->save(out);
    }
}

void BookFace::savePages(ofstream &out) const
{
    int size = this->fanPages.size();
    out.write((char*)&size, sizeof(size));
    auto itr = this->fanPages.begin();
    auto itrEnd = this->fanPages.end();
    for(; itr != itrEnd; ++itr)
    {
        itr->second->save(out);
    }
}

// load functions
void BookFace::load()
{
    ifstream usersIn("Users.bin", ios::binary);
    ifstream pagesIn("FanPages.bin", ios::binary);
    ifstream connectIn("Connections.bin", ios::binary);
    ifstream followIn("Followships.bin", ios::binary);

    loadUsers(usersIn);
    loadPages(pagesIn);
    loadConnections(connectIn);
    loadFollowship(followIn);

    usersIn.close();
    pagesIn.close();
    connectIn.close();
    followIn.close();
}


void BookFace::loadUsers(ifstream &in)
{
    if(in.peek() == ios::traits_type::eof())
        return;
    int size;
    in.read((char*)&size, sizeof(size));
    for(int i = 0; i < size; ++i)
    {
        FriendPage* newUser = new FriendPage(in);
        this->users.insert(make_pair(newUser->getName(), newUser));
    }
}

void BookFace::loadPages(ifstream &in)
{
    if(in.peek() == ios::traits_type::eof())
        return;
    int size;
    in.read((char*)&size, sizeof(size));
    for(int i = 0; i < size; ++i)
    {
        FanPage* newFanPage = new FanPage(in);
        this->fanPages.insert(make_pair(newFanPage->getName(), newFanPage));
    }
}

void BookFace::loadConnections(ifstream &in)
{
    if(in.peek() == ios::traits_type::eof())
        return;
    int len1, len2;
    string name1, name2;
    while(true)
    {
        // get first name
        in.read((char*)&len1, sizeof(len1));
        name1.resize(len1);
        in.read(&name1[0], len1);

        // get second name
        in.read((char*)&len2, sizeof(len2));
        name2.resize(len2);
        in.read(&name2[0], len2);

        // find users in users.arr
        auto u1 = this->users.find(name1);
        auto u2 = this->users.find(name2);

        // add user2 to user1 friends
        *u1->second += *u2->second;

        if(in.peek() == ios::traits_type::eof())
            break;
    }
}

void BookFace::loadFollowship(ifstream &in)
{
    if(in.peek() == ios::traits_type::eof())
        return;
    int len1, len2;
    string page, user;
    while(true)
    {
        in.read((char*)&len1, sizeof(len1));
        page.resize(len1);
        in.read(&page[0], len1);

        in.read((char*)&len2, sizeof(len2));
        user.resize(len2);
        in.read(&user[0], len2);

        auto u1 = this->users.find(user);
        auto u2 = this->fanPages.find(page);
        *u1->second += *u2->second;
        *u2->second += *u1->second;

        if(in.peek() == ios::traits_type::eof())
            break;
    }
}
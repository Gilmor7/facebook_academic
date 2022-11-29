#ifndef FACEBOOK_ACADEMIC_MEMBERARRAY_H
#define FACEBOOK_ACADEMIC_MEMBERARRAY_H

class FriendPage;

class FriendArray
{
private:
    FriendPage** friends;
    int phySize;
    int logSize;

public:
    FriendArray();
    FriendArray(const FriendArray& arr) = delete;
    ~FriendArray();

    // getters
    const int getSize() const {return this->logSize;}
    FriendPage* getFriendAtIndex(const int index) {return this->friends[index];}
    const FriendPage* getFriendAtIndex(const int index) const {return this->friends[index];}

    // Methods
    void push(FriendPage* newFriend);
    bool remove(int& indexToRemove);
    void show() const;
    void emptyArrPtr() {friends = nullptr;} // Empty friends pointer for using in Move C'tor of another class

    const bool isFriendInArr(FriendPage& user) const;

    void deleteAllUsers();

private:
    void realloc();
};

#endif //FACEBOOK_ACADEMIC_MEMBERARRAY_H

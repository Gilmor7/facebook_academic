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
    //TODO: Move Ctor??
    ~FriendArray();

    // Methods
    void push(FriendPage* newFriend);
    bool remove(int& indexToRemove);
    void show() const;
    void changePtrForMoveCtor() {friends = nullptr;}


    // getters
    const int getSize() const {return this->logSize;}
    const FriendPage* getFriendAtIndex(const int index) const {return this->friends[index];}

private:
    void realloc();
};

#endif //FACEBOOK_ACADEMIC_MEMBERARRAY_H

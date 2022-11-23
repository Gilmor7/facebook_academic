#ifndef FACEBOOK_ACADEMIC_MEMBERARRAY_H
#define FACEBOOK_ACADEMIC_MEMBERARRAY_H

class FriendPage;

class FriendArray
{
    FriendPage** friends;
    int phySize;
    int logSize;

public:
    FriendArray();
    ~FriendArray();

    // Methods
    void push(FriendPage& newFriend);
    bool remove(int& indexToRemove);

private:
    FriendArray(const FriendArray& arr);

    void realloc(const int size, const int newSize);
};

#endif //FACEBOOK_ACADEMIC_MEMBERARRAY_H

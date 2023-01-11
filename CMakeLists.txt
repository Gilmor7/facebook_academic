cmake_minimum_required(VERSION 3.20)
project(facebook_academic)

set(CMAKE_CXX_STANDARD 14)

add_executable(facebook_academic main.cpp Bookface.cpp Bookface.h Date.h Date.cpp FanPage.cpp FanPage.h FriendPage.cpp FriendPage.h Status.h Status.cpp UserInterface.cpp UserInterface.h Utilities.cpp Utilities.h Exceptions.h Page.cpp Page.h VideoStatus.h VideoStatus.cpp ImageStatus.h ImageStatus.cpp)
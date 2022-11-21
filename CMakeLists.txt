cmake_minimum_required(VERSION 3.20)
project(facebook_academic)

set(CMAKE_CXX_STANDARD 14)

add_executable(facebook_academic main.cpp Date.cpp Date.h Status.cpp Status.h Menu.cpp Menu.h page.h page.cpp friend_page.h friend_page.cpp Bookface.cpp Bookface.h FanPage.cpp FanPage.h)

cmake_minimum_required(VERSION 3.29)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library_Management_System main.cpp
        BookManager.h
        BookManager.cpp)

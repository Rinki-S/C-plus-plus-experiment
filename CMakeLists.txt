cmake_minimum_required(VERSION 3.26)
project(Grade_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Grade_Management_System
        source/main.cpp
        source/menu.cpp
        header/menu.h
        header/model.h
        source/file.cpp
        header/student.h
        source/student.cpp
        source/tools.cpp
        header/tools.h
        header/file.h)

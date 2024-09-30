cmake_minimum_required(VERSION 3.27)
project(clione)

set(CMAKE_CXX_STANDARD 11)

add_executable(clione main.cpp
        线性表/LinearTable.cpp
        "线性表/链表(带头节点).cpp")

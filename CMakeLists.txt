cmake_minimum_required(VERSION 3.29)
project(BinarySearchTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(BinarySearchTree main.cpp
        Tree.cpp
        Tree.h
        Node.h)

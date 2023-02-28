cmake_minimum_required(VERSION 3.17)
project(Assignment_3)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-static")

add_executable(SpellCheck
        src/main.cpp src/SpellChecker.cpp src/SpellChecker.h src/BST.cpp src/BST.h src/Node.h)

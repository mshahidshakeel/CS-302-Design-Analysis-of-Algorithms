cmake_minimum_required(VERSION 3.17)
project(algo)

set(CMAKE_CXX_STANDARD 20)

add_executable(algo src/main.cpp src/AnagramDictionary.cpp headers/AnagramDictionary.h src/Bucket.cpp headers/Bucket.h src/WordList.cpp headers/WordList.h)
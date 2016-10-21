cmake_minimum_required(VERSION 3.6)
project(Snippet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NumberGenerator.h NumberGenerator.cpp GlobalDefinition.h)
add_executable(Snippet ${SOURCE_FILES})
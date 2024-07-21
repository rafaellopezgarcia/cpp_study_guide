cmake_minimum_required(VERSION 3.10)
project(push_and_emplace_back)

set(CMAKE_CXX_STANDARD 20)
add_executable(push_and_emplace_back ./src/push_and_emplace_back.cpp)
add_executable(resource_management ./src/resource_management.cpp)
add_executable(custom_deleter_issue ./src/custom_deleter_issue.cpp)


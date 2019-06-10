cmake_minimum_required(VERSION 3.8)
project(wxHelloWorld)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(wxHelloWorld main.cpp)
target_link_libraries(wxHelloWorld ${wxWidgets_LIBRARIES})
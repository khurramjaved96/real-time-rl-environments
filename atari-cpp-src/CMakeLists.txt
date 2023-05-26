cmake_minimum_required(VERSION 3.14)

# Project specific target properties

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

project(real-time-atari LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(ale test.cpp)
find_package(ZLIB REQUIRED)
add_subdirectory(src)

find_package(Threads REQUIRED)
target_link_libraries(ale
        PUBLIC
        ZLIB::ZLIB
        Threads::Threads dl)

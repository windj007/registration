cmake_minimum_required(VERSION 2.8)

project(test)

SET(Boost_FIND_REQUIRED TRUE)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost 1.51 REQUIRED serialization thread system)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

ADD_SUBDIRECTORY(registration)

add_executable(test "main.cpp")
target_link_libraries(test ${Boost_LIBRARIES})

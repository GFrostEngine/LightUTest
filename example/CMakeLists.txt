cmake_minimum_required(VERSION 3.00)

project(LightUTest.examples)

include_directories(
        ../
)

set(BINARY test.STD)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(${BINARY} ${TEST_SOURCES})

#add_test(NAME ${BINARY} COMMAND ${BINARY})

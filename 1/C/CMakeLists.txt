cmake_minimum_required(VERSION 3.0)

project(C)

include_directories(${CMAKE_SOURCE_DIR}/A)
include_directories(${CMAKE_SOURCE_DIR}/B)
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(C main.cpp)

target_link_libraries(C lib)
add_dependencies(C GenerateIndex)

# Adding hard case (probably CTest not best naming, but it was a task)
include(CTest)
add_executable(CTest main_test.cpp tests.cpp)
target_include_directories(CTest PUBLIC tests.h)
target_link_libraries(CTest lib)
add_dependencies(CTest GenerateIndex)
target_link_libraries(CTest gtest)

add_test(CTest test)

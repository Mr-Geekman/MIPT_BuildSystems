cmake_minimum_required(VERSION 3.0)

# option for building for ARM
option(FOR_ARM "Build for ARM" ON)

# check if we pass suitable arguments if compile for arm
if(FOR_ARM)
    message("Compiling for ARM")
    set(CMAKE_TOOLCHAIN_FILE toolchain-arm.cmake)

    if("${ARM_TOOLCHAIN_PATH}" STREQUAL "")
        message(FATAL_ERROR "Need path to toolchain in variable ARM_TOOLCHAIN_PATH")
    endif()
endif()

project(SimpleLibrary)

# set rpath
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

# add public headers
set_target_properties(
    MainLib
    PROPERTIES
    PUBLIC_HEADER include/buffer.h
)

# installation
install(
    TARGETS Main MainLib buffer
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

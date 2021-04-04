cmake_minimum_required(VERSION 3.0)

project(4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${4_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${4_SOURCE_DIR}/lib)
set(RESOURCES_DIR ${4_SOURCE_DIR}/resources)

# add OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_calib3d opencv_video opencv_features2d opencv_ml opencv_highgui opencv_objdetect)

# add standard approach
add_executable(standard main_standard.cpp)
target_link_libraries(standard ${OpenCV_LIBS})

# add codegenerated approach
add_custom_command(
        OUTPUT map_image.h
        COMMAND python ${4_SOURCE_DIR}/generate_mapping.py ${RESOURCES_DIR}/map.png map_image.h
        DEPENDS generate_mapping.py resources/map.png
        COMMENT "Generating mapping from image"
)
add_custom_target(RunGenerator DEPENDS map_image.h COMMENT "Checking if re-generation is required")
add_executable(codegenerated main_codegenerated.cpp)
add_dependencies(codegenerated RunGenerator)
target_include_directories(codegenerated PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(codegenerated ${OpenCV_LIBS})

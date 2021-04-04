cmake_minimum_required(VERSION 3.0)

project(A)

add_custom_command(
        OUTPUT index.h
        COMMAND python ${PROJECT_SOURCE_DIR}/preparing.py index.h
        DEPENDS ${PROJECT_SOURCE_DIR}/preparing.py
        COMMENT "Generating index.h"
)

add_custom_target(GenerateIndex DEPENDS index.h COMMENT "Checking if re-generation is required")

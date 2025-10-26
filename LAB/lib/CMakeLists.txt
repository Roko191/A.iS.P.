cmake_minimum_required(VERSION 3.16)

add_library(LabUtils SHARED
    src/libLabUtils.c
)

target_include_directories(LabUtils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# spremi output u lib/out/
set_target_properties(LabUtils PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/out
)

cmake_minimum_required(VERSION 3.16)
get_filename_component(LAB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB LAB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/c/*.c"
)

add_executable(${LAB_NAME} ${LAB_SOURCES})

target_include_directories(${LAB_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/c
)

target_link_libraries(${LAB_NAME} PRIVATE LabUtils)


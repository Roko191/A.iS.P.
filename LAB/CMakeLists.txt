cmake_minimum_required(VERSION 3.16)
project(AiSP C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/out)

# Dodaj LabUtils library (iz mape LAB/lib/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/)

# Automatski pronađi sve LAB foldere i dodaj ih
file(GLOB LAB_DIRS "${CMAKE_SOURCE_DIR}/LAB*")

foreach(lab_dir ${LAB_DIRS})
    if (EXISTS "${lab_dir}/CMakeLists.txt")
        add_subdirectory(${lab_dir})
        get_filename_component(lab_name ${lab_dir} NAME)
        set_target_properties(${lab_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${lab_dir}/out
            OUTPUT_NAME "program"
        )
    endif()
endforeach()


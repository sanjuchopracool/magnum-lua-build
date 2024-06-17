cmake_minimum_required(VERSION 3.26)

project(TEST)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})


# Add Corrade as a subproject
add_subdirectory(corrade EXCLUDE_FROM_ALL)
add_subdirectory(magnum EXCLUDE_FROM_ALL)
add_subdirectory(lua EXCLUDE_FROM_ALL)

add_subdirectory(src)

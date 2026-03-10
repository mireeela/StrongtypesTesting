cmake_minimum_required(VERSION 3.20)
project(my_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Download Libs
include(cmake/DownloadCatch2.cmake)

# Central library
add_subdirectory(include)

# Tests
enable_testing()
add_subdirectory(tests_catch2)


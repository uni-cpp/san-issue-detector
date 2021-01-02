cmake_minimum_required(VERSION 3.16)
project(san-detector)
include(cmake/bootstrap.cmake)

add_executable(${PROJECT_NAME}
               src/app/sanitizer_detector/main.cpp
               src/sanitizer/address/issue/collection.hpp
               src/sanitizer/address/issue/collection.cpp
               src/sanitizer/undefined/issue/collection.hpp
               src/sanitizer/undefined/issue/collection.cpp
               )

target_include_directories(${PROJECT_NAME} PRIVATE src)

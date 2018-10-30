cmake_minimum_required (VERSION 3.1)
project (type_safe_identifier)

set (CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} type_safe_cats_and_dogs.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)


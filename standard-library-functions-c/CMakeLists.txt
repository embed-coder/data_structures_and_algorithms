cmake_minimum_required(VERSION 3.0.0)

# set the project name
project(data_structures_and_algorithms VERSION 0.1.0)

include(CTest)
enable_testing()

# add the executable
add_executable(01-float 01-float.c)
add_executable(24-pointer 24-pointer.c)
add_executable(25-snail_arr 25-snail_arr.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set debug flag
set(CMAKE_BUILD_TYPE Debug)
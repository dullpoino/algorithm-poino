cmake_minimum_required(VERSION 3.14)
project(algorithm-poino LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Math INTERFACE)

target_include_directories(Math
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_executable(example Example/main.cpp)
target_link_libraries(example PRIVATE Math)

cmake_minimum_required(VERSION 3.10)

project(campus_utility_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
file(GLOB SRC "src/*.cpp")
add_executable(main ${SRC})
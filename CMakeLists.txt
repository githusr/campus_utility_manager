cmake_minimum_required(VERSION 3.10)

project(campus_utility_manager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(system)
add_subdirectory(tui)
add_subdirectory(user)
add_subdirectory(utility)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC
    tui
)

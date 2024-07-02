add_library(utility
    src/rate.cpp
    src/utility_data.cpp
)

target_include_directories(utility PUBLIC
    include
)

target_link_libraries(utility PUBLIC
    tui
)
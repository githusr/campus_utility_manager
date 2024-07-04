add_library(utility
    src/rate.cpp
    src/utility_data.cpp
    include/utility/rate.h
    include/utility/utility_data.h
    include/utility/utility_type.h
)

target_include_directories(utility PUBLIC
    include
)

target_link_libraries(utility PUBLIC
    tui
)

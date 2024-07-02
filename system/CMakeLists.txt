add_library(system
    src/user_data_manager.cpp
)

target_include_directories(system PUBLIC
    include
)

target_link_libraries(system PUBLIC
    tui
    user
    utility
)
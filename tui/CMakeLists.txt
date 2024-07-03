add_library(tui
    src/action.cpp
    src/admin.cpp
    src/interaction.cpp
    src/menu_build.cpp
    src/menu_item.cpp
    src/navigate_menu.cpp
)

target_include_directories(tui PUBLIC
    include
)

target_link_libraries(tui PUBLIC
    system
    user
    utility
)

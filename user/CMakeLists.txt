add_library(user
    src/faculty.cpp
    src/student.cpp
    src/user.cpp
)

target_include_directories(user PUBLIC
    include
)

target_link_libraries(user PUBLIC
    utility
)
add_library(user
    src/faculty.cpp
    src/student.cpp
    src/user.cpp
    include/user/faculty.h
    include/user/student.h
    include/user/user.h
    include/user/user_type.h
)

target_include_directories(user PUBLIC
    include
)

target_link_libraries(user PUBLIC
    utility
)
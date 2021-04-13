project(Project)

add_executable(
    Project
    png.cpp
    geometry.cpp
    finder.cpp
    main.cpp
)

target_include_directories(
    Project PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

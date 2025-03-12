cmake_minimum_required(VERSION 3.31)
project(luna)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(game-activity REQUIRED CONFIG)

add_library(${PROJECT_NAME} SHARED
        main.cpp
)
target_link_libraries(${PROJECT_NAME} PUBLIC
        game-activity::game-activity_static
        android
        log
)

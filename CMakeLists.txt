cmake_minimum_required(VERSION 3.31)
project(luna)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
        main.cpp
)
target_link_libraries(${PROJECT_NAME} PUBLIC
        android
        log
)

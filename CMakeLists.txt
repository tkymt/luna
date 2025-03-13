cmake_minimum_required(VERSION 3.31)
project(luna)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_COMPILER_IMPORT_STD ON)
set(CMAKE_CXX_EXPERIMENTAL_CXX_IMPORT_STD ON)

find_package(game-activity REQUIRED CONFIG)

add_library(${PROJECT_NAME} SHARED)
target_link_libraries(${PROJECT_NAME} PUBLIC
        game-activity::game-activity_static
        android
        log
)
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
)
target_sources(${PROJECT_NAME} PRIVATE FILE_SET CXX_MODULES FILES

)

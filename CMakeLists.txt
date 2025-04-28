cmake_minimum_required(VERSION 3.31)
project(luna)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863 # v1.0.1
)
FetchContent_MakeAvailable(glm)

  # find Vulkan SDK
find_package( Vulkan REQUIRED )

add_library(${PROJECT_NAME} STATIC)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_sources(${PROJECT_NAME} PUBLIC windows_main.cpp)
target_sources(${PROJECT_NAME} PUBLIC
  FILE_SET CXX_MODULES
  FILES
  ThreadBase.ixx
  Application.ixx
  GameInfo.ixx
  Win32Application.ixx
  Graphics.ixx)
target_sources(${PROJECT_NAME} PRIVATE Win32Application.cpp Graphics.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC)
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan glm::glm)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE UNICODE)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PUBLIC /utf-8)
endif(MSVC)

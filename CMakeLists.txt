cmake_minimum_required(VERSION 3.30)
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

# Vulkan SDKを探す
find_package( Vulkan REQUIRED )

# このプロジェクトを静的ライブラリにする
add_library(${PROJECT_NAME} STATIC)

# ソースファイルを指定
set (PRIVATE_SOURCES
  ThreadBase.cpp
  Application.cpp
  GameInfo.cpp
  VulkanRenderer.cpp
  Win32Application.cpp
)
set(PUBLIC_SOURCES
  windows_main.cpp
)
list(TRANSFORM PRIVATE_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/")
list(TRANSFORM PUBLIC_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_sources(${PROJECT_NAME} PRIVATE
  ${PRIVATE_SOURCES})
target_sources(${PROJECT_NAME} PUBLIC
  ${PUBLIC_SOURCES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_definitions(${PROJECT_NAME} PUBLIC
  _UNICODE
  UNICODE)
target_link_libraries(${PROJECT_NAME} PRIVATE
  Vulkan::Vulkan
  glm::glm)
target_include_directories(${PROJECT_NAME} PUBLIC
  ${Vulkan_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PUBLIC /utf-8)
endif(MSVC)

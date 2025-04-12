cmake_minimum_required(VERSION 3.30)
project(luna)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_EXPERIMENTAL_CXX_IMPORT_STD ON)

include(FetchContent)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863 # v1.0.1
)
FetchContent_MakeAvailable(glm)

if(ANDROID)
  # Vulkan-Hppリポジトリを取得する
  FetchContent_Declare(
    vulkan-hpp
    GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Hpp.git
    GIT_TAG 1a24b015830c116632a0723f3ccfd1f06009ce12 # v1.3.275
  )
  FetchContent_MakeAvailable(vulkan-hpp)

  # luna settings
  find_package(game-activity REQUIRED CONFIG)

  add_library(${PROJECT_NAME} STATIC)
  target_sources(${PROJECT_NAME} PRIVATE main.cpp)
  target_sources(
    ${PROJECT_NAME}
    PRIVATE FILE_SET
            CXX_MODULES
            FILES
            AndroidApplication.ixx
            ThreadBase.ixx
            Application.ixx
            ApplicationInfo.ixx
            Graphics.ixx)
  target_include_directories(${PROJECT_NAME} PRIVATE ${vulkan-hpp_SOURCE_DIR})
  target_link_libraries(
    ${PROJECT_NAME} PRIVATE game-activity::game-activity_static vulkan glm::glm
                            android log)
elseif(WIN32)
  find_package(Vulkan REQUIRED)
  add_library(${PROJECT_NAME} STATIC)
  target_sources(${PROJECT_NAME} PRIVATE main.cpp Win32Application.cppm)
  target_sources(
    ${PROJECT_NAME}
    PRIVATE FILE_SET
            CXX_MODULES
            FILES
            ThreadBase.ixx
            Application.ixx
            ApplicationInfo.ixx
            Win32Application.ixx
            
            Graphics.ixx)
  target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES} glm::glm)
endif()

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif(MSVC)

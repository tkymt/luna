cmake_minimum_required(VERSION 3.31)
project(luna)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_EXPERIMENTAL_CXX_IMPORT_STD ON)

include(FetchContent)

# Vulkan-Hppリポジトリを取得する
FetchContent_Declare(
        vulkan-hpp
        GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Hpp.git
        GIT_TAG 1a24b015830c116632a0723f3ccfd1f06009ce12 # v1.3.275
)
FetchContent_MakeAvailable(vulkan-hpp)

# VulkanSDKを探す
# NDKでは、sysrootにあるスタブライブラリを見つける
find_package( Vulkan REQUIRED )

# Vulkan 1.3.256以上を必須とします （VulkanHppモジュールが初めて利用可能になったバージョンです）
if( ${Vulkan_VERSION} VERSION_LESS "1.3.256" )
    message( FATAL_ERROR "Minimum required Vulkan version for C++ modules is 1.3.256. "
            "Found ${Vulkan_VERSION}."
    )
endif()

# VulkanHppモジュールをセットアップします
add_library( VulkanHppModule )
# モジュールのソースファイルを設定します
target_sources( VulkanHppModule PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${vulkan-hpp_SOURCE_DIR}
        FILES ${vulkan-hpp_SOURCE_DIR}/vulkan/vulkan.cppm
)
# モジュールのソースファイルが参照するヘッダーファイルのディレクトリを設定します
target_include_directories( VulkanHppModule PRIVATE
        ${vulkan-hpp_SOURCE_DIR}
)
# FindVulkanで見つけたVulkanライブラリをリンクします
target_link_libraries( VulkanHppModule PRIVATE Vulkan::Vulkan )

# luna settings
find_package( game-activity REQUIRED CONFIG )
add_library( ${PROJECT_NAME} SHARED )
target_sources( ${PROJECT_NAME} PRIVATE
        main.cpp
)
target_sources( ${PROJECT_NAME} PRIVATE FILE_SET CXX_MODULES FILES

)
target_link_libraries( ${PROJECT_NAME} PRIVATE
        game-activity::game-activity_static
        VulkanHppModule
        android
        log
)

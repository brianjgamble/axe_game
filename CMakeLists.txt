cmake_minimum_required(VERSION 3.20)
project(axe_game_project VERSION 0.1.0 LANGUAGES CXX)

# Require C++20 and disable extensions for all targets
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Retrieve raylib
include(FetchContent)

FetchContent_Declare(
        RAYLIB
        GIT_REPOSITORY "https://github.com/raysan5/raylib"
        GIT_TAG 3.7.0
)

FetchContent_GetProperties(RAYLIB)
if (NOT raylib_POPULATED)
    FetchContent_Populate(RAYLIB)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
endif ()

# Retrieve Catch2
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.7)

FetchContent_MakeAvailable(Catch2)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

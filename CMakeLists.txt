cmake_minimum_required(VERSION 3.20)
project(axe_game_project VERSION 0.1.0 LANGUAGES CXX)

# Require C++20 and disable extensions for all targets
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download automatically, you can also just copy the conan.cmake file
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES
        catch2/2.13.7
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

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

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

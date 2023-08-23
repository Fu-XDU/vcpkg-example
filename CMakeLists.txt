cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 14)

if(NOT DEFINED URL_BASE)
    set(URL_BASE "github.com")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(VERSION "3.4.0")
set(VERSION_SUFFIX "")

# vcpkg init
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive -- vcpkg WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "Vcpkg toolchain file")
endif()

project(vcpkg_learn)

find_package(cryptopp CONFIG REQUIRED)
add_executable(vcpkg_learn main.cpp)
target_link_libraries(vcpkg_learn PRIVATE cryptopp::cryptopp)
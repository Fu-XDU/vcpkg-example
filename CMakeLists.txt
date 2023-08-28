cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

if (NOT DEFINED URL_BASE)
    set(URL_BASE "github.com")
endif ()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(VERSION "3.4.0")
set(VERSION_SUFFIX "")

# vcpkg init
include(ProjectVcpkg)
set(CMAKE_TOOLCHAIN_FILE "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(vcpkg_learn)

find_package(cryptopp CONFIG REQUIRED)

include(ProjectCoost)

# hide linker warnings on OS X
# issue: https://github.com/Microsoft/vcpkg/issues/4497
IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(other_flags "${other_flags} -frtti -fvisibility-inlines-hidden")
    set(other_flags "${other_flags} -fvisibility=hidden")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")
ENDIF ()

add_executable(vcpkg_learn main.cpp)
target_link_libraries(vcpkg_learn PRIVATE cryptopp::cryptopp coost::co)

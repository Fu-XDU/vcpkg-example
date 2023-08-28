include(FetchContent)

set(PACKAGE_NAME vcpkg)

FetchContent_Declare(
        ${PACKAGE_NAME}
        GIT_REPOSITORY "https://${URL_BASE}/microsoft/vcpkg.git"
        GIT_TAG "2023.08.09"
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/src/${PACKAGE_NAME}
)

FetchContent_MakeAvailable(${PACKAGE_NAME})
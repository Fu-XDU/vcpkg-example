include(FetchContent)

set(PACKAGE_NAME coost)

FetchContent_Declare(
        ${PACKAGE_NAME}
        GIT_REPOSITORY "https://${URL_BASE}/idealvin/coost.git"
        GIT_TAG "v3.0.0"
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/src/${PACKAGE_NAME}
)

FetchContent_MakeAvailable(${PACKAGE_NAME})
include(FetchContent)

FetchContent_Declare(
        coost
        GIT_REPOSITORY "https://${URL_BASE}/idealvin/coost.git"
        GIT_TAG "v3.0.0"
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/src/coost
)

FetchContent_MakeAvailable(coost)
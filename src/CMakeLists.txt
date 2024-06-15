cmake_minimum_required(VERSION 3.14.0)
project("app")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 20)

# Example: adding 3rd party library. In this case, Raylib
# Adding Raylib
# include(FetchContent)
# set(FETCHCONTENT_QUIET FALSE)
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
# set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

# FetchContent_Declare(
#     raylib
#     GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
#     GIT_TAG "master"
#     GIT_PROGRESS TRUE
# )

# FetchContent_MakeAvailable(raylib)

# Source files (.cpp files) here
set(SOURCE_FILES
    "Main.cpp"
)

# Header files here
set(HEADER_FILES
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
# target_link_libraries(${PROJECT_NAME} PRIVATE
# raylib
# )

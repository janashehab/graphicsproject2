cmake_minimum_required(VERSION 3.14)
project(Project2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GLM 1.0.1 is fetched from the official repository:
# https://github.com/g-truc/glm.git
#
# EXTERNAL — NOT VERIFIED IN LABS.
# FetchContent is build configuration for the math types used by the shared
# headers. It is not a graphics implementation, and it was not taken from the
# university lab materials.
include(FetchContent)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
    GIT_SHALLOW TRUE
)
set(GLM_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLM_BUILD_LIBRARY OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glm)

add_executable(Project2
    src/main.cpp
    src/Camera.cpp
    src/Player.cpp
    src/Input.cpp
    src/HUD.cpp
    src/Shader.cpp
    src/Model.cpp
    src/Texture.cpp
    src/Lights.cpp
    src/Ground.cpp
    src/Scene1.cpp
    src/Scene2.cpp
    src/Audio.cpp
)

target_include_directories(Project2 PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Project2 PRIVATE glm::glm)

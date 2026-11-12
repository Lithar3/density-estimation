cmake_minimum_required(VERSION 3.15)
project(Laba1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus.git
    GIT_TAG master
)

FetchContent_MakeAvailable(matplotplusplus)


add_executable(laba1 "Laba 1.cpp")


target_link_libraries(laba1 PRIVATE Matplot++::matplot)
cmake_minimum_required(VERSION 3.14)

project(ProxyDI CXX)

# ==== CONFIGURATION ==== #

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==== DEPENDENCIES ==== #

find_package(proxy CONFIG REQUIRED)


# ==== BUILDING TARGET ==== #

set(HEADERS
    v8engine.h
)

set(CLASS_SOURCES
    v8engine.cpp
)

list(TRANSFORM HEADERS PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)
list(TRANSFORM CLASS_SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)

add_library(${PROJECT_NAME} ${HEADERS} ${CLASS_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC msft_proxy)


add_subdirectory(tests)

cmake_minimum_required(VERSION 3.14)

project(ConceptsDI CXX)

# ==== CONFIGURATION ====

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==== BUILDING TARGET ==== #

set(HEADERS
    v8engine.h
    car.h
    engine.h
)

set(CLASS_SOURCES
    v8engine.cpp
    car.cpp
)

list(TRANSFORM HEADERS PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)
list(TRANSFORM CLASS_SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)

add_library(${PROJECT_NAME} ${HEADERS} ${CLASS_SOURCES})

add_subdirectory(tests)

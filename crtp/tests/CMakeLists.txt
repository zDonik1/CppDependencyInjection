cmake_minimum_required(VERSION 3.14)

project(CrtpDITests CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==== DEPENDENCY MANAGEMENT ==== #

include(${CMAKE_SOURCE_DIR}/3rd/cmake-conan-0.18.1/conan.cmake)

conan_cmake_configure(REQUIRES gtest/cci.20210126 GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)
conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
)

find_package(GTest CONFIG REQUIRED)


# ==== BUILDING TARGET ==== #

set(HEADERS
    mock_engine.h
)

set(SOURCES
    test_engine.cpp
    test_v8engine.cpp
    test_car.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${CLASS_SOURCES})
target_link_libraries(${PROJECT_NAME} GTest::gtest_main GTest::gmock)
target_include_directories(${PROJECT_NAME} PUBLIC ../src)

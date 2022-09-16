cmake_minimum_required(VERSION 3.14)

project(CppDIAndUnitTestExamples CXX)

# ==== CONFIGURATION ====

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==== SUBMODULES ==== #

add_subdirectory(interface)
add_subdirectory(template)
add_subdirectory(concepts)
add_subdirectory(proxy)
add_subdirectory(crtp)

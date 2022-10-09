cmake_minimum_required(VERSION 3.2)
project(muzeroxq)

# ##############################################################################
# Global compiler config
set(CMAKE_CXX_STANDARD 17)
set(PYBIND11_CPP_STANDARD -std=c++17)
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-register -Wno-deprecated-declarations -fPIC -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # require at least gcc 7.1
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7.1)
        message(FATAL_ERROR "GCC version must be at least 7.1!")
    endif()
endif()

find_package(fmt)
find_package(pybind11)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# ##############################################################################
# LIBS ####################################
# ##############################################################################
find_package(Threads)
find_package(Python COMPONENTS Interpreter Development)

add_library(muzeroxq src/print_func.cpp)

# add_executable(xqconsol src/main.cpp)
target_link_libraries(muzeroxq PRIVATE
    pybind11::lto pybind11::embed pybind11::module
    $<BUILD_INTERFACE:${PYTHON_LIBRARIES}>

    # TBB::tbb
    fmt::fmt-header-only

    # nlohmann_json::nlohmann_json
)

# target_link_libraries(xqconsol PRIVATE fmt::fmt-header-only)
pybind11_add_module(xqlib src/pybind_module.cpp)

target_link_libraries(xqlib PRIVATE
    muzeroxq
)
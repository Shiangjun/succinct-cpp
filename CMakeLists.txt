cmake_minimum_required(VERSION 2.8)
project(succinct CXX)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")
enable_language(C)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-modules)

# Builds all of Succinct's sub-modules
add_subdirectory(core)
add_subdirectory(examples)
add_subdirectory(sharded)
add_subdirectory(sharded-kv)
add_subdirectory(bench)

# Testing framework
# Build google testing framework
add_subdirectory(external/gtest-1.7.0)

# Build and run all tests for succinct
add_subdirectory(test)

enable_testing()
add_test(CoreTest ${TESTS_PATH}/core_test ${PROJECT_SOURCE_DIR}/test/data)

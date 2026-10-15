cmake_minimum_required(VERSION 3.20)
project(debug_warmup LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip 
)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(CTest)
include(GoogleTest)

add_executable(dw_test tests/dw_test.cpp src/dw.cpp)

target_include_directories(dw_test PRIVATE include)

target_compile_options(dw_test PRIVATE -g3 -O0)

target_link_libraries(dw_test PRIVATE GTest::gtest_main)

gtest_discover_tests(dw_test
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
)

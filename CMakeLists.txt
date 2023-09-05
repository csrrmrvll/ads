cmake_minimum_required(VERSION 3.0.0)
project(ads-test VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(ads-test src/test.cpp)
include_directories(include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_STANDARD 20)
target_compile_options(ads-test PRIVATE "-fconcepts")

cmake_minimum_required(VERSION 3.0.0)
project(auth-test VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(auth-test src/main.cpp)
set_property(TARGET auth-test PROPERTY CXX_STANDARD 20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

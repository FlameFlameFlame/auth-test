cmake_minimum_required(VERSION 3.0.0)
project(auth-test VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

add_library(AuthApp src/AuthApp.cpp)
add_library(AuthIO src/AuthIO.cpp)
add_library(Authenticator src/Authenticator.cpp)

add_executable(auth-test src/main.cpp)
target_link_libraries(auth-test PUBLIC AuthApp)
target_link_libraries(auth-test PUBLIC AuthIO)
target_link_libraries(auth-test PUBLIC Authenticator)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

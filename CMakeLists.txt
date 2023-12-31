cmake_minimum_required(VERSION 3.16.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(QrCode VERSION 1.0.0)
message(STATUS "ProjectVersion = ${CMAKE_PROJECT_VERSION}")

add_subdirectory(lib)
add_subdirectory(module)
add_subdirectory(test)

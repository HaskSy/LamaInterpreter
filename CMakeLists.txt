cmake_minimum_required (VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

project(LamaInterpreter LANGUAGES CXX VERSION 0.0.0)

include(cmake/utils.cmake)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

enable_warnings(${PROJECT_NAME})
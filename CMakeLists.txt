cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

project(JunoSync VERSION 0.0.1
                 LANGUAGES CXX)

add_executable(JunoServer apps/junoserver.cxx)
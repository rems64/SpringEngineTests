﻿cmake_minimum_required (VERSION 3.8)

project ("SpringEngine")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory ("Modules")
add_subdirectory ("SpringCore")
add_subdirectory ("SpringMain")
add_subdirectory ("SpringAnalyzer")
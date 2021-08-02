cmake_minimum_required (VERSION 3.8)
project(SpringCore)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_DOC "Build documentation" ON)

include_directories("include/")

set(SRCS
	
 "src/Core/Application.cpp" "src/Debug/Logger.cpp" )

add_subdirectory(lib/spdlog)
find_package(spdlog)

# Ajoutez une source à l'exécutable de ce projet.
add_library (SpringCore STATIC ${SRCS})

target_link_libraries(SpringCore spdlog)

target_precompile_headers(SpringCore
  PUBLIC
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/Spring/SpringCore/Core/pch.hpp>"
)

#find_package(Doxygen)
#if(DOXYGEN_FOUND)
#	message("DOXYGEN WAS FOUND")
#	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/Doxyfile.in)
#	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#	add_custom_target( SpringEngineDocumentation ALL
#        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#        COMMENT "Generating API documentation with Doxygen"
#        VERBATIM )
#endif(DOXYGEN_FOUND)
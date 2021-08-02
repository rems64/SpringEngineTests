# CMakeList.txt : projet CMake pour SpringEngine, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project(SpringAnalyzer)

option(BUILD_DOC "Build documentation" ON)

include_directories("include/" "../SpringCore/include/" "../SpringMain/include/" "../Modules/BaseModule/include/")

set(SRCS
    "src/Core/SpringAnalyzerApp.cpp"
)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (SpringAnalyzer ${SRCS})
target_link_libraries(SpringAnalyzer PUBLIC SpringCore SpringMain)

#target_precompile_headers(SpringAnalyzer
#  PUBLIC
#    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/SpringAnalyzer/Core/pch.hpp>"
#)

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
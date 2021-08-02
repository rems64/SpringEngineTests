cmake_minimum_required (VERSION 3.8)
project(SpringMain)

set(CMAKE_CXX_STANDARD 17)
 
include_directories("include/" "../Modules/BaseModule/include/" "../SpringCore/include/")

set(SRCS
	"src/Core/ModulesManager.cpp"
)

add_library (SpringMain STATIC ${SRCS})
target_link_libraries(SpringMain SpringCore BaseModule)
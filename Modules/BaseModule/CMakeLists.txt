project(SpringBaseModule)

include_directories("include/" "../../SpringCore/include/")

set(SRCS
	"src/SpringModule.cpp"
)

add_library(BaseModule SHARED ${SRCS})
target_link_libraries(BaseModule PUBLIC SpringCore)

target_compile_definitions(BaseModule PUBLIC SPRING_EXPORT_MODULE=1)
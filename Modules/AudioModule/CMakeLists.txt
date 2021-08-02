project(AudioModule)


include_directories("include/" "../BaseModule/include/" "../../SpringCore/include")

set(SRCS
	"src/Core/AudioModule.cpp"
)

add_library(AudioModule SHARED ${SRCS})
target_link_libraries(AudioModule PUBLIC BaseModule SpringCore)
target_compile_definitions(AudioModule PUBLIC SPRING_EXPORT_MODULE=1)
# CMakeList.txt : CMake project for ScreenSaver, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ScreenSaver")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory ( external/glfw )
add_subdirectory ( external/glm )

# Add source to this project's executable.
add_executable ( ScreenSaver  )

target_include_directories ( ScreenSaver
	PRIVATE
	"external/glad/include"
	#"external/glm"
)

target_link_libraries ( ScreenSaver
	PRIVATE
	glm
	glfw
)

target_sources ( ScreenSaver 
	PRIVATE 
	"external/glad/src/glad.c"
	"source/ScreenSaver.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ScreenSaver PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

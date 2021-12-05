cmake_minimum_required(VERSION 3.13)
# Project information
project(Excitation
  VERSION 3.0.0
  DESCRIPTION "Excitation functions."
  LANGUAGES CXX
)
include(FetchContent)
FetchContent_Declare(
	units
	GIT_REPOSITORY https://github.com/bolderflight/units.git
	GIT_TAG v4.0.1
)
FetchContent_MakeAvailable(units)
FetchContent_Declare(
	eigen
	GIT_REPOSITORY https://github.com/bolderflight/eigen.git
	GIT_TAG v3.0.2
)
FetchContent_MakeAvailable(eigen)
# Add the library target
add_library(excitation INTERFACE)
target_link_libraries(excitation
	INTERFACE
		units
		eigen
)
# Setup include directories 
target_include_directories(excitation INTERFACE src/)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(excitation_example examples/cmake/excitation_example.cc)
	# Add the includes
	target_include_directories(excitation_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the example target
	target_link_libraries(excitation_example
		PRIVATE 
			excitation
	)
endif()

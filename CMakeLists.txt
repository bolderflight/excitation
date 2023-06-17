cmake_minimum_required(VERSION 3.14)
# Project information
project(Excitation
  VERSION 4.0.0
  DESCRIPTION "Excitation functions."
  LANGUAGES CXX
)
include(FetchContent)
if (DEFINED DEPS)
  string(TOUPPER ${DEPS} DEPS)
  if (DEPS STREQUAL "BFS")
    # Fetch global defs
    FetchContent_Declare(
      units
      GIT_REPOSITORY git@192.168.1.11:bolderflight/software/units.git
      GIT_TAG v5.0.0
    )
  elseif(DEPS STREQUAL "LOCAL")
    # Fetch global defs
    FetchContent_Declare(
      units
      GIT_REPOSITORY ${CMAKE_SOURCE_DIR}/../units
      GIT_TAG v5.0.0
    )
  else()
    # Fetch global defs
    FetchContent_Declare(
      units
      GIT_REPOSITORY https://github.com/bolderflight/units.git
      GIT_TAG v5.0.0
    )
  endif()
else()
# Fetch global defs
FetchContent_Declare(
  units
  GIT_REPOSITORY https://github.com/bolderflight/units.git
  GIT_TAG v5.0.0
)
endif()
FetchContent_MakeAvailable(units)
# Add the library target
add_library(excitation
  src/chirp.cpp
  src/chirp.h
  src/doublet.cpp
  src/doublet.h
  src/excitation.h
  src/multisine.cpp
  src/multisine.h
  src/pulse.cpp
  src/pulse.h
  src/sampled.cpp
  src/sampled.h
)
target_link_libraries(excitation
  PUBLIC
    units
)
# Setup include directories 
target_include_directories(excitation PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>
)

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

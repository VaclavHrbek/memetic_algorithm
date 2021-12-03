cmake_minimum_required(VERSION 3.16)

# set the project name
project(memetic_algorithm)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(ENABLE_TESTS "Enable test" OFF)
option(ENABLE_EXAMPLES "Enable examples" ON)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# Add source file
add_subdirectory(src)

# Add the executable
if(ENABLE_EXAMPLES)
	add_subdirectory(app)
endif()

if(ENABLE_TESTS)
	include(CTest)
	find_program( MEMORYCHECK_COMMAND valgrind )
	set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )

	Include(FetchContent)
	add_subdirectory(tests)
endif()


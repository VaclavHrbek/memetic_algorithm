cmake_minimum_required(VERSION 3.16)

# set the project name
project(genetic_program)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


option(ENABLE_TESTS "Enable test" OFF)

Include(FetchContent)

add_library(city city.cpp city.hpp)
add_library(genetic_program genetic_program.cpp genetic_program.hpp)

# add the executable
add_executable(main main.cpp)

target_compile_options(genetic_program PUBLIC -g -Wall -Wextra -pedantic)
target_compile_options(city PUBLIC -g -Wall -Wextra -pedantic)

target_link_libraries(main 
	PRIVATE city
	PRIVATE genetic_program)


if(ENABLE_TESTS)


	FetchContent_Declare(
	  Catch2
	  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	  GIT_TAG        v3.0.0-preview3
	)

	FetchContent_MakeAvailable(Catch2)

	list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

	include(CTest)
	include(Catch)
	enable_testing()
	add_executable(tests
		test_city.cpp
		test_genetic_program.cpp)
	target_link_libraries(tests 
		PRIVATE Catch2::Catch2WithMain 
		city
		genetic_program)
	catch_discover_tests(tests
		TEST_PREFIX test__)

endif()




FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

file(GLOB TEST_FILES "${memetic_algorithm_SOURCE_DIR}/tests/*.cpp")

include(Catch)
enable_testing()
add_executable(tests
	${TEST_FILES})
target_link_libraries(tests 
	PRIVATE Catch2::Catch2WithMain 
	genetic_program)

catch_discover_tests(tests)

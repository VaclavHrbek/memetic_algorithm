



# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST "${memetic_algorithm_SOURCE_DIR}/include/memetic_algorithm/*.hpp")
file(GLOB SOURCE_LIST "${memetic_algorithm_SOURCE_DIR}/src/*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(genetic_program ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(genetic_program PUBLIC ../include)

target_compile_features(genetic_program PUBLIC cxx_std_17)


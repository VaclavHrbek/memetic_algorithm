
#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/genetic_operation.hpp>

using namespace GP;

TEST_CASE("Tree creation"){
	SECTION("create_full_tree function"){
		std::size_t depth = 2;
		auto tree_1 = create_full_tree<(depth);

	}
}

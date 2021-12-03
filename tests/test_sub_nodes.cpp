

#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/sub_nodes.hpp>

using namespace tree;

TEST_CASE("SubNodes class"){
	auto foo = SubNodes<int>{};
	SECTION("Test positioning of 'container'"){
		int a = 3;
		foo.push(a);
		foo.push(5);
		CHECK(foo.at(0) == 3);
		CHECK(foo.at(1) == 5);
		CHECK(foo.size() == 2);
	}
}

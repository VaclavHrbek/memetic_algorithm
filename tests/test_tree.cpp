
#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/tree.hpp>

using namespace tree;

TEST_CASE("Tree class"){
	auto tree_1 = Node<int>{};
	SECTION("Test swap function"){
		std::string s = "abc";
		auto tree_2 = Node<int>(2, {});
		CHECK_FALSE(tree_1 == tree_2);
		CHECK(tree_2.value() == 2);
		swap(tree_1, tree_2);
		CHECK_FALSE(tree_2.value() == 2);
		CHECK(tree_1.value() == 2);
	}
}

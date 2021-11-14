
#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/tree.hpp>

TEST_CASE("tree.hpp"){
	SECTION("Test of add_child function"){
		auto child_1 = tree::Node{};
		child_1._properties._type = "foo";
		auto parent_1 = tree::Node{};
		tree::add_child(parent_1, child_1);
		REQUIRE(parent_1._children.size() == 1);
		REQUIRE(parent_1._children.at(0)._properties._type == "foo");
	}
	SECTION("Test std::swap "){
		auto child_1 = tree::Node{};
		child_1._properties._type = "foo";
		auto child_2 = tree::Node{};
		child_2._properties._type = "bar";
		std::swap(child_1, child_2);
		REQUIRE(child_1._properties._type == "bar");
		REQUIRE(child_2._properties._type == "foo");
	}
	SECTION("Test operator== "){
		auto child_1 = tree::Node{};
		child_1._properties._type = "foo";
		auto child_2 = child_1;
		REQUIRE(child_1 == child_2);
	}
	SECTION("Test traverse_tree_post_order function"){
		auto child_1 = tree::Node{};
		child_1._properties._type = "foo";

		auto child_2 = tree::Node{};
		child_2._properties._type = "bar";

		auto child_3 = tree::Node{};
		child_3._properties._type = "baz";

		auto child_4 = tree::Node{};
		child_4._properties._type = "faz";
		child_3._children.push_back(child_4);
		child_2._children.push_back(child_3);
		auto parent_1 = tree::Node{};
		parent_1._children.push_back(child_1);
		parent_1._children.push_back(child_2);
		auto res = tree::traverse_tree_post_order(parent_1);
		auto vec = std::vector<tree::Node>{child_1, child_4, child_3, child_2, parent_1};
		REQUIRE(res == vec);
	}	
	SECTION("Test traverse_tree_breadth_first function"){
		auto child_1 = tree::Node{};
		child_1._properties._type = "foo";

		auto child_2 = tree::Node{};
		child_2._properties._type = "bar";

		auto child_3 = tree::Node{};
		child_3._properties._type = "baz";

		auto child_4 = tree::Node{};
		child_4._properties._type = "faz";
		child_3._children.push_back(child_4);

		child_2._children.push_back(child_3);
		auto parent_1 = tree::Node{};
		parent_1._children.push_back(child_1);
		parent_1._children.push_back(child_2);
		auto res = tree::traverse_tree_breadth_first(parent_1);
		auto vec = std::vector<tree::Node>{parent_1, child_1, child_2, child_3, child_4};
		REQUIRE(res == vec);
	}	
	SECTION("Test create_node function"){
		auto child_1 = tree::Node{};
		child_1._properties._type = "foo";
		auto child_2 = tree::Node{};
		child_2._properties._type = "bar";
		auto parent_1 = tree::Node{};
		parent_1._children.push_back(child_1);
		parent_1._children.push_back(child_2);
		auto properties = tree::NodeProperties{};	
		auto vec = std::vector<tree::Node>{child_1, child_2};
		auto res_1 = tree::create_node(properties, vec);
		REQUIRE(res_1 == parent_1);
	}
	SECTION("Test create_full_tree function"){
		auto parent_1 = tree::Node{{}, {{},{},{},{},2}};
	}
	SECTION("Test create_child function"){
		auto parent_1 = tree::Node{};
		auto vec = std::vector<tree::Node>{};
		auto parent_2 = tree::NodeProperties{{"function"},{},{},{"minus"},{},2};
		auto child_fun = std::bind(tree::create_node, parent_2, vec);
		create_child(parent_1, child_fun);
		REQUIRE(parent_1._children.at(0)._properties._type == "minus");
	}


}

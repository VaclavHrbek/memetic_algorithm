

#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/node_type.hpp>

TEST_CASE("node_type.hpp"){
	SECTION("Test plus function"){
		REQUIRE(node_type::plus(3,2) == 5);
		REQUIRE(node_type::plus(3.3,2.2) == 5.5);
	}
	SECTION("Test minus function"){
		REQUIRE(node_type::minus(3,2) == 1);
		REQUIRE(node_type::minus(3,5) == -2);
		REQUIRE(node_type::minus(3.3,5.5) == -2.2);
	}
	SECTION("Test plus_factory function"){
		auto a = node_type::plus_factory();
		auto b = tree::NodeProperties{{"function"},{},{},{"plus"},{},2};
		REQUIRE(a == b);
	}
	SECTION("Test plus_factory function"){
		auto a = node_type::minus_factory();
		auto b = tree::NodeProperties{{"function"},{},{},{"minus"},{},2};
		REQUIRE(a == b);
	}
	SECTION("Test create_full_tree function"){
		//auto root = node_type::create_full_tree(2, node_type::select_default_function, node_type::select_default_terminal);
		//auto parent_1 = tree::create_node(tree::NodeProperties{{"function"},{},{},{"plus"},{},2}, {});
		//auto child_1 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		//auto child_2 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		//tree::add_child(parent_1, child_1);
		//tree::add_child(parent_1, child_2);
		//REQUIRE(root == parent_1);

		//auto root = node_type::create_full_tree(3, node_type::select_default_function, node_type::select_default_terminal);
		auto parent_1 = tree::create_node(tree::NodeProperties{{"function"},{},{},{"plus"},{},2}, {});
		auto child_1 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		auto child_2 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		auto child_3 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		auto child_4 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		auto child_5 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		auto child_6 = tree::create_node(tree::NodeProperties{{"terminal"},{},{},{"r"},{},0}, {});
		tree::add_child(child_1, child_3);
		tree::add_child(child_1, child_4);
		tree::add_child(child_2, child_5);
		tree::add_child(child_2, child_6);
		tree::add_child(parent_1, child_1);
		tree::add_child(parent_1, child_2);
		//std::cout << root._children.at(0);
		//std::cout << root._children.at(1);
		//std::cout << root._children.at(0)._children.at(0);
		//std::cout << root._children.at(0)._children.at(1);
		//std::cout << root._children.at(1);
		//REQUIRE(root == parent_1);
	}

}



#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include "genetic_program.hpp"
#include "city.hpp"
#include "genetic_program.cpp"

std::shared_ptr<Node> make_tree_binary(){

	auto t1 = std::make_shared<Node>();
	t1->type = Terminals::X;
	t1->value = 1;
	auto t2 = std::make_shared<Node>();
	t2->type = Terminals::X;
	t2->value = 2;
	auto t3 = std::make_shared<Node>();
	t3->type = Terminals::X;
	t3->value = 3;
	auto t4 = std::make_shared<Node>();
	t4->type = Terminals::X;
	t4->value = 4;
	auto t5 = std::make_shared<Node>();
	t5->type = Terminals::X;
	t5->value = 5;
	auto t6 = std::make_shared<Node>();
	t6->type = Terminals::X;
	t6->value = 6;
	auto t7 = std::make_shared<Node>();
	t7->type = Terminals::X;
	t7->value = 7;
	auto t8 = std::make_shared<Node>();
	t8->type = Terminals::X;
	t8->value = 8;

	auto n1 = std::make_shared<Node>();
	n1->children.push_back(t1);
	n1->children.push_back(t2);
	n1->type = Functions::Addition;
	n1->value = 9;
	auto n2 = std::make_shared<Node>();
	n2->children.push_back(t3);
	n2->children.push_back(t4);
	n2->type = Functions::Addition;
	n2->value = 10;
	auto n3 = std::make_shared<Node>();
	n3->children.push_back(t5);
	n3->children.push_back(t6);
	n3->type = Functions::Addition;
	n3->value = 11;
	auto n4 = std::make_shared<Node>();
	n4->children.push_back(t7);
	n4->children.push_back(t8);
	n4->type = Functions::Addition;
	n4->value = 12;
	auto n5 = std::make_shared<Node>();
	n5->children.push_back(n1);
	n5->children.push_back(n2);
	n5->type = Functions::Addition;
	n5->value = 13;
	auto n6 = std::make_shared<Node>();
	n6->children.push_back(n3);
	n6->children.push_back(n4);
	n6->type = Functions::Addition;
	n6->value = 14;
	auto n7 = std::make_shared<Node>();
	n7->children.push_back(n5);
	n7->children.push_back(n6);
	n7->type = Functions::Addition;
	n7->value = 15;
	return n7;
}

TEST_CASE("Genetic program hpp "){
	auto root = make_tree_binary();	
	std::vector<double> out{1, 2, 9, 3, 4, 10, 13, 5, 6, 11, 7, 8, 12, 14, 15};
	Node n1{{Terminals::X}, {}, 0};
	Node n2{{Terminals::Y}, {}, 0};
	auto  a1 = std::make_shared<Node>(n1);
	auto  b1 = std::make_shared<Node>(n2);
	Node n3{{Functions::Addition}, {a1, b1}, -1};
	auto  c1 = std::make_shared<Node>(n3);
	Node n4{{Functions::Subtraction}, {a1, b1}, -1};
	auto  c2 = std::make_shared<Node>(n4);
	Node n5{{Functions::Multiplication}, {a1, b1}, -1};
	auto  c3 = std::make_shared<Node>(n5);
	Node n6{{Functions::ProtDivision}, {a1, b1}, -1};
	auto  c4 = std::make_shared<Node>(n6);
	std::vector<std::shared_ptr<Node>> v1{a1, b1, c1};
	std::vector<std::shared_ptr<Node>> v2{a1, b1, c2};
	std::vector<std::shared_ptr<Node>> v3{a1, b1, c3};
	std::vector<std::shared_ptr<Node>> v4{a1, b1, c4};
	City city1{{1,2},{3,4},{}};
	City city2{{1,0},{3,4},{}};
	City city3{{3,4},{3,4},{}};
	SECTION("No class: "){
		CHECK(value(root) == 15);
		CHECK(post_order(root, value) == out);

		fill_initials_value(city1, v1);
		CHECK(v1.at(0)->value == 1);
		CHECK(v1.at(1)->value == 2);
		calculate_value_root_node(v1);
		CHECK(v1.at(2)->value == 3);
		calculate_value_root_node(v2);
		CHECK(v2.at(2)->value == -1);
		calculate_value_root_node(v3);
		CHECK(v3.at(2)->value == 2);
		calculate_value_root_node(v4);
		CHECK(v4.at(2)->value == 0.5);

		fill_initials_value(city2, v1);
		calculate_value_root_node(v4);
		CHECK(v4.at(2)->value == 1);

		CHECK(get_cout_functions() == 4);
		CHECK(get_cout_terminals() == 6);

		create_full_tree(2);

		CHECK(node_to_string(a1) == "( x )");
		CHECK(node_to_string(b1) == "( y )");
		CHECK(node_to_string(c1) == "( Addition )");
	}
	SECTION("Individual "){
		//std::vector<std::pair<double, double> v{{1,2},{1,0}, {3,4}};
		std::vector<City> cities{city1, city2, city3};
		Map map(cities, 0);	
		map.calculate_sum_n_nearest(1);
		Individual ind(c1);
		CHECK(ind.size() == 3);
		ind.calculate_fitness(map);
		CHECK(ind._fitness == Catch::Approx( 4.8284 ).epsilon( 0.01 ));
	}
	SECTION("GeneticProgram "){
		Individual ind1(c1);
		Individual ind2(c2);
		Individual ind3(c3);

	}
}

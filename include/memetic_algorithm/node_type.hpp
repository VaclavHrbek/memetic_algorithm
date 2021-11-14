#pragma once

#include <memetic_algorithm/tree.hpp>
#include <iostream>

namespace node_type{
	template<typename T, typename U>
		auto plus(T a, U b){
			return a + b;
		}
	template<typename T, typename U>
		auto minus(T a, U b){
			return a - b;
		}
	auto X();
	auto Y();

	//struct NodeProperties{
	//	std::string _type_node;
	//	std::size_t _depth;
	//	std::size_t _position;
	//	std::string _type;
	//	double _val;	
	//	std::size_t _arity = 0;
	//	bool operator== (const NodeProperties& rhs) const;
	//};
	tree::NodeProperties plus_factory();
	tree::NodeProperties minus_factory();
	tree::NodeProperties addition_factory();
	tree::NodeProperties division_factory();
	tree::NodeProperties r_factory();
	tree::NodeProperties x_factory();
	tree::NodeProperties y_factory();
	tree::NodeProperties default_terminal_factory();
	tree::NodeProperties default_function_factory();

	tree::NodeProperties select_function(std::size_t num);
	tree::NodeProperties select_default_function();

	tree::NodeProperties select_terminal(std::size_t num);
	tree::NodeProperties select_default_terminal();

	template<typename T, typename U,typename X>
		auto create_full_tree(std::size_t depth, T function_fun, U terminal_fun){
			auto vec_node = std::vector<std::vector<X>>(depth - 1);	
			for(auto& i : vec_node){
				tree::create_node(function_fun, {});
			}
	}



}

#pragma once 

#include <stack>
#include <iostream>
#include <queue>
#include <cmath>
#include <tuple>

#include <memetic_algorithm/node.hpp>
#include <memetic_algorithm/collection.hpp>

class Tree {
	public: 
		Tree(std::size_t size);
		std::shared_ptr<Node> root();
	private:
		std::shared_ptr<Node> _root;
		std::shared_ptr<Node> create_full_tree(std::size_t depth);
};

Collection<std::shared_ptr<Node>> create_collection_from_tree(std::shared_ptr<Node> root);

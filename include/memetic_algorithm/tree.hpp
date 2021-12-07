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
		//Tree() = default;
		Tree(std::size_t size);
		std::size_t size() const;
		Node& at(std::size_t i);
		void print () const;
		Collection<Node> _tree;
	private:
		void create_full_tree(std::size_t depth);
		void fill_tree_with_random_values();

};

std::tuple<Tree, Tree> crossover(Tree t1, Tree t2, std::size_t p);
Tree mutate(Tree t, std::size_t p);



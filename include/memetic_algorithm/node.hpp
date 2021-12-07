#pragma once

#include <memory>

#include <memetic_algorithm/node_value.hpp>

class Node {
	public:
		Node() = default;
		Node(NodeValue val,std::size_t num) : _value(val), _number(num) {};
		std::size_t _number;
		NodeValue _value;
};

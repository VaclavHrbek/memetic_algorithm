#pragma once

#include <memory>

#include <memetic_algorithm/node_value.hpp>

class Node {
	public:
		Node() = default;
		Node(NodeValue val) : _value(val) {};
		std::shared_ptr<Node> _left;
		std::shared_ptr<Node> _right;
		NodeValue _value;
};

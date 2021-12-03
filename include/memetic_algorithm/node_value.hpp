#pragma once

#include <string>
#include <random>

static std::random_device r;

class NodeValue{
	public:
		NodeValue(std::string t) : type{t} {};
		std::string type;
		std::string value;
		double num_value;
	private:
};

std::string random_function();
std::string random_terminal();

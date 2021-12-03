#pragma once

#include <string>
#include <memory>
#include <stack>
#include <limits>

#include <memetic_algorithm/collection.hpp>
#include <memetic_algorithm/map.hpp>
#include <memetic_algorithm/node.hpp>

class Fitness {
	public:
		Fitness();
		void calculate_fitness(Collection<std::shared_ptr<Node>>& col);
		double value();
	private:
		void calculate_value();
		Map _map;
		double _value;
		
};

double return_terminal_value(std::tuple<double,double,double>& val, std::string s);
double fill_numerical_values(std::tuple<double,double,double>& val,
		Collection<std::shared_ptr<Node>>& col);

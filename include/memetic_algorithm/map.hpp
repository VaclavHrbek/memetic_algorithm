#pragma once

#include <iostream>
#include <cmath>
#include <tuple>
#include <limits>

#include <memetic_algorithm/collection.hpp>
#include <memetic_algorithm/city.hpp>

class Map {
	public:
		Map() = default;
		Map(std::size_t num);
		City at(int indx);
		int size();	
		void push_back(City c);
		void print_map();
	private:
		Collection<City> _map;
		void calculate_n_nearest_cities(std::size_t n);
};

struct Data {
	std::size_t size();
	std::vector<double> x{1,2,3,4,5,6,7,8,9,0};
	std::vector<double> y{1,2,3,4,5,6,7,8,9,0};
};

double calculate_distance(const City& a, const City& b);




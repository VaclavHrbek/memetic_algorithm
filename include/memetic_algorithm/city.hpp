#pragma once

#include <tuple>
#include <iostream>

class City {
	public:
		City(double x, double y);
		//TODO replace double with some tuple
		double _x;
		double _y;
		double _sum = 0;
		std::tuple<double, double, double> get_values();
		void print_city();
	private:
};

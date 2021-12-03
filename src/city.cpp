#include <memetic_algorithm/city.hpp>

City::City(double x, double y){
	_x = x;
	_y = y;
}

std::tuple<double, double, double> City::get_values(){
	return std::make_tuple(_x, _y, _sum);
}

void City::print_city(){
	std::cout << "x: " << _x;
	std::cout << " ,y: " << _y;
	std::cout << " ,sum: " << _sum;
	std::cout << '\n';
}


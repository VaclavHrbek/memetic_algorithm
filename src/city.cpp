#include <memetic_algorithm/city.hpp>

double calculate_distance_between_points(double x1, double y1, double x2, double y2){
	return std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
}

double calculate_route(const std::vector<City>& map){
	double val = 0; 
	for(std::size_t i = 0; i != (map.size()-1); ++i){
		val += calculate_distance_between_points(
				map.at(i)._cartesian_coordinate.x,
				map.at(i)._cartesian_coordinate.y,
				map.at(i+1)._cartesian_coordinate.x,
				map.at(i+1)._cartesian_coordinate.y);
	}
	return val;
}

double calculate_polar_angle(double x, double y){
	if(x == 0){
		return 0;
	}
	return std::atan(y / x);
}

City::City(double x, double y) : _cartesian_coordinate{x, y}{
	calculate_polar_coordinate();
}

void City::calculate_polar_coordinate(){
	_polar_coordinate.r = calculate_distance_between_points(
			_begin_coordinate.x, 
			_begin_coordinate.y, 
			_cartesian_coordinate.x, 
			_cartesian_coordinate.y
			);
	_polar_coordinate.alfa = calculate_polar_angle(
			_cartesian_coordinate.x, 
			_cartesian_coordinate.y
			);
}
Map::Map(std::vector<City> v, std::size_t n) : _map{v}, _num_of_cities{n} {
	calculate_sum_n_nearest(_num_of_cities);
};

Map::Map(std::vector<std::pair<double, double>> xy, std::size_t n) : _num_of_cities{n} {
	for(auto& i : xy){
		_map.emplace_back(i.first, i.second);
	}
	calculate_sum_n_nearest(_num_of_cities);
}

std::vector<double> make_vector_of_distances_from_point(std::vector<CartesianCoordinate>& coord, 
		double x, double y){
	std::vector<double> out;
	for(auto& el : coord){
		out.emplace_back(calculate_distance_between_points(el.x, el.y, x, y));
	}
	return out;	
}

std::vector<double> find_n_smallest_elem_in_vector(std::vector<double> vec, std::size_t n){
	std::vector<double> out;
	for(std::size_t i = 0; i != n; ++i){
		auto elem = std::min_element(vec.begin(), vec.end());
		out.emplace_back(*elem);
		vec.erase(elem);	
		}
	return out;
}

void calculate_sum_n_nearest_for_city(City& city, int n, 
		std::vector<CartesianCoordinate> car_coor_vec){
	auto vec1 = make_vector_of_distances_from_point(
			car_coor_vec, 
			city._cartesian_coordinate.x, 
			city._cartesian_coordinate.y
			);

	auto vec2 = find_n_smallest_elem_in_vector(
			vec1, n);
	city._sum_n = std::accumulate(vec2.begin(), vec2.end(), 0.0);

}

void Map::calculate_sum_n_nearest(std::size_t n){
	try{
		if(n > _map.size()){
			throw std::out_of_range("The n nearest cities is bigger than number of cities in map");
		}
		std::vector<CartesianCoordinate> car_coor_vec;
		for(auto& el : _map){
			car_coor_vec.emplace_back(el._cartesian_coordinate);
		}

		for(auto& city : _map){
			calculate_sum_n_nearest_for_city(city, n+1, car_coor_vec);
		}
	}
	catch(std::out_of_range& e){
		throw e.what();
	}

}


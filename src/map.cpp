#include <memetic_algorithm/map.hpp>

// num is the the number of cities that is used to calculate sum
Map::Map(std::size_t num){
	auto d = Data();
	Collection<City> m;
	for(std::size_t i = 0; i != d.size(); i++){
		m.push_back(City(d.x.at(i), d.y.at(i)));
	}
	_map = m;
	calculate_n_nearest_cities(num);
}
	

City Map::at(int indx){
	return _map.at(indx);
}

void Map::print_map(){
	for(std::size_t i = 0; i != _map.size(); i++){
		_map.at(i).print_city();
	}
}

void Map::calculate_n_nearest_cities(std::size_t n){
	for(std::size_t i= 0; i != _map.size(); i++){
		Collection<std::tuple<City, double>> new_coll;
		for(std::size_t a = 0; a != _map.size(); a++){
			auto d = calculate_distance(_map.at(i), _map.at(a));
			new_coll.push_back(std::make_tuple(_map.at(a), d));
		}
		Collection<std::tuple<City, double>> final_coll;
		for(std::size_t o = 0; o != n + 1; o++){
			double lowest = std::numeric_limits<double>::max();
			int in = 0;
			for(std::size_t e = 0; e != new_coll.size(); e++){
				if(lowest > std::get<1>(new_coll.at(e))){
					lowest = std::get<1>(new_coll.at(e));
					in = e;
				}
			}
			final_coll.push_back(new_coll.at(in));
			new_coll.remove(in);
		}
		double fin = 0;
		for(std::size_t a = 0; a != final_coll.size(); a++){
			fin += std::get<1>(final_coll.at(a));
		}
		_map.at(i)._sum = fin;
	}
}

int Map::size(){
	return _map.size();
	}

void Map::push_back(City c){
	_map.push_back(c);
}

std::size_t Data::size(){
	return x.size();
}

double calculate_distance(const City& a, const City& b){
	return std::sqrt(std::pow((a._x - b._x), 2) + std::pow((a._y - b._y), 2));
}

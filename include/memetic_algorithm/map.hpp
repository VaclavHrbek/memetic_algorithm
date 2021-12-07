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

// min lenght is 12.72...
//struct Data {
//	std::size_t size();
//	std::vector<double> x{1,2,3,4,5,6,7,8,9,0};
//	std::vector<double> y{1,2,3,4,5,6,7,8,9,0};
//};
// min lenght is 33523
struct Data {
	std::size_t size();
	std::vector<double> x{
		6734 ,
			 2233 ,
			 5530 ,
			 401 ,
			 3082 ,
			 7608 ,
			 7573 ,
			 7265 ,
			 6898 ,
			 1112 ,
			 5468 ,
			 5989 ,
			 4706 ,
			 4612 ,
			 6347 ,
			 6107 ,
			 7611 ,
			 7462 ,
			 7732 ,
			 5900 ,
			 4483 ,
			 6101 ,
			 5199 ,
			 1633 ,
			 4307 ,
			 675 ,
			 7555 ,
			 7541 ,
			 3177 ,
			 7352 ,
			 7545 ,
			 3245 ,
			 6426 ,
			 4608 ,
			 23 ,
			 7248 ,
			 7762 ,
			 7392 ,
			 3484 ,
			 6271 ,
			 4985 ,
			 1916 ,
			 7280 ,
			 7509 ,
			 10 ,
			 6807 ,
			 5185 ,
			 3023 };

	std::vector<double> y{
		1453,
			10,
			1424,
			841,
			1644,
			4458,
			3716,
			1268,
			1885,
			2049,
			2606,
			2873,
			2674,
			2035,
			2683,
			669,
			5184,
			3590,
			4723,
			3561,
			3369,
			1110,
			2182,
			2809,
			2322,
			1006,
			4819,
			3981,
			756,
			4506,
			2801,
			3305,
			3173,
			1198,
			2216,
			3779,
			4595,
			2244,
			2829,
			2135,
			140,
			1569,
			4899,
			3239,
			2676,
			2993,
			3258,
			1942};

};

double calculate_distance(const City& a, const City& b);




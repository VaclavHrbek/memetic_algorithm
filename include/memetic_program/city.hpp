#pragma once

#include <vector>
#include <cmath>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <algorithm>
#include <numeric>

struct BeginCoordinates {
	double x = 0;
	double y = 0;
};

struct CartesianCoordinate {
	double x;
	double y;
};
struct PolarCoordinate {
	double r;
	double alfa;
};

struct City{
	CartesianCoordinate _cartesian_coordinate;
	PolarCoordinate _polar_coordinate;
	BeginCoordinates _begin_coordinate;
	double _sum_n;

	void calculate_polar_coordinate();
	City(double x, double y);	
	City(CartesianCoordinate car_coor, PolarCoordinate pol_coor, double sum) : _cartesian_coordinate{car_coor}, _polar_coordinate{pol_coor}, _sum_n{sum} {}
};

class Map{
	std::size_t _num_of_cities;
	public:
	std::vector<City> _map;
	
	Map(std::vector<City> v, std::size_t n);	
	Map(std::vector<std::pair<double, double>> xy, std::size_t n);
	void calculate_sum_n_nearest(std::size_t n);
};

double calculate_route(const std::vector<City>& map);
void calculate_sum_n_nearest_for_city(City& city, int n, std::vector<double> car_coor_vec);
double calculate_distance_between_points(double x1, double y1, double x2, double y2);
double calculate_polar_angle(double x1, double y1);
std::vector<double> find_n_smallest_elem_in_vector(std::vector<double> vec, std::size_t n);
std::vector<double> make_vector_of_distances_from_point(std::vector<CartesianCoordinate>& coord, 
		double x, double y);


#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/city.hpp>

TEST_CASE("No class"){
	std::vector<double> vec_double{ 1, 2, 3, 4, 4, 3.1, 8.5, 2.1, 9.6, 0.1, 5.2 };

	SECTION("Function: calculate_distance_between_points"){
		CHECK( calculate_distance_between_points(0,0,2,2) == Catch::Approx( 2.828 ).epsilon(0.01));
		CHECK( calculate_distance_between_points(1,0,1,2) == Catch::Approx( 2 ).epsilon(0.01));
		CHECK( calculate_distance_between_points(2,2,0,0) == Catch::Approx( 2.828 ).epsilon(0.01));
		CHECK( calculate_distance_between_points(3,2,5,7) == Catch::Approx( 5.385 ).epsilon(0.01));
		CHECK( calculate_distance_between_points(5,7,3,2) == Catch::Approx( 5.385 ).epsilon(0.01));
	}

	SECTION("Function: calculate_polar_angle"){
		CHECK( calculate_polar_angle(2,2) == Catch::Approx( 0.785 ).epsilon(0.01));
		CHECK( calculate_polar_angle(0,0) == Catch::Approx( 0 ));
		CHECK( calculate_polar_angle(5,7) == Catch::Approx( 0.951 ).epsilon(0.01));
		CHECK( calculate_polar_angle(3,2) == Catch::Approx( 0.588 ).epsilon(0.01));
	}

	SECTION("Function: find_n_smallest_elem_in_vec"){
		std::vector<double> a = {0.1, 1};
		std::vector<double> b = {0.1, 1, 2};
		std::vector<double> c = {0.1, 1, 2, 2.1, 3};
		CHECK(find_n_smallest_elem_in_vector(vec_double, 2) == a);
		CHECK(find_n_smallest_elem_in_vector(vec_double, 3) == b);
		CHECK(find_n_smallest_elem_in_vector(vec_double, 5) == c);
	}

	SECTION("Function: make_vector_of_distances"){
		double x = 3;
		double y = 6;
		std::vector<CartesianCoordinate> vec{{1,1}, {2,2}, {4,4}, {5,7}, {3,2}, {0,0}, {3, 6}, {5, 2}};
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(0) == Catch::Approx(5.385).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(1) == Catch::Approx(4.123).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(2) == Catch::Approx(2.236).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(3) == Catch::Approx(2.236).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(4) == Catch::Approx(4).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(5) == Catch::Approx(6.708).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(6) == Catch::Approx(0).epsilon(0.01));
		CHECK(make_vector_of_distances_from_point(vec, x, y).at(7) == Catch::Approx(4.472).epsilon(0.01));
	}

	SECTION("Function: calculate_route"){
		City city1{{1,2},{3,4},{}};
		City city2{{1,0},{3,4},{}};
		City city3{{3,4},{3,4},{}};
		std::vector<City> cities{city1, city2, city3};
		CHECK(calculate_route(cities) == Catch::Approx( 6.472 ).epsilon( 0.01));

	}
}

TEST_CASE("struct City"){
	SECTION("Function member: calculate_polar_coordinates"){
		SECTION("Normal functionality"){
			City a{2,2};
			a.calculate_polar_coordinate();
			CHECK(a._polar_coordinate.r == Catch::Approx( 2.828).epsilon(0.01));
			CHECK(a._polar_coordinate.alfa == Catch::Approx(0.785).epsilon(0.01));
		}
		SECTION("Bad initialization"){
			// TODO: Manage the bad intialization of City
			City a{0,0};
			a.calculate_polar_coordinate();
			CHECK(a._polar_coordinate.r == 0);
			CHECK(a._polar_coordinate.alfa == 0);
		}
	}
}
TEST_CASE("class Map"){

	std::vector<std::pair<double, double>> vec{{1,1}, {2,2}, {4,4}, {5,7}, {3,2}, {0,0}, {3, 6}, {5, 2}};
	Map m(vec, 0);

	SECTION("Initialization "){
		CHECK(m._map.at(0)._cartesian_coordinate.x == 1);
		CHECK(m._map.at(0)._cartesian_coordinate.y == 1);
	}
	SECTION("Function memeber: calculate_sum_n_nearest"){
		CHECK_THROWS(m.calculate_sum_n_nearest(10));
		m.calculate_sum_n_nearest(2);
		CHECK(m._map.at(0)._sum_n == Catch::Approx( 2.828).epsilon(0.01));
		CHECK(m._map.at(2)._sum_n == Catch::Approx( 4.472).epsilon(0.01));
		CHECK(m._map.at(5)._sum_n == Catch::Approx( 4.242).epsilon(0.01));
		m.calculate_sum_n_nearest(3);
		CHECK(m._map.at(0)._sum_n == Catch::Approx( 5.064).epsilon(0.01));
		CHECK(m._map.at(2)._sum_n == Catch::Approx( 6.708).epsilon(0.01));
		CHECK(m._map.at(5)._sum_n == Catch::Approx( 7.848).epsilon(0.01));
	}

}
//CHECK( 
	




#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <iostream>

#include <memetic_algorithm/functions_and_terminals.hpp>

using namespace GP;

TEST_CASE("No class functions"){
	SECTION("Random int"){
		auto n = random_int(1,1);
		CHECK(n == 1);
	}
}

TEST_CASE("Function class "){
	SECTION("Plus"){
	}
	SECTION("Random init function"){
		auto a = Function();
		CHECK(a.val().size() > 0);
	}
	SECTION("Plus operator"){
		auto a = Function("plus");
		auto res = a(2, 3);
		CHECK(res == 5);
	}
	SECTION("Minus operator"){
		auto a = Function("minus");
		auto res = a(2, 3);
		CHECK(res == -1);
	}
}

TEST_CASE("Terminal class "){
	SECTION("x"){
		auto a = Terminal("x");
		CHECK(a.val() == "x");
		a._num_val = 3;
		CHECK(a() == 3);
	}

}

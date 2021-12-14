#include <memetic_algorithm/node_value.hpp>

std::string random_function(){
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int i = uniform_dist(e1);
	switch(i){
		case 1 :
			return "plus";
		case 2 :
			return "minus";
		case 3 :
			return "multiplication";
		case 4 :
			return "division";
		case 5 :
			return "past_right";
		case 6 :
			return "past_left";
		default :
			return "plus";
	}

	}
std::string random_terminal(){
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 4);
    int i = uniform_dist(e1);
	switch(i){
		case 1 :
			return "x";
		case 2 :
			return "y";
		case 3 :
			return "sum";
		case 4 :
			return "rand";
		default :
			return "x";
	}
	}

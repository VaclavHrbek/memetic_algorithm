#include <memetic_algorithm/node_value.hpp>

std::string random_function(){
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 4);
    int i = uniform_dist(e1);
	switch(i){
		case 1 :
			return "plus";
		case 2 :
			return "minus";
		case 3 :
			return "addition";
		case 4 :
			return "division";
		default :
			return "plus";
	}

	}
std::string random_terminal(){
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 3);
    int i = uniform_dist(e1);
	switch(i){
		case 1 :
			return "x";
		case 2 :
			return "y";
		case 3 :
			return "sum";
		default :
			return "x";
	}
	}

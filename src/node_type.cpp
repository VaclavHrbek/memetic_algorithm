#include <memetic_algorithm/node_type.hpp>


namespace node_type{

	tree::NodeProperties plus_factory(){
		return {{"function"},
			{},
			{},
			{"plus"},
			{},
			2};
	}
	tree::NodeProperties minus_factory(){
		return {{"function"},
			{},
			{},
			{"minus"},
			{},
			2};
	}
	tree::NodeProperties addition_factory(){
		return {{"function"},
			{},
			{},
			{"addition"},
			{},
			2};
	}
	tree::NodeProperties division_factory(){
		return {{"function"},
			{},
			{},
			{"division"},
			{},
			2};
	}
	tree::NodeProperties x_factory(){
		return {{"terminal"},
			{},
			{},
			{"x"},
			{},
			0};
	}
	tree::NodeProperties y_factory(){
		return {{"terminal"},
			{},
			{},
			{"y"},
			{},
			0};
	}
	tree::NodeProperties r_factory(){
		return {{"terminal"},
			{},
			{},
			{"r"},
			{},
			0};
	}
	tree::NodeProperties default_terminal_factory(){
		return {{"terminal"},
			{},
			{},
			{"r"},
			{},
			0};
	}
	tree::NodeProperties default_function_factory(){
		return {{"function"},
			{},
			{},
			{"plus"},
			{},
			2};
	}
	tree::NodeProperties select_terminal(std::size_t num){
		switch(num){
			case 0:
				return x_factory();
			case 1:
				return y_factory();
			case 2: 
				return r_factory();
			default:
				return default_terminal_factory();
		}
	}
	tree::NodeProperties select_function(std::size_t num){
		switch(num){
			case 0:
				return plus_factory();
			case 1:
				return minus_factory();
			case 2: 
				return addition_factory();
			case 3:
				return division_factory();
			default:
				return default_function_factory();
		}
	}
	tree::NodeProperties select_default_function(){
		return select_function(-1);
	}
	tree::NodeProperties select_default_terminal(){
		return select_terminal(-1);
	}

}

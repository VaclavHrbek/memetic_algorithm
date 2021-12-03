#include <memetic_algorithm/fitness.hpp>

Fitness::Fitness(){
	std::size_t n = 2;
	auto m = Map(n);
	_map = m;
}

double Fitness::value(){
	return _value;
}

void Fitness::calculate_fitness(Collection<std::shared_ptr<Node>>& col){
	_value = 0;
	Collection<std::tuple<City, double>> route{};
	for(std::size_t i = 0; i !=  _map.size(); i++){
		auto val = _map.at(i).get_values();
		//std::cout << "val.0 " << std::get<0>(val) << '\n';
		//std::cout << "val.1 " << std::get<1>(val) << '\n';
		//std::cout << "val.2 " << std::get<2>(val) << '\n';
		auto score = fill_numerical_values(val, col);
		route.push_back(std::make_tuple(_map.at(i), score));
	}
	// calculate route
	double lowest = std::numeric_limits<double>::max();
	int in = 0;
	for(std::size_t e = 0; e != route.size(); e++){
		if(lowest > std::get<1>(route.at(e))){
			lowest = std::get<1>(route.at(e));
			in = e;
		}
	}
	auto start_city = std::get<0>(route.at(in));	
	route.remove(in);
	double distance = 0;
	while(not route.empty()){
	 lowest = std::numeric_limits<double>::max();
	 in = 0;
		for(std::size_t e = 0; e != route.size(); e++){
			if(lowest > std::get<1>(route.at(e))){
				lowest = std::get<1>(route.at(e));
				in = e;
			}
		}
		//std::cout << "route: ";
		//std::cout << std::get<1>(route.at(in));
		//std::cout << '\n';
		distance += calculate_distance(start_city, std::get<0>(route.at(in)));
		start_city = std::get<0>(route.at(in));
		route.remove(in);
	}
	//std::cout << "Distance: ";
	//std::cout << distance << '\n';
	_value = distance;
	
}

double return_terminal_value(std::tuple<double,double,double>& val, std::string s){
	if(s == "x"){
		return std::get<0>(val);
	}
	else if(s == "y"){
		return std::get<1>(val);
	}
	else if(s == "sum"){
		return std::get<2>(val);
	}
	else{
		return 0;
	}
}

double fill_numerical_values(std::tuple<double,double,double>& val,
		Collection<std::shared_ptr<Node>>& col){
	std::stack<double> s;
	//std::cout << '\n';
	for(std::size_t i = (col.size() - 1); i != -1; i--){
		if(col.at(i)->_value.type == "function"){
			auto a = s.top();
			s.pop();
			auto b = s.top();
			s.pop();
			if(col.at(i)->_value.value == "plus"){
				s.push(a + b);	
				//std::cout << '(' << a << " + " << b << ')';
			}
			else if(col.at(i)->_value.value == "minus"){
				s.push(a - b);	
				//std::cout << '(' << a << " - " << b << ')';
			}
			else if(col.at(i)->_value.value == "addition"){
				s.push(a * b);	
				//std::cout << '(' << a << " * " << b << ')';
			}
			else if(col.at(i)->_value.value == "division"){
				//std::cout << '(' << a << " / " << b << ')';
				if(b == 0){
					s.push(a);
				}
				else{
					s.push(a / b);	
				}
			}
		}
		else if(col.at(i)->_value.type == "terminal"){
			////std::cout << "(";
			//std::cout << col.at(i)->_value.value;
			//std::cout << ": ";
			//std::cout << return_terminal_value(val, col.at(i)->_value.value);
			//std::cout << ")";
			s.push(return_terminal_value(val, col.at(i)->_value.value));
		}
	}
	return s.top();
}






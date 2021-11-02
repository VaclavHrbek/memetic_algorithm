
#include "genetic_program.hpp"

// TODO Thing if best should advance?

GeneticProgram::GeneticProgram(std::size_t pop_size, std::size_t init_depth, Map map) 
	: _map{map}{
		for(std::size_t i = 0; i != pop_size; ++i){
			_population.emplace_back(
					create_full_tree(init_depth));		
		}
	}

void GeneticProgram::mutation(){
	for(auto& i : _population){
		if(_population.size() >  _new_population.size()){
			if(get_random_int(0, 100) < 005){ // five is the mutation rate
				_new_population.emplace_back(mutate(i));
			}
		}
	}
}

void GeneticProgram::put_best_to_new(){
	_new_population.emplace_back(get_best());
}

Individual GeneticProgram::get_best(){
	Individual best = _population.at(0);
	for(auto& i : _population){
		if(i._fitness < best._fitness){
			best = i;
		}
	}
	return best;
}

void GeneticProgram::crossover(){
	while(_population.size() != _new_population.size()){
		for(auto& p : _population){
			//if(get_random_int(0, 100) < 050){ // fifty is the crossover rate
				auto new_vec = tree_crossover(
					turnament_selection(
						p,
						_population.at(get_random_int(0, _population.size() - 1))),
					turnament_selection(
						_population.at(get_random_int(0, _population.size() - 1)),
						_population.at(get_random_int(0, _population.size() - 1)))
					);
				for(auto& i : new_vec){
					if(_population.size() >  _new_population.size()){
						_new_population.push_back(i);
					}
				}
			//}
		}
	}
}

void GeneticProgram::swap_populations(){
	_population.swap(_new_population);
	_new_population.clear();
}

void GeneticProgram::print_population(){
	for(auto& i : _population){
		print_tree(i.root);
		std::cout << "fitness: " << i._fitness;
		std::cout << '\n';
	}
}

void GeneticProgram::calculate_fitness(){
	for(auto& i : _population){
		i.calculate_fitness(_map);
	}
}

void Individual::calculate_fitness(Map& map){
	std::vector<std::pair<City, double>> sequence;
	for(std::size_t i = 0; i != map._map.size(); ++i){
		auto vec_of_node_pointers = post_order(root, pointer);
		fill_initials_value(map._map.at(i), vec_of_node_pointers);
		calculate_value_root_node(vec_of_node_pointers);
		sequence.emplace_back(std::make_pair(map._map.at(i), root->value));
	}
	std::sort(sequence.begin(), sequence.end(), 
			[](auto a, auto b)
			{return a.second > b.second;});
	std::vector<City> route;
	for(auto& c : sequence){
		route.emplace_back(c.first);
	}
	_fitness = calculate_route(route);
}

std::size_t Individual::size(){
	return post_order(root, pointer).size();
}

double value(std::shared_ptr<Node> node){
	return node->value;
}

std::shared_ptr<Node> pointer(std::shared_ptr<Node> node){
	return node;
}

std::variant<Terminals, Functions> type(std::shared_ptr<Node> node){
	return node->type;
}

std::string node_to_string(std::shared_ptr<Node> node){
	if(std::holds_alternative<Functions>(node->type)){
		if(std::get<Functions>(node->type) == Functions::Addition){
			return "( Addition )";
		}
		if(std::get<Functions>(node->type) == Functions::Subtraction){
			return "( Subtraction )"; 
		}
		if(std::get<Functions>(node->type) == Functions::Multiplication){
			return "( Multiplication )";
		}
		if(std::get<Functions>(node->type) == Functions::ProtDivision){
			return "( Division )";
		}
		else{
			return "( Unknow )";
		}

	}
	if(std::holds_alternative<Terminals>(node->type)){
		if(std::get<Terminals>(node->type) == Terminals::X){
			return "( x )";
		}
		else if(std::get<Terminals>(node->type) == Terminals::Y){
			return "( y )";
		}
		else if(std::get<Terminals>(node->type) == Terminals::SumN){
			return "( n )";
		}
		else if(std::get<Terminals>(node->type) == Terminals::PolarR){
			return "( r )";
		}
		else if(std::get<Terminals>(node->type) == Terminals::PolarO){
			return "( O )";
		}
		else if(std::get<Terminals>(node->type) == Terminals::Random){
			return "( rand )";
		}else{
			return "( Unknow )";
		}
	}
	else{
		return "Nor Function or Terminal";
	}
}

void print_tree(std::shared_ptr<Node> root){
	auto arr = post_order(root, pointer);
	for(auto& a : arr){
		std::cout << node_to_string(a) << " ";
	}
	std::cout << '\n';
}

int get_cout_functions(){
	return static_cast<int>(Functions::Count);
}

int get_cout_terminals(){
	return static_cast<int>(Terminals::Count);
}

int get_random_int(int down, int upper){
	std::default_random_engine e1(rand_device());
	std::uniform_int_distribution<int> uniform_dist(down, upper);
	return uniform_dist(e1);
}

std::shared_ptr<Node> random_function(){
	auto i = get_random_int(0, get_cout_functions()-1);
	switch(i){
		case 0:
			return std::make_shared<Node>(Functions::Addition);
		case 1:
			return std::make_shared<Node>(Functions::Subtraction);
		case 2:
			return std::make_shared<Node>(Functions::Multiplication);
		case 3:
			return std::make_shared<Node>(Functions::ProtDivision);
		default:
			return std::make_shared<Node>(Functions::Addition);
	}
}
std::shared_ptr<Node> random_terminal(){
	auto i = get_random_int(0, get_cout_terminals()-1);
	switch(i){
		case 0:
			return std::make_shared<Node>(Terminals::X);
		case 1:
			return std::make_shared<Node>(Terminals::Y);
		case 2:
			return std::make_shared<Node>(Terminals::SumN);
		case 3:
			return std::make_shared<Node>(Terminals::PolarR);
		case 4:
			return std::make_shared<Node>(Terminals::PolarO);
		case 5:
			return std::make_shared<Node>(Terminals::Random);
		default:
			return std::make_shared<Node>(Terminals::Random);
	}
}

std::shared_ptr<Node> create_full_tree(std::size_t depth){
	auto root = random_function();
	std::stack<std::shared_ptr<Node>> s;
	s.push(root);
	for(std::size_t i = 0; i != depth; i++)
	{
		std::stack<std::shared_ptr<Node>> s_helper;
		while(not s.empty()){
			auto node = s.top(); 
			auto n1 = random_function();
			auto n2 = random_function();
			node->children.emplace_back(n1);
			node->children.emplace_back(n2);
			s_helper.push(n1);
			s_helper.push(n2);
			s.pop();
		}
		s.swap(s_helper);
	}
	while(not s.empty()){
		auto node = s.top(); 
		node->children.emplace_back(random_terminal());
		node->children.emplace_back(random_terminal());
		s.pop();
	}
	return root;
}


void calculate_value_root_node(std::vector<std::shared_ptr<Node>>& ind){
	for(auto& i : ind){
		if(std::holds_alternative<Functions>(i->type)){
			if(std::get<Functions>(i->type) == Functions::Addition){
				double val = 0;
				for(auto& ch : i->children){
					val += ch->value;
				}
				i->value = val;
				continue;
			}
			if(std::get<Functions>(i->type) == Functions::Subtraction){
				double val = i->children.at(0)->value;
				for(std::size_t x = 1; x != i->children.size(); ++x){
					val -= i->children.at(x)->value;
				}
				i->value = val;
				continue;
			}
			if(std::get<Functions>(i->type) == Functions::Multiplication){
				double val = 1;
				for(auto& ch : i->children){
					val *= ch->value;
				}
				i->value = val;
				continue;
			}
			if(std::get<Functions>(i->type) == Functions::ProtDivision){
				if(i->children.at(1)->value == 0){
					i->value = i->children.at(0)->value;
				}else{
					i->value = i->children.at(0)->value / i->children.at(1)->value;
				}
				continue;
			}
			else{
				i->value = 0;
			}
		}
	}
}

void fill_initials_value(const City& city, std::vector<std::shared_ptr<Node>>& ind){
	for(auto& i : ind){
		if(std::holds_alternative<Terminals>(i->type)){
			if(std::get<Terminals>(i->type) == Terminals::X){
				i->value = city._cartesian_coordinate.x;
				continue;
			}
			else if(std::get<Terminals>(i->type) == Terminals::Y){
				i->value = city._cartesian_coordinate.y;
				continue;
			}
			else if(std::get<Terminals>(i->type) == Terminals::SumN){
				i->value = city._sum_n;
				continue;
			}
			else if(std::get<Terminals>(i->type) == Terminals::PolarR){
				i->value = city._polar_coordinate.r;
				continue;
			}
			else if(std::get<Terminals>(i->type) == Terminals::PolarO){
				i->value = city._polar_coordinate.alfa;
				continue;
			}
			else if(std::get<Terminals>(i->type) == Terminals::Random){
				i->value = get_random_int(-100, 100);
				continue;
			}
			else{
				i->value = 0;
				continue;
			}
		}
	}
}

std::shared_ptr<Node> select_random_function_from_tree(std::shared_ptr<Node>& root){
	auto arr = post_order(root, pointer);
	std::shared_ptr<Node> node;
	do{
		node = arr.at(get_random_int(0, arr.size()-1));
	}
	while(node->children.empty());
	return node;
}

Individual mutate(Individual ind){
	Individual new_ind{create_full_tree(get_random_int(0,4))};
	if(ind.size() < 40){
		auto node = select_random_function_from_tree(ind.root);	
		node->children.at(get_random_int(0, node->children.size()-1)) = new_ind.root;
		return ind;
	}
	else{
		return new_ind;
	}
}

std::vector<Individual> tree_crossover(Individual ind1, Individual ind2){
	std::vector<Individual> out;
	if(ind1.size() > 40 || ind2.size() > 40){
		out.emplace_back(ind1);
		out.emplace_back(ind2);
	}
	else{
		std::shared_ptr<Node> node1 = select_random_function_from_tree(ind1.root);
		std::shared_ptr<Node> node2 = select_random_function_from_tree(ind2.root);
		//auto node3 = *node1;
		//*node1 = *node2;
		//*node2 = node3;
		std::swap(*node1, *node2);
		out.emplace_back(ind1);
		out.emplace_back(ind2);
	}
	return out;
}

Individual turnament_selection(Individual& ind1, Individual& ind2){
	if(ind1._fitness < ind2._fitness){
		return ind2;
	}else{
		return ind1;
	}
}

#include <memetic_algorithm/individual.hpp>

Individual::Individual(std::size_t size, std::size_t max_s){
	max_size = max_s;
	auto tree = Tree(size);	
	_nodes = create_collection_from_tree(tree.root());
	fill_individual_with_random_values();
	
}

void Individual::print_individual(){
	std::cout << "Fitness: " << fitness() << '\n';
	//for(int i = 0; i != _nodes.size(); i++){
		//std::cout << _nodes.at(i)->_value.value << '\n';
	//}
}

void Individual::fill_individual_with_random_values(){
	for(int i = 0; i != _nodes.size(); i++){
		if(_nodes.at(i)->_value.type == "function"){
			_nodes.at(i)->_value.value = random_function();
		}
		else{
			_nodes.at(i)->_value.value = random_terminal();
		}
	}
}

void Individual::calculate_fitness(){
	fit.calculate_fitness(_nodes);
}

double Individual::fitness(){
	return fit.value();
}

int Individual::size(){
	return _nodes.size();
}

std::shared_ptr<Node> Individual::at(int indx){
	return _nodes.at(indx);
}

Individual mutate(const Individual& old_ind){
	auto new_ind = old_ind;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, new_ind.size() - 1);
	int i = uniform_dist(e1);
	if(new_ind.at(i)->_value.type == "function"){
		new_ind.at(i)->_value.value = random_function();
	}
	else{
		new_ind.at(i)->_value.value = random_terminal();
	}
	return new_ind;
}

std::tuple<Individual, Individual> crossover(const Individual& old_ind1, const Individual& old_ind2){
	std::default_random_engine e1(r());
	auto ind1 = old_ind1;	
	auto ind2 = old_ind2;	

	do{
	auto n1 = ind1.at(0);
	auto n2 = ind2.at(0);
	int i1;
	int i2;
	do{
		std::uniform_int_distribution<int> uniform_dist1(0, ind1.size() - 1);
		i1 = uniform_dist1(e1);
		n1 = ind1.at(i1);
	}
	while(n1->_value.type != "function");

	do{
		std::uniform_int_distribution<int> uniform_dist2(0, ind2.size() - 1);
		i2 = uniform_dist2(e1);
		n2 = ind2.at(i2);
	}
	while(n2->_value.type != "function");
	auto m = ind2.at(i2);
	auto o = ind1.at(i1);
	std::swap(*ind2.at(i2), *ind1.at(i1));
	ind1.reload_nodes();
	ind2.reload_nodes();

	}
	while(ind1.size() >= ind1.max_size && ind2.size() > ind2.max_size);

	return std::make_tuple(ind1, ind2);
}

void Individual::reload_nodes(){
	_nodes = create_collection_from_tree(at(0));
}



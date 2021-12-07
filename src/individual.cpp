#include <memetic_algorithm/individual.hpp>

Individual::Individual(std::size_t size) : _tree(size) {
	calculate_fitness();
}

void Individual::print() const {
	std::cout << "Fitness: " << fitness() << '\n';
	std::cout << "Random number: " << rand_value() << '\n';
	_tree.print();
}

void Individual::calculate_fitness(){
	_fit.calculate_fitness(_tree._tree);
}

double Individual::fitness() const {
	return _fit.value();
}

double Individual::rand_value() const {
	return _fit._rand;
}

Individual mutate(Individual ind){
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(0, ind._tree.size() - 1);
		auto rand = uniform_dist(e1);
		ind._tree = mutate(ind._tree, rand);
		ind.calculate_fitness();
		return ind;
}

std::tuple<Individual, Individual> crossover(Individual ind1, Individual ind2){
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(0, ind1._tree.size() - 1);
		auto rand = uniform_dist(e1);
		auto tt = crossover(ind1._tree, ind2._tree, rand);
		ind1._tree = std::get<0>(tt);
		ind1.calculate_fitness();
		ind2._tree = std::get<1>(tt);
		ind2.calculate_fitness();
	return std::make_tuple(ind1, ind2);
}


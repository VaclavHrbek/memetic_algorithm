#include <memetic_algorithm/population.hpp>

void Population::create_population(std::size_t size_pop, std::size_t size_ind, std::size_t max_size){
	for(std::size_t i = 0; i != size_pop; i++){
		auto ind = Individual(size_ind, max_size);
		ind.calculate_fitness();
		_pop.push_back(ind);
	}
}

void Population::print_at(int indx){
	_pop.at(indx).print_individual();
}

std::size_t Population::size() const {
	return _pop.size();
}

void Population::push_back(Individual ind){
	ind.calculate_fitness();
	_pop.push_back(ind);
}

//mut_pr is from 0 to 1.
//cros_pr is from 0 to 1.
Population genetic_operation(Population& old_pop, double mut_pr, double cros_pr){
	auto new_pop = Population();
	std::size_t mut = old_pop.size() * mut_pr;
	std::size_t cros = old_pop.size() * cros_pr;
	while(new_pop.size() != old_pop.size()){
		for(std::size_t i = 0; i != old_pop.size(); i++){
			if(new_pop.size() == old_pop.size()){
				break;
			}
			std::default_random_engine e1(r());
			std::uniform_real_distribution<> uniform_dist(0.0, 1.0);
			auto rand = uniform_dist(e1);
			if(rand < mut_pr){
				new_pop.push_back(mutate(old_pop.turnamet_selection()));
			}
			else if(rand > mut_pr && rand < cros_pr){
				auto inds = crossover(old_pop.turnamet_selection(),
						old_pop.turnamet_selection());
				new_pop.push_back(std::get<0>(inds));
				if(new_pop.size() != old_pop.size()){
					new_pop.push_back(std::get<1>(inds));
				}
			}
			else{
				new_pop.push_back(old_pop.get_best());
			}
		}
	}
	return new_pop;
}
	
Individual Population::get_best(){
	double best = std::numeric_limits<double>::max();
	int indx = 0;
	for(std::size_t i = 0; i != _pop.size(); i++){
		if(best > _pop.at(i).fitness()){
			best = best > _pop.at(i).fitness();
			indx = i;
		}
	}
	return _pop.at(indx);

}

void Population::print_best(){
	auto best = get_best();
	std::cout << "Best individual from population: \n";
	best.print_individual();
}

Individual& Population::random_selection(){
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, _pop.size() - 1);
	int i = uniform_dist(e1);
	return _pop.at(i);
}

Individual Population::turnamet_selection(){
	auto ind1 = random_selection();
	auto ind2 = random_selection();
	return (ind1.fitness() > ind2.fitness()) ? ind1 : ind2;
}
	

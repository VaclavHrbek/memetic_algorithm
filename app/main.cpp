#include <memetic_algorithm/population.hpp>
#include <memetic_algorithm/map.hpp>

#include <iostream>

int main(){

	auto pop = Population();
	// pop_size is size of population
	// ind_init_size is initial size of individual
	// ind_max_size is maximal size of individual
	std::size_t pop_size = 50;
	std::size_t ind_init_size = 6;
	std::size_t ind_max_size = 15;

	pop.create_population(pop_size, ind_init_size, ind_max_size);
	for(std::size_t i = 0; i != 50; i++){
		pop.print_best();
		auto new_pop = genetic_operation(pop, 0.30, 0.65);
		pop = new_pop;
	}

	//
	//TODO Solve the pointer pointing to the same location.
	//auto ind = Individual(3);
	//ind.fill_individual_with_random_values();
	//ind.print_individual();
	//std::cout << "# # # # # # # # # # # #\n";
	//auto ind2 = mutate(ind);
	//ind2.print_individual();
	//std::cout << "# # # # # # # # # # # #\n";



}

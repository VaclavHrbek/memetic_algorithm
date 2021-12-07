#include <memetic_algorithm/population.hpp>
//#include <memetic_algorithm/map.hpp>
//#include <memetic_algorithm/individual.hpp>

//#include <memetic_algorithm/tree.hpp>

#include <iostream>

int main(){
	auto pop = Population();
	// pop_size is size of population
	std::size_t pop_size = 5;
	// ind_init_size is initial size of individual
	std::size_t ind_init_size = 3;

	pop.create_population(pop_size, ind_init_size);
	pop.print_best();
	//  loop is number of generation
	for(std::size_t i = 0; i != 300; i++){
		std::cout << "Number of generation: " << i << '\n';
		auto b1 = pop.get_best().fitness();
		auto new_pop = genetic_operation(pop, 0.30, 0.69);
		auto b2 = new_pop.get_best().fitness();
		if(b1 != b2){
			std::cout << "#############################################\n";
			std::cout << "New best\n";
			std::cout << "#############################################\n";
			new_pop.print_best();
		}
		pop = new_pop;
	}
}

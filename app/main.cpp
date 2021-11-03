#include <memetic_program/genetic_program.hpp>

int main(){
	std::vector<std::pair<double, double>> vec{
		std::make_pair(1,1),
		std::make_pair(2,2),
		std::make_pair(4,4),
		std::make_pair(5,2),
		std::make_pair(5,7),
		std::make_pair(3,6),
		std::make_pair(0,0)
	};
	Map map{vec, 2};
	GeneticProgram gp{50, 2, map};
	gp.calculate_fitness();
	auto best = gp.get_best();
	for(std::size_t i = 0; i != 25; ++i){
		gp.put_best_to_new();
		//gp.mutation();
		gp.crossover();
		gp.swap_populations();
		gp.calculate_fitness();

		best = gp.get_best();
		std::cout << "Fitness: " << best._fitness << '\n';
		print_tree(best.root);
	}


}

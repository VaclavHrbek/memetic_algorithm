#pragma once

#include <memetic_algorithm/individual.hpp>
#include <memetic_algorithm/node_value.hpp>
#include <memetic_algorithm/collection.hpp>

class Population {
	public:
		void create_population(std::size_t size_pop, std::size_t size_tree, std::size_t max_size);
		void print_at(int indx);
		void print_best();
		std::size_t size() const ;
		Individual turnamet_selection(); 
		void push_back(Individual ind);
		Individual get_best();
	private:
		Collection<Individual> _pop;	
		Individual& random_selection();
};

Population genetic_operation(Population& old_pop, double mut_pr, double cros_pr);



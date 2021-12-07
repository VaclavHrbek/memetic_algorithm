#pragma once

#include <memetic_algorithm/tree.hpp>
#include <memetic_algorithm/fitness.hpp>

class Individual {
	public:
		Individual(std::size_t size);
		void print() const ;
		void calculate_fitness();
		double fitness() const ;
		double rand_value() const;
		std::size_t size;
		Tree _tree;
	private:
		Fitness _fit;
};

Individual mutate(Individual ind);
std::tuple<Individual, Individual> crossover(Individual ind1, Individual ind2);

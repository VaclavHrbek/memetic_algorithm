#pragma once

#include <memetic_algorithm/tree.hpp>
#include <memetic_algorithm/node.hpp>
#include <memetic_algorithm/fitness.hpp>

class Individual {
	public:
		Individual(std::size_t size, std::size_t max_s);
		void print_individual();
		int size();
		std::shared_ptr<Node> at(int indx);
		void reload_nodes();
		void calculate_fitness();
		double fitness();
		std::size_t max_size;
	private:
		Fitness fit;
		Collection<std::shared_ptr<Node>> _nodes;
		void fill_individual_with_random_values();
};

Individual mutate(const Individual& old_ind);
std::tuple<Individual, Individual> crossover(const Individual& old_ind1, const Individual& old_ind2);

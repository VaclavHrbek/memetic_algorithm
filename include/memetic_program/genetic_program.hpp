#pragma once

#include <variant>
#include <memory>
#include <vector>
#include <stack>
#include <random>

#include "city.hpp"


enum class Functions{
	Addition,
	Subtraction,
	Multiplication,
	ProtDivision,
	Count
};

enum class Terminals{
	X,
	Y,
	SumN,
	PolarR,
	PolarO,
	Random,
	Count
};

static std::random_device rand_device;

struct Node{
	std::variant<Terminals, Functions> type;
	std::vector<std::shared_ptr<Node>> children;
	double value;
	Node() = default;
	Node(std::variant<Terminals, Functions> t, std::vector<std::shared_ptr<Node>> c, double v) :
		type{t}, children{c}, value{v} {};
	Node(std::variant<Terminals, Functions> t) :
		type{t} {};
};


class Individual{
	public: 
		Individual(std::shared_ptr<Node> n) : root{n} {};
		std::shared_ptr<Node> root;
		double _fitness;
		void calculate_fitness(Map& map);
		std::size_t size();
};

class GeneticProgram{
		Map _map;
		std::vector<Individual> _population;
		std::vector<Individual> _new_population;
	public:
		GeneticProgram(std::size_t pop_size, std::size_t init_depth, Map map); 
		void run();
		void print_population();
		void calculate_fitness();
		void mutation();
		void crossover();
		void swap_populations();
		void put_best_to_new();
		Individual get_best();
};

void fill_initials_value(const City& city, std::vector<std::shared_ptr<Node>>& ind);
void calculate_value_root_node(std::vector<std::shared_ptr<Node>>& ind);
int get_cout_functions();
int get_cout_terminals();
int get_random_int(int down, int upper);
std::shared_ptr<Node> create_full_tree(std::size_t depth);
std::string node_to_string(std::shared_ptr<Node> node);
void print_tree(std::shared_ptr<Node> root);
Individual mutate(Individual root);
std::vector<Individual> tree_crossover(Individual ind1, Individual ind2);
Individual turnament_selection(Individual& ind1, Individual& ind2);

double value(std::shared_ptr<Node> node);
std::shared_ptr<Node> pointer(std::shared_ptr<Node> node);
std::variant<Terminals, Functions> type(std::shared_ptr<Node> node);

template<typename OutFunction>
auto post_order(std::shared_ptr<Node> root, OutFunction function){
	std::vector<decltype(function(root))> out;
	if(root->children.empty()){
		out.emplace_back(function(root));
		return out;
	}
	std::stack<std::shared_ptr<Node>> s;
	s.push(root);

	auto it = out.begin();

	while(not s.empty()){
		auto curr = s.top();
		s.pop();

		it = out.insert(it, function(curr));
		for(auto& i : curr->children){
			s.push(i);
		}
	}
	return out;
}

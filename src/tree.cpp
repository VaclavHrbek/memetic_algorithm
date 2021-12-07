#include <memetic_algorithm/tree.hpp>

Tree::Tree(std::size_t size){
	create_full_tree(size);
	fill_tree_with_random_values();
}

std::size_t Tree::size() const {
	return _tree.size();
}

void Tree::create_full_tree(std::size_t depth){
	if(depth <= 1){
		_tree.push_back(Node(NodeValue("terminal"), 0));
		return;
	}

	std::size_t f_n_c = std::pow(2, depth-1) - 1;
	std::size_t i = 0;
	for(i = 0; i != f_n_c; i++){
		_tree.push_back(Node(NodeValue("function"), i));

	}
	for(std::size_t a = -1; a != f_n_c; a++){
		_tree.push_back(Node(NodeValue("terminal"), a + i + 1));
	}
}

void Tree::fill_tree_with_random_values(){
	for(int i = 0; i != _tree.size(); i++){
		if(_tree.at(i)._value.type == "function"){
			_tree.at(i)._value.value = random_function();
		}
		else{
			_tree.at(i)._value.value = random_terminal();
		}
	}
}

void Tree::print() const {
	for(std::size_t i = 0; i != _tree.size(); i++){
		std::cout << _tree.at(i)._value.value;
		std::cout << " id: ";
		std::cout << _tree.at(i)._number;
		std::cout << '\n';
	}
}

Node& Tree::at(std::size_t i){
	return _tree.at(i);
}

std::tuple<Tree, Tree> crossover(Tree t1, Tree t2, std::size_t p){
	std::stack<Node> s{};
	s.push(t1.at(p));
	while(not s.empty()){
		auto curr = s.top();
		s.pop();
		if(curr._value.type == "terminal"){
			std::swap(t1.at(curr._number), t2.at(curr._number));
		}
		else{
			s.push(t1.at((curr._number * 2) + 1));
			s.push(t2.at((curr._number * 2) + 2));
			std::swap(t1.at(curr._number), t2.at(curr._number));
		}
	}
	return std::make_tuple(t1, t2);
}

Tree mutate(Tree t, std::size_t p){
	if(t.at(p)._value.type == "function"){
		t.at(p)._value.value = random_function();
	}
	else{
		t.at(p)._value.value = random_terminal();
	}
	return t;
}


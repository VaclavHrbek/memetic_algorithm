#include <memetic_algorithm/tree.hpp>

Tree::Tree(std::size_t size){
	_root = create_full_tree(size);
}

std::shared_ptr<Node> Tree::root(){
	return _root;
}

std::shared_ptr<Node> Tree::create_full_tree(std::size_t depth){
	if(depth <= 1){
		auto t = NodeValue("terminal");
		auto root = Node(t);
		
		return std::make_shared<Node>(root);
	}

	std::queue<std::shared_ptr<Node>> s{};
	auto f = NodeValue("function");
	auto root = Node(f);
	auto root_ptr = std::make_shared<Node>(root);
	s.push(root_ptr);

	int f_n_c = std::pow(2, depth-2) - 1;
	
	//std::cout << f_n_c << '\n';
	int n_c = 0;

	while(not s.empty()){
		auto current = s.front();
		n_c++;
		if(n_c <= f_n_c){
			auto f2 = NodeValue("function");
			auto r = std::make_shared<Node>(f2);
			current->_right = r;
			s.push(r);
			auto f1 = NodeValue("function");
			auto l = std::make_shared<Node>(f1);
			current->_left = l;
			s.push(l);
		}
		else{
			auto t = NodeValue("terminal");
			auto l = std::make_shared<Node>(t);
			current->_left = l;
			t = NodeValue("terminal");
			auto r = std::make_shared<Node>(t);
			current->_right = r;
		}
		s.pop();
	}
	return root_ptr;
}

Collection<std::shared_ptr<Node>> create_collection_from_tree(std::shared_ptr<Node> root){
	std::stack<std::shared_ptr<Node>> s{};
	s.push(root);
	Collection<std::shared_ptr<Node>> coll;
	while(not s.empty()){
		auto current = s.top();
		s.pop();
		coll.push_back(current);
		if(current->_value.type == "function"){
			s.push(current->_left);
			s.push(current->_right);
		}
	}
	return coll;
}








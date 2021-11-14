#pragma once

#include <variant>
#include <memory>
#include <vector>
#include <stack>
#include <random>


static std::random_device rand_device;


template<typename T>
class Node{
	public:
		std::vector<std::unique_ptr<Node>> children;
		T type;
};


class Individual{
};

class GeneticProgram{
};

//template<typename OutFunction>
//auto post_order(std::unique_ptr<Node> root, OutFunction function){
//	std::vector<decltype(function(root))> out;
//	if(root->children.empty()){
//		out.emplace_back(function(root));
//		return out;
//	}
//	std::stack<std::unique_ptr<Node>> s;
//	s.push(root);
//
//	auto it = out.begin();
//
//	while(not s.empty()){
//		auto curr = s.top();
//		s.pop();
//
//		it = out.insert(it, function(curr));
//		for(auto& i : curr->children){
//			s.push(i);
//		}
//	}
//	return out;
//}

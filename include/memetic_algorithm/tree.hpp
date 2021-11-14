#pragma once

#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <stack>
#include <queue>
#include <algorithm>
#include <ostream>



namespace tree{

	struct NodeProperties{
		std::string _type_node;
		std::size_t _depth;
		std::size_t _position;
		std::string _type;
		double _val;	
		std::size_t _arity = 0;
		bool operator== (const NodeProperties& rhs) const;
	};

	struct Node{
		std::vector<Node> _children;
		NodeProperties _properties;
		bool operator== ( const Node& rhs) const;
	};
	std::ostream& operator<< (std::ostream& os, const Node& node);

	template<typename T>
		auto add_child(T& node, const T& child){
			node._children.emplace_back(child);
		}
	template<typename T,typename U>
		void create_child(T& node, U& function){
			add_child(node, function());
		}

	template<typename T>
		auto traverse_tree_post_order(const T& node){
			std::stack<T> s;
			std::vector<T> out;
			s.push(node);
			while(!s.empty()){
				auto current = s.top();
				s.pop();
				for(auto& node : current._children){
					s.push(node);
				}
				out.insert(out.begin(), current);
			}
			return out;
		}

	template<typename T>
		auto traverse_tree_breadth_first(const T& node){
			std::queue<T> s;
			std::vector<T> out;
			s.push(node);
			while(!s.empty()){
				auto current = s.front();
				s.pop();
				for(auto& node : current._children){
					s.push(node);
				}
				out.emplace_back(current);
			}
			return out;
		}

	template<typename T>
		auto calculate_depth(const T& node){
			std::queue<T> s;
			std::size_t depth = 0;
			s.push(node);
			while(!s.empty()){
				auto current = s.front();
				s.pop();
				for(auto& node : current._children){
					s.push(node);
				}
				if(depth < current._properties._depth){
					depth = current._properties._depth;
				}
			}
			depth;
		}

	Node create_node(const NodeProperties& properties, const std::vector<Node>& children);
}



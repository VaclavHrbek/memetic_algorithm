#include <memetic_algorithm/tree.hpp>

namespace tree{

	bool NodeProperties::operator== ( const NodeProperties& rhs) const {
		if(_type == rhs._type &&
				_arity == rhs._arity){
			return true;
		}
		else{
			return false;
		}	
	};

	bool Node::operator== ( const Node& rhs) const {
		if( _children == rhs._children &&
				_properties == rhs._properties){
			return true;
		}
		else{
			return false;
		}
	};
	std::ostream& operator<< (std::ostream& os, const Node& node){
		os << "(" << node._properties._position << ": " << node._properties._type << ") ";
		return os;
	};
	Node create_node(const NodeProperties& properties, const std::vector<Node>& children){
		return Node{children, properties};
	};

}

#pragma once

#include <vector>

template<typename T>
class Collection {
	public:
		Collection() = default;
		Collection(std::size_t size) : _coll(size) {};
		int size() const{
			return _coll.size();
		}
		T& at(int indx){
			return _coll.at(indx);
		}

		const T& at(int indx) const {
			return _coll.at(indx);
		}

		void push_back(T item){
			_coll.emplace_back(item);
		}

		void push_front(T item){
			_coll.insert(_coll.begin(), item);
		}
		
		void remove(int indx){
			_coll.erase(_coll.begin() + indx);
		}
		
		bool empty() const {
			return _coll.empty();
		}

	private:
		std::vector<T> _coll;
};



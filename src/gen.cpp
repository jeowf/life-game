#include "gen.h"

namespace lg{

	Gen::Coord::Coord(index_type i, index_type j) : x(i), y(j) {}

	bool Gen::Coord::operator==(const Coord& rhs) const{
		return ((this->x == rhs.x) and (this->y == rhs.y));
	}

	Gen::Gen(){ }

	Gen::~Gen(){ }

	void Gen::add(index_type i, index_type j){
		Coord c(i, j);
		gen.push_back(c);
	}


	Gen::size_type Gen::size() const{
		return gen.size();
	}

	bool Gen::operator==(const Gen& rhs) const{
		if (this->size() != rhs.size()){
			return false;
		} else {
			for (int i = 0; i < this->size(); i++){
				if (!(this->gen[i] == rhs[i]))
					return false;
			}
			return true;
		}
	}

	const Gen::Coord& Gen::operator[](index_type i) const{
		return gen[i];
	}

}
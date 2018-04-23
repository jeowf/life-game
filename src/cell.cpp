#include "cell.h"

namespace lg{

	Cell::Cell (status_type s, neighbors_type n) : status(s), 
													n_neighbors(n = 0) { }
	Cell::Cell () : status(status_type::DEAD), 
					n_neighbors(0) { }

	Cell::status_type Cell::get_status( void ) const{
		return status;
	}

	void Cell::set_status( status_type s){
		status = s;
	}

	Cell::neighbors_type Cell::get_n_neighbors( void ) const{
		return n_neighbors;
	}

	void Cell::set_n_neighbors( neighbors_type n){
		n_neighbors = n;
	}

	Cell::ref Cell::operator+= (const ref rhs){
		return this->n_neighbors += rhs;
	}


}
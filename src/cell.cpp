#include "cell.h"

namespace lg{


	//using Cell;

	Cell::Cell (Cell::status_type s, Cell::neighbors_type n) : status(s), 
															   n_neighbors(n = 0) { }
	Cell::Cell () : status(Cell::status_type::DEAD), 
					n_neighbors(0) { }

	Cell::status_type Cell::get_status( void ) const{
		return status;
	}

	void Cell::set_status( Cell::status_type s){
		status = s;
	}

	Cell::neighbors_type Cell::get_n_neighbors( void ) const{
		return n_neighbors;
	}

	void Cell::set_n_neighbors( Cell::neighbors_type n){
		n_neighbors = n;
	}


}
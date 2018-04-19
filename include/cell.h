#ifndef CELL
#define CELL

#include <iostream>

namespace lg{

	class Cell{
		// Alias
	    public:
		//typedef short int status_type;
		typedef size_t neighbors_type; 

		enum class status_type : short int { ALIVE = 0, DEAD };
		
		// Atributos
		private:
		status_type status;
		neighbors_type n_neighbors; 
		
		// Métodos
		public:
		Cell (status_type, neighbors_type);
		
		Cell ();

		status_type get_status( void ) const;
		void set_status( status_type );

		neighbors_type get_n_neighbors( void ) const;
		void set_n_neighbors( neighbors_type );

	};

}

#endif
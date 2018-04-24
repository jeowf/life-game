#ifndef GRID
#define GRID

#include <iostream>

#include "cell.h"

namespace lg{

	class Grid{
		// Alias
	    public:
		//typedef short int status_type;
		typedef long int dimension_type; 
		typedef lg::Cell cell_type;
		typedef lg::Cell::status_type status_type;
		typedef int i_cell_type;
		typedef int index_type;
		
		// Atributos
		private:
		dimension_type n_rows;
		dimension_type n_columns;
		cell_type **grid;
		
		// Métodos
		public:
		Grid (dimension_type, dimension_type);

		~Grid ();

		cell_type& at(index_type, index_type);

		void calculate_neighbors();

		void reset_neighbors();

		void next_gen();

		private:
		index_type wrap_index(index_type, index_type, index_type);

	};

}

#endif
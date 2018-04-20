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
		typedef int i_cell_type;
		typedef int index_type;

		//enum class direction_type : short int { ROW = 0, COLUMN  };
		
		// Atributos
		private:
		dimension_type n_rows;
		dimension_type n_columns;
		cell_type **grid;
		
		// Métodos
		public:
		Grid (dimension_type, dimension_type);

		~Grid ();

		void set_alive(i_cell_type, i_cell_type **);

		void print_grid() const;

		void print_neighbors() const;

		//bool is_stable() const;

		//bool is_extinct() const;

		void update();

		private:
		index_type wrap_index(index_type, index_type, index_type);


		// Cell (status_type, neighbors_type);
		
		// Cell ();

		// status_type get_status( void ) const;
		// void set_status( status_type );

		// neighbors_type get_n_neighbors( void ) const;
		// void set_n_neighbors( neighbors_type );

	};

}

#endif
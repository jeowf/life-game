#ifndef LIFE
#define LIFE

#include <iostream>
#include <iomanip>
#include "grid.h"

namespace lg{

	class Life{
		// Alias
	    public:
	    typedef lg::Grid::dimension_type dimension_type;
	    typedef lg::Grid grid_type;
	    typedef lg::Cell::status_type status_type;
	    
	    typedef char char_type;
	    typedef int i_cell_type;
	    typedef int gen_type;
		//typedef int neighbors_type;
		//typedef int& ref; 

		//enum class status_type : short int { DEAD = 0, ALIVE  };
		
		// Atributos
		private:
		dimension_type rows;
		dimension_type cols;
		grid_type *grid;
		char_type out_char;
		gen_type gen;
		
		// Métodos
		public:
		// Construtores
		Life (dimension_type, dimension_type, char_type);

		~Life();

		void set_alive(i_cell_type, i_cell_type **);

		friend std::ostream& operator<<(std::ostream&, const Life&);


		

	};

}

#endif
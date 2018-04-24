#ifndef CELL
#define CELL

namespace lg{

	class Cell{
		// Alias
	    public:
		typedef int neighbors_type;
		typedef int& ref; 

		enum class status_type : short int { DEAD = 0, ALIVE  };
		
		// Atributos
		private:
		status_type status;
		neighbors_type n_neighbors; 
		
		// Métodos
		public:
		// Construtores
		Cell (status_type, neighbors_type);
		Cell ();

		// Acessores
		status_type get_status( void ) const;
		void set_status( status_type );

		neighbors_type get_n_neighbors( void ) const;
		void set_n_neighbors( neighbors_type );

	};

}

#endif
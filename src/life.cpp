#include "life.h"

namespace lg{

	Life::Life (dimension_type c, dimension_type r, char_type o) : 
				rows(r), cols(c), out_char(o) {
		grid = new grid_type(r,c);
		gen = 0;

		//std::cout << "opa\n";
		//grid->print_grid();
		//grid(r, c);
	}

	Life::~Life(){
		delete grid;
	}

	// Life::print(){

	// }
	void Life::set_alive(i_cell_type alive_value, i_cell_type **i_grid){
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (i_grid[i][j] == alive_value)
					grid->at(i,j).set_status(status_type::ALIVE);
				else
					grid->at(i,j).set_status(status_type::DEAD);
			}
		}
	}


	std::ostream& operator<<(std::ostream& os, const Life& lf) {  

		os << "Generation: "<< lf.gen << std::endl; 
		
		//imprime a primeira linha de pontos
		for (int j = 0; j < lf.cols; j++)
			os << ". ";
		os << "." <<std::endl;

		//imprime a grid propriamente dita
    	for (int i = 0; i < lf.rows; i++){
    		os << ".";
			for (int j = 0; j < lf.cols; j++){
				if (lf.grid->at(i,j).get_status() == lg::Life::status_type::ALIVE)
					os << lf.out_char << ".";
				else 
					os << " .";
			}
			os << "" << std::endl;
		}
		
    	return os;  
	}  
  
	
	


}
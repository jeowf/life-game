#include "life.h"

namespace lg{

	Life::Life (dimension_type c, dimension_type r, char_type o) : 
				rows(r), cols(c), out_char(o) {
		grid = new grid_type(r,c);
		gen = 0;
	}

	Life::~Life(){
		delete grid;
	}

	void Life::set_alive(i_cell_type alive_value, i_cell_type **i_grid){
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (i_grid[i][j] == alive_value)
					grid->at(i,j).set_status(status_type::ALIVE);
				else
					grid->at(i,j).set_status(status_type::DEAD);
			}
		}

		this->save_gen();
	}

	void Life::update(){
		grid->reset_neighbors();
		grid->calculate_neighbors();
		grid->next_gen();
		this->save_gen();
		gen++;
		//std::cout << "EXTINCTC?: " << (bool) this->is_extinct() << std::endl;

	}

	void Life::save_gen(){
		lg::Gen gen;
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (grid->at(i, j).get_status() == status_type::ALIVE)
					gen.add(i,j);
			}
		}
		generations.push_back(gen);
	}

	Life::gen_type Life::is_stable() const{
		if (generations.size() > 1){
			for (int i = 0; i < (gen); i++){
				if (generations[i] == generations[gen])
					return i;
			}
		} 
		return -1;
	}

	bool Life::is_extinct() const{
		return generations[gen].size() == 0;
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
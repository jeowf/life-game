#include "grid.h"

namespace lg{

	Grid::Grid (dimension_type r, dimension_type c) : 
				n_rows(r), n_columns(c) {

		grid = new cell_type*[r];
		for (int i = 0; i < r; i++){
			grid[i] = new cell_type[c];
			for (int j = 0; j < c; j++){
				this->at(i,j).set_status(status_type::DEAD);
			}
		}
		
	}

	Grid::~Grid (){
		for (int i = 0; i < n_rows; i++)
    		delete [] grid[i];
		delete [] grid;
	}

	void Grid::set_alive(i_cell_type alive_value, i_cell_type **i_grid){
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				if (i_grid[i][j] == alive_value)
					this->at(i,j).set_status(status_type::ALIVE);
				else
					this->at(i,j).set_status(status_type::DEAD);
			}
		}
	}

	void Grid::print_grid() const {
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				std::cout << (int) grid[i][j].get_status() << " ";
			}
			std::cout << std::endl;
		}
	}

	void Grid::print_neighbors() const {
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				std::cout << (int) grid[i][j].get_n_neighbors() << " ";
			}
			std::cout << std::endl;
		}
	}

	void Grid::update(){
		this->reset_neighbors();
		this->calculate_neighbors();
		this->next_gen();
	}

	void Grid::reset_neighbors(){
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				this->at(i,j).set_n_neighbors(0);
			}
		}
	}

	void Grid::calculate_neighbors(){
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				if (this->at(i,j).get_status() == status_type::ALIVE){

					// analisa visinhança
					for (int x = i-1; x <= i+1; x++){
						for (int y = j-1; y <= j+1; y++){
							if (this->at(x,y).get_status() == status_type::ALIVE)
								this->at(i,j).set_n_neighbors( this->at(i,j).get_n_neighbors() + 1);
							else
								this->at(x,y).set_n_neighbors( this->at(x,y).get_n_neighbors() + 1);
						}
					}
					//tirando a propria celula q é contada
					this->at(i,j).set_n_neighbors( this->at(i,j).get_n_neighbors() - 1);

				}

			}
		}
	}

	void Grid::next_gen(){
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				if ((this->at(i,j).get_status() == status_type::ALIVE) and
				   (this->at(i,j).get_n_neighbors() <= 1 or 
					this->at(i,j).get_n_neighbors() >= 4))
					this->at(i,j).set_status(status_type::DEAD);
				else if (this->at(i,j).get_status() == status_type::DEAD and
				 		 this->at(i,j).get_n_neighbors() == 3)
					this->at(i,j).set_status(status_type::ALIVE);	
			}
		}
	}

	
	Grid::index_type Grid::wrap_index(index_type v, 
									  index_type i_min, 
								      index_type i_max){

		if (v < i_min) 		 return i_max - (i_min - v);
		else if (v >= i_max) return i_min + (v - i_max);
		else  			     return v;

	}

	Grid::cell_type& Grid::at(index_type x, 
							  index_type y){
		return this->grid[this->wrap_index(x, 0, n_rows)]
						 [this->wrap_index(y, 0, n_columns)];

	}

}
#include "grid.h"

namespace lg{

	Grid::Grid (Grid::dimension_type r, Grid::dimension_type c) : 
				n_rows(r), n_columns(c) {

		this->grid = new Grid::cell_type*[r];
		for (int i = 0; i < r; i++){
			this->grid[i] = new Grid::cell_type[c];
			for (int j = 0; j < c; j++){
				this->grid[i][j].set_status(lg::Cell::status_type::DEAD);
			}
		}
		
	}

	Grid::~Grid (){
		for (int i = 0; i < n_rows; i++)
    		delete [] this->grid[i];
		delete [] this->grid;
	}

	void Grid::set_alive(Grid::i_cell_type alive_value, Grid::i_cell_type **i_grid){
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				if (i_grid[i][j] == alive_value)
					this->grid[i][j].set_status(lg::Cell::status_type::ALIVE);
				else
					this->grid[i][j].set_status(lg::Cell::status_type::DEAD);
			}
		}
	}

	void Grid::print_grid() const {
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				std::cout << (int) this->grid[i][j].get_status() << " ";
			}
			std::cout << std::endl;
		}
	}

	void Grid::print_neighbors() const {
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				std::cout << (int) this->grid[i][j].get_n_neighbors() << " ";
			}
			std::cout << std::endl;
		}
	}

	void Grid::update(){
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				this->grid[i][j].set_n_neighbors(0);
			}
		}


		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				if (this->grid[i][j].get_status() == lg::Cell::status_type::ALIVE){

					// analisa visinhança
					for (int x = i-1; x <= i+1; x++){
						for (int y = j-1; y <= j+1; y++){
							if (this->grid[wrap_index(x, 0, n_rows)][wrap_index(y, 0, n_columns)].get_status() == lg::Cell::status_type::ALIVE)
								this->grid[i][j].set_n_neighbors( this->grid[i][j].get_n_neighbors() + 1);
								//this->grid[i][j]++ // .set_status(lg::Cell::status_type::DEAD);
							this->grid[wrap_index(x, 0, n_rows)][wrap_index(y, 0, n_columns)].set_n_neighbors( this->grid[wrap_index(x, 0, n_rows)][wrap_index(y, 0, n_columns)].get_n_neighbors() + 1);
						}
					}
				}

			}
		}
	}

	Grid::index_type Grid::wrap_index(Grid::index_type v, 
									  Grid::index_type i_min, 
									  Grid::index_type i_max){
		if (v < i_min)
			return (i_max - 1) - (i_min - v);
		else if (v >= i_max)
			return i_min + (v - i_max);
		else 
			return v;

	}

}
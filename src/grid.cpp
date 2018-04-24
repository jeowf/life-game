#include "grid.h"

namespace lg{

	Grid::Grid (dimension_type r, dimension_type c) : 
				n_rows(r), n_columns(c) {

		//alocar a grid
		grid = new cell_type*[r];
		for (int i = 0; i < r; i++){
			grid[i] = new cell_type[c];

			// inicializar os valores das células com status DEAD
			for (int j = 0; j < c; j++){
				this->at(i,j).set_status(status_type::DEAD);
			}
		}
		
	}

	Grid::~Grid (){
		// desalocar a grid
		for (int i = 0; i < n_rows; i++)
    		delete [] grid[i];
		delete [] grid;
	}

	void Grid::reset_neighbors(){
		// para todas as células da grid, calcule os vizinhos
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				this->at(i,j).set_n_neighbors(0);
			}
		}
	}

	void Grid::calculate_neighbors(){
		// percorre as células da grid
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){

				//se a célula for viva
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
		// para todas as células na grid
		for (int i = 0; i < n_rows; i++){
			for (int j = 0; j < n_columns; j++){
				// se a célula for viva e possuir menos que 1 ou mais que
				// 4 vizinhos, então ela morrerá na próxima geração
				if ((this->at(i,j).get_status() == status_type::ALIVE) and
				   (this->at(i,j).get_n_neighbors() <= 1 or 
					this->at(i,j).get_n_neighbors() >= 4))
					this->at(i,j).set_status(status_type::DEAD);

				// se a célula for morta, mas possuir 3 vizinhos, ela irá
				// nascer na próxima geração
				else if (this->at(i,j).get_status() == status_type::DEAD and
				 		 this->at(i,j).get_n_neighbors() == 3)
					this->at(i,j).set_status(status_type::ALIVE);	
			}
		}
	}

	
	Grid::index_type Grid::wrap_index(index_type v, 
									  index_type i_min, 
								      index_type i_max){

		// se o índice é menor que o menor índice, 
		// então retorne a diferença como offset pro índice máximo
		if (v < i_min) return i_max - (i_min - v);

		// análogo à condição anterior, porém o offset é calculado
		// em cima do menor índice com base no maior índice
		else if (v >= i_max) return i_min + (v - i_max);

		// se o índice estiver nos limites, então não há o que fazer
		else return v;

	}

	Grid::cell_type& Grid::at(index_type x, 
							  index_type y){
		// retorna a posição grid[x][y] levando em consideração o wrap
		return this->grid[this->wrap_index(x, 0, n_rows)]
						 [this->wrap_index(y, 0, n_columns)];

	}

}
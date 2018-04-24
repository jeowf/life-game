#include "life.h"

namespace lg{

	Life::Life (dimension_type r, dimension_type c, char_type o) : 
				rows(r), cols(c), out_char(o) {
		// instancia uma grid rXc
		grid = new grid_type(r,c);
		gen = 0;
	}

	Life::~Life(){
		// destroi a grid instanciada
		delete grid;
	}

	void Life::set_alive(i_cell_type alive_value, i_cell_type **i_grid){
		// percorre as células da grid
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				// modifica o status da célula com base em seu valor inteiro
				if (i_grid[i][j] == alive_value)
					grid->at(i,j).set_status(status_type::ALIVE);
				else
					grid->at(i,j).set_status(status_type::DEAD);
			}
		}

		// salva a configuração carregada como a primeira geração
		this->save_gen();
	}

	void Life::update(){
		// reseta o número de vizinhos da grid inteira
		grid->reset_neighbors();

		// calcula os vizinhos
		grid->calculate_neighbors();

		// calcula as células que irão viver/morrer
		grid->next_gen();

		// salva a grid modificada como uma geração
		this->save_gen();
		gen++;

	}

	void Life::save_gen(){
		lg::Gen gen;
		// percorre as células da grid
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				// salva as coordenadas das células vivas na geração
				if (grid->at(i, j).get_status() == status_type::ALIVE)
					gen.add(i,j);
			}
		}

		// adiciona a geração calculada à lista de gerações
		generations.push_back(gen);
	}

	Life::gen_type Life::is_stable() const{
		// se há no mínimo 2 gerações a serem comparadas
		if (generations.size() > 1){
			// compara célula a célula da geração
			for (int i = 0; i < (gen); i++){
				// se encontrar uma geração recorrente, retorna o
				// índice de sua primeira ocorrência
				if (generations[i] == generations[gen])
					return i;
			}
		} 

		// caso não encontre, retorna -1
		return -1;
	}

	bool Life::is_extinct() const{
		// como uma geração só salva as coordenadas das células vivas
		// se o tamanho lógico da geração for 0, não há células vivas
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
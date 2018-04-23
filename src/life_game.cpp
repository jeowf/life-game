#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "grid.h"

// Alias

typedef std::string string;
typedef lg::Grid::i_cell_type c_type;
//typedef std::ifstream 

int main(int argc, char* argv[]){ // Argumentos da linha de comando

	if (argc < 2 || argc > 3){ // verifica a quantidade de argumentos
		std::cerr << "Wrong syntaxe!"  << std::endl;
		std::cerr << "Use: " << argv[0] << " <input_cfg_file> [<output_cfg_evolution_file>]" << std::endl; // mensagem de erro
		return 1;
	}

	//variaveis do sistema
	int m = 0;
	int n = 0;
	char alive;
	char cell;
	std::ifstream file;
	std::string row_data;

	c_type **a;

	file.open(argv[1]); // abre o arquivo passado na linha de comando	
	std::ofstream outfile(argv[2]);//salva no arquivo de saida desejado

	if (file.is_open()){
		getline(file, row_data); // pega a linha das dimensões
		std::istringstream al(row_data);
		al >> m; // pega m'
		al >> n; // pega n

		getline(file, row_data);//pega a linha do caracter de 'vivo'
		std::istringstream ast(row_data);
		ast >> alive;
		//char field[m][n];// criação da matriz
		a = new c_type * [m];

		while (!file.eof()){
			for (int i = 0; i < m; i++){
				a[i] = new c_type[n];
				getline(file, row_data);//pega cada linha do primeiro estado e salva na matriz
				std::istringstream place(row_data); 
				for (int j = 0; j < n; j++){
					//a[i][j] = 0;
					//std::cout << "AA: " << place << " ";
					place >> cell;
					//a[i][j] = cell;
					 if (cell == alive) 
					 	a[i][j] = 1;
					 else
					 	a[i][j] = 0;

					//place >> dead;
					//field[i][j] = dead;

					outfile << a[i][j];// caso exista arquivo de saida salva uma cópia nele

				}

				outfile << std::endl;
			}
		}
	}
//================== Essa parte é o print de teste ===========================================

	// for (int i = 0; i < m; i++){
	// 	for (int j = 0; j < n; j++){
	// 		std::cout << field[i][j];
	// 	}
	// std::cout << std::endl;	
	// }
	
	lg::Grid grid(m, n);
	grid.set_alive(1, a);

	std::cout << std::endl;

	grid.print_grid();
	std::cout << std::endl;

//================== Vai virar uma função ======================================================

	file.close();// fecha os arquivos
	outfile.close();
}
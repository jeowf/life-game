#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <thread>
#include <chrono> 

//#include "grid.h"
#include "life.h"
#include "gen.h"

// Alias

typedef std::string string;
typedef lg::Grid::i_cell_type c_type;
//typedef std::ifstream 

int main(int argc, char* argv[]){ // Argumentos da linha de comando
	//variaveis do sistema
	int rows = 0;
	int cols = 0;
	char alive;
	char cell;
	bool auto_arg = false;
	std::string row_data;

	std::ifstream file;
	std::ofstream outfile;


	c_type **a;

	if (argc == 4){
		if (argv[3][0] != 'a'){
			std::cerr << "Wrong syntaxe!"  << std::endl;
			std::cerr << "Use: " << argv[0] << " <input_cfg_file> [<output_cfg_evolution_file>] [<a> to auto]" << std::endl; // mensagem de erro
			return 1;
		}
		outfile.open(argv[2]);
		auto_arg = true;
	} else if (argc == 3){
		if (argv[2][0] == 'a'){
			outfile.open("out.txt");
			auto_arg = true;
		} else {
			outfile.open(argv[2]);
		}
	} else if (argc == 2){
		outfile.open("out.txt");
	} else {
		if (argc < 2 || argc > 4){ // verifica a quantidade de argumentos
			std::cerr << "Wrong syntaxe!"  << std::endl;
			std::cerr << "Use: " << argv[0] << " <input_cfg_file> [<output_cfg_evolution_file>] [<a> to auto]" << std::endl; // mensagem de erro
		}
		return 1;
	}

	file.open(argv[1]); // abre o arquivo passado na linha de comando

	if (file.is_open()){
		getline(file, row_data); // pega a linha das dimensões
		std::istringstream al(row_data);
		al >> rows; // pega m'
		al >> cols; // pega n

		getline(file, row_data);//pega a linha do caracter de 'vivo'
		std::istringstream ast(row_data);
		ast >> alive;
		//char field[m][n];// criação da matriz
		a = new c_type * [rows];

		while (!file.eof()){
			for (int i = 0; i < rows; i++){
				a[i] = new c_type[cols];
				getline(file, row_data);//pega cada linha do primeiro estado e salva na matriz
				std::istringstream place(row_data); 
				for (int j = 0; j < cols; j++){

					place >> cell;

					 if (cell == alive) 
					 	a[i][j] = 1;
					 else
					 	a[i][j] = 0;

				}

			}
		}
	} else {
		std::cerr << "ERROR: Cannot read the file!" << std::endl;		
		return 1;
	}

	lg::Life life(rows, cols, alive);
	life.set_alive(1, a);

	for (int i = 0; i < rows; i++)
    	delete [] a[i];
	delete [] a;

	std::cout << life << std::endl;
	outfile << life << std::endl;

	char sel = 'y';
	int s_config = -1;

	if (!auto_arg) {
		std::cout << "Next generation? (y/N) ";
		std::cin >> sel;
	}
	
	while (sel == 'y'){

		std::cout<<std::endl;

		life.update();
		std::cout << life << std::endl;
		outfile << life << std::endl;
		
		s_config = life.is_stable();
		if (s_config >= 0){
			std::cout << "STABLE CONFIGURATION STARTING AT GENERATION "<< s_config << std::endl;
			outfile << "STABLE CONFIGURATION STARTING AT GENERATION "<< s_config << std::endl;
			break;
		} else if (life.is_extinct() == true){
			std::cout << "EXTINCT CONFIGURATION!" << std::endl;
			outfile << "EXTINCT CONFIGURATION!" << std::endl;
			break;
		}

		if (auto_arg){
			std::this_thread::sleep_for (std::chrono::seconds(1));
		} else {
			std::cout << "Next generation? (y/N) ";
			std::cin >> sel;
		}

	}

	

	file.close();// fecha os arquivos
	outfile.close();
}
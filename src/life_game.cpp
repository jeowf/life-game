#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono> 

#include "life.h"
#include "gen.h"

///
/// Alias
///
typedef std::string string; 			/*!< Type of string */
typedef lg::Grid::i_cell_type c_type;   /*!< Type of initialization cell */

int main(int argc, char* argv[]){ 
	///
	/// System Variables
	///
	int rows = 0; 			/*!< Number of rows */
	int cols = 0; 			/*!< Number of columns */
	char alive;  			/*!< Alive character */
	char cell;       		/*!< Character of cell */
	bool auto_arg = false;  /*!< Auto arg */
	std::string row_data;   /*!< Row of file */

	std::ifstream file;     /*!< Input file */
	std::ofstream outfile;  /*!< Output file */

	c_type **a; 			/*!< Grid of initialization */

	// tratamento de argumentos
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

		std::cerr << "Wrong syntaxe!"  << std::endl;
		std::cerr << "Use: " << argv[0] << " <input_cfg_file> [<output_cfg_evolution_file>] [<a> to auto]" << std::endl; // mensagem de erro
		
		return 1;
	}

	// abre o arquivo passado na linha de comando
	file.open(argv[1]); 

	// verifica se o arquivo foi aberto corretamente
	if (file.is_open()){
		// pega a linha das dimensões
		getline(file, row_data); 
		std::istringstream al(row_data);
		al >> rows; // pega linhas
		al >> cols; // pega colunas

		//pega a linha do caracter de 'vivo'
		getline(file, row_data);
		std::istringstream ast(row_data);
		ast >> alive;

		// intancia a grid de inicialização
		a = new c_type * [rows];

		// enquanto não for final de arquivo
		while (!file.eof()){
			for (int i = 0; i < rows; i++){
				a[i] = new c_type[cols];

				//pega cada linha do primeiro estado e salva na matriz
				getline(file, row_data);
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

	// caso haja erro na leitura do arquivo
	} else {
		std::cerr << "ERROR: Cannot read the file!" << std::endl;		
		return 1;
	}

	// instancia Life e inicializa sua grid
	lg::Life life(rows, cols, alive);
	life.set_alive(1, a);

	// desaloca a matriz de inicialização
	for (int i = 0; i < rows; i++)
    	delete [] a[i];
	delete [] a;

	// imprime a configuração da grid
	std::cout << life << std::endl;
	outfile << life << std::endl;

	char sel = 'y';
	int s_config = -1;

	// se não for automático, mostra opção de gerar
	// próxima geração
	if (!auto_arg) {
		std::cout << "Next generation? (y/N) ";
		std::cin >> sel;
	}
	
	// enquanto a seleção do usuário for y
	while (sel == 'y'){
		// pula linha
		std::cout<<std::endl;

		// atualiza grid de células
		life.update();

		// imprime configuração
		std::cout << life << std::endl;
		outfile << life << std::endl;
		
		// verifica estabilidade
		// caso seja estável, finaliza programa
		s_config = life.is_stable();
		if (s_config >= 0){
			std::cout << "STABLE CONFIGURATION STARTING AT GENERATION "<< s_config << std::endl;
			outfile << "STABLE CONFIGURATION STARTING AT GENERATION "<< s_config << std::endl;
			break;

		// verifica extinção
		// caso seja extinta, finaliza programa
		} else if (life.is_extinct() == true){
			std::cout << "EXTINCT CONFIGURATION!" << std::endl;
			outfile << "EXTINCT CONFIGURATION!" << std::endl;
			break;
		}

		// se for automático, espera um segundo para 
		// mostrar a próxima configuração
		if (auto_arg){
			std::this_thread::sleep_for (std::chrono::seconds(1));

		// caso não seja auto, mostra opção pro usuário
		} else {
			std::cout << "Next generation? (y/N) ";
			std::cin >> sel;
		}

	}

	// fecha streams de arquivos
	file.close();
	outfile.close();
}
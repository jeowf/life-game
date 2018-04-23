#include <iostream>

//#include "cell.h"
#include "grid.h"

int main(){

	// lg::Cell cell;
	// int a = (int) cell.get_status();
	// std::cout << a << std::endl;
	int rows = 10, cols = 10;

	lg::Grid grid(rows, cols);

	//inicializando Grid (teste)
	int **a = new int * [rows];
	for  (int i = 0; i < rows; i++){
		a[i] = new int[cols];
		for (int j = 0; j < cols; j++){
			if (i == j)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}

	for (int i = 0; i < rows; i++){
		a[i][3] = 1;
	}

	grid.set_alive(1, a);
	grid.print_grid();
	std::cout << std::endl;

	grid.update();
	grid.print_grid();
	std::cout << std::endl;

	//grid.at(0,0) += (int) 20;
	//grid.at(-1,-1).set_n_neighbors(20);
	grid.print_neighbors();

	std::cout << std::endl;

	grid.update();
	grid.print_grid();




	return 0;
}
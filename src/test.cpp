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

	grid.set_alive(1, a);
	grid.update();
	grid.print_grid();
	std::cout << std::endl;
	grid.print_neighbors();

	return 0;
}
#include <iostream>

#include "cell.h"

int main(){

	lg::Cell cell;
	int a = (int) cell.get_status();
	std::cout << a << std::endl;

	return 0;
}
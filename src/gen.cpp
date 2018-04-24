#include "gen.h"

namespace lg{

	Gen::Coord::Coord(index_type i, index_type j) : x(i), y(j) {}

	bool Gen::Coord::operator==(const Coord& rhs) const{
		// uma coordenada é igual a outra se seu par ordenado é igual
		return ((this->x == rhs.x) and (this->y == rhs.y));
	}

	void Gen::add(index_type i, index_type j){
		// cria uma coordenada (i,j) e a adiciona à geração
		Coord c(i, j);
		gen.push_back(c);
	}


	Gen::size_type Gen::size() const{
		// retorna tamanho lógico da geração
		return gen.size();
	}

	bool Gen::operator==(const Gen& rhs) const{
		// se a quantidade de células vivas de uma geração é
		// distinta de outra, logo são diferentes
		if (this->size() != rhs.size()){
			return false;
		} else {

			// caso contrário, isto é, a quantidade de células
			// vivas é igual

			// percorre todos os elementos das gerações comparadas
			// par a par.
			// NOTE QUE as comparações estão sendo feitas par a par
			// pois as coordenadas estão numa ordem conhecida
			for (int i = 0; i < this->size(); i++){
				if (!(this->gen[i] == rhs[i]))
					return false;
			}
			return true;
		}
	}

	const Gen::Coord& Gen::operator[](index_type i) const{
		// retorna a célula na posição i
		return gen[i];
	}

}
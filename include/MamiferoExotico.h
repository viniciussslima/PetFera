/**
* @file MamiferoExotico.h
* @brief Classe que representa mamíferos exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_MAMIFEROEXOTICO_H_
#define _H_MAMIFEROEXOTICO_H_

#include "Mamifero.h"
#include "AnimalExotico.h"

using namespace std;

class MamiferoExotico : public Mamifero, public AnimalExotico
{
	public:
		MamiferoExotico();
		MamiferoExotico(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, string, string, string);
		~MamiferoExotico();
		friend ostream& operator<<(ostream &, MamiferoExotico);
};

#endif
/**
* @file AnfibioNativo.h
* @brief Classe que representa anfibíos nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_ANFIBIONATIVO_H_
#define _H_ANFIBIONATIVO_H_

#include "Anfibio.h"
#include "AnimalNativo.h"

using namespace std;

class AnfibioNativo : public Anfibio, public AnimalNativo
{
	public:
		AnfibioNativo();
		AnfibioNativo(int, string, string, char,
			double, string,	Veterinario, Tratador,
			string, int, date, string, string);
		~AnfibioNativo();
		friend ostream& operator<<(ostream &, AnfibioNativo);
};

#endif
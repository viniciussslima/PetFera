/**
* @file MamiferoNativo.h
* @brief Classe que representa mamíferos nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_MAMIFERONATIVO_H_
#define _H_MAMIFERONATIVO_H_

#include "Mamifero.h"
#include "AnimalNativo.h"

using namespace std;

class MamiferoNativo : public Mamifero, public AnimalNativo
{
	public:
		MamiferoNativo();
		MamiferoNativo(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, string, string, string);
		~MamiferoNativo();
		friend ostream& operator<<(ostream &, MamiferoNativo);
};

#endif
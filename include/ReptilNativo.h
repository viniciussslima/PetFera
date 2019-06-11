/**
* @file ReptilNativo.h
* @brief Classe que representa répteis nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_REPTILNATIVO_H_
#define _H_REPTILNATIVO_H_

#include "Reptil.h"
#include "AnimalNativo.h"

using namespace std;

class ReptilNativo : public Reptil, public AnimalNativo
{
	public:
		ReptilNativo();
		ReptilNativo(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, bool, string, string, string);
		~ReptilNativo();
		friend ostream& operator<<(ostream &, ReptilNativo);
};

#endif
/**
* @file ReptilExotico.h
* @brief Classe que representa répeteis exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_REPTILEXOTICO_H_
#define _H_REPTILEXOTICO_H_

#include "Reptil.h"
#include "AnimalExotico.h"

using namespace std;

class ReptilExotico : public Reptil, public AnimalExotico
{
	public:
		ReptilExotico();
		ReptilExotico(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, bool, string, string, string, string);
		~ReptilExotico();
		friend ostream& operator<<(ostream &, ReptilExotico);
};

#endif
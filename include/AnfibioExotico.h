/**
* @file AnfibioExotico.h
* @brief Classe que representa anfibíos exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_ANFIBIOEXOTICO_H_
#define _H_ANFIBIOEXOTICO_H_

#include "Anfibio.h"
#include "AnimalExotico.h"

using namespace std;

class AnfibioExotico : public Anfibio, public AnimalExotico
{
	public:
		AnfibioExotico();
		AnfibioExotico(int, string, string, char,
			double, string, Veterinario,
			Tratador, string, int,
			date, string, string);
		~AnfibioExotico();
		friend ostream& operator<<(ostream &, AnfibioExotico);
};

#endif
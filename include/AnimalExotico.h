/**
* @file AnimalExotico.h
* @brief Classe que representa animais exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_ANIMAL_EXOTICO_H_
#define _H_ANIMAL_EXOTICO_H_

#include "AnimalSilvestre.h"

using namespace std;

class AnimalExotico : public AnimalSilvestre
{
	protected:
		string m_pais_origem;
		string m_cidade_origem;
	public:
		AnimalExotico();
		AnimalExotico(string, string, string);
		~AnimalExotico();
		string get_pais_de_origem();
		string get_cidade_de_origem();
};

#endif
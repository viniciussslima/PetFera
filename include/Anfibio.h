/**
* @file Anfibio.h
* @brief Classe que representa anfibíos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_ANFIBIO_H_
#define _H_ANFIBIO_H_

#include "date.h"
#include "Animal.h" 

using namespace std;

class Anfibio: public Animal
{
	protected:
		int m_total_de_mudas;
		date m_ultima_muda;

	public:
		Anfibio();
		Anfibio(int, string, string, char,
				double, string, Veterinario,
				Tratador, string, int, date);
		~Anfibio();
		int get_total_de_mudas();
		string get_data_da_ultima_muda();
};

#endif
/**
* @file AnimalSilvestre.h
* @brief Classe que representa animais silvestres.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_ANIMAL_SILVESTRE_H_
#define _H_ANIMAL_SILVESTRE_H_

#include <string>

using namespace std;

class AnimalSilvestre
{
	protected:
		string m_autorizacao_ibama;
	public:
		AnimalSilvestre();
		AnimalSilvestre(string);
		~AnimalSilvestre();
		string get_autorizacao_ibama();
};

#endif
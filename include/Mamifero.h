/**
* @file Mamifero.h
* @brief Classe que representa mamíferos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_MAMIFERO_H
#define _H_MAMIFERO_H

#include "Animal.h"
#include <string>

using namespace std;

class Mamifero: public Animal
{
protected:
	string m_cor_pelo;

public:
	Mamifero();
	Mamifero(int, string, string, char,
		double, string, Veterinario,
		Tratador, string, string);
	~Mamifero();
	string get_cor_do_pelo();
};

#endif
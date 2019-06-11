/**
* @file Veterinario.h
* @brief Classe que representa veterinários.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_VETERINARIO_H_
#define _H_VETERINARIO_H_

#include <string>

#include "Funcionario.h"

using namespace std;

class Veterinario : public Funcionario
{
	private:
		string m_cmv;
	public:
		Veterinario();
		Veterinario(int, string, string,
			short, string, char, string,
			string);
		~Veterinario();
		string get_crmv();
		friend ostream& operator<<(ostream &, Veterinario);
	
};

#endif
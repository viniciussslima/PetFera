#ifndef _H_VETERINARIO_H_
#define _H_VETERINARIO_H_

#include <string>

#include "Funcionario.h"

using namespace std;

class Veterinario : public Funcionario
{
	private:
		string m_crmv;
	public:
		Veterinario();
		Veterinario(int, string, string,
			short, string, char, string,
			string);
		~Veterinario();
		friend ostream& operator<<(ostream &, Veterinario);
		void Exibir_Veterinario();
		void Exibir_Veterinario_2();
	
};

#endif
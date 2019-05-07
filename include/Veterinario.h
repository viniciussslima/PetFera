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
			short, short, char, string,
			int);
		~Veterinario();
	
};

#endif
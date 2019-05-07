#ifndef _H_TRATADOR_H_
#define _H_TRATADOR_H_

#include <string>

#include "Funcionario.h"

using namespace std;

class Tratador : public Funcionario
{
	private:
		int m_nivel_de_seguranca;
	public:
		Tratador(int, string, string,
	short, short, char,	string, int);
		Tratador();
		~Tratador();
	
};

#endif
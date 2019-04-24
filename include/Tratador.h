#ifndef _H_TRATADOR_H
#define _H_TRATADOR_H

using namespace std;

class Tratador : public Funcionario
{
	private:
		int m_nivel_de_seguranca;
	public:
		Tratador();
		~Tratador();
	
};

#endif
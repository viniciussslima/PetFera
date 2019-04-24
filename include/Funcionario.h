#ifndef _H_FUNCIONARIO_H
#define _H_FUNCIONARIO_H

#include <iostream>
#include <string>

using namespace std;

class Funcionario
{
	protected:
		int m_id;
		string m_nome;
		string m_cpf;
		short m_idade;
		short m_tipo_sanguineo;
		char m_fator_rh;
		string m_especialidade;
	public:
		Funcionario(int new_id, string new_nome, string new_cpf,
			short new_idade, short new_tipo_sanguineo, char new_fator_rh,
			string new_especialidade);
		~Funcionario();
	
};

#endif

/*
friend ostream& operator<< (ostream &o, 
	Funcionario const F)
{
	o << F.m_id << endl
		<< F.m_id << endl
		<< F.m_nome << endl
		<< F.m_cpf << endl
		<< F.m_idade << endl
		<< F.m_tipo_sanguineo << endl
		<< F.m_fator_rh << endl
		<< F.m_especialidade << endl;
	return o;
}
*/
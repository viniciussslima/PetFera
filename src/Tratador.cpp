/**
* @file Tratador.cpp
*/

#include "Funcionario.h"
#include "Tratador.h"

using namespace std;

Tratador::Tratador(){}

Tratador::Tratador(int new_id, string new_nome, string new_cpf,
	short new_idade, string new_tipo_sanguineo, char new_fator_rh,
	string new_especialidade, int new_nivel_de_seguranca):
	Funcionario(new_id, new_nome, new_cpf,
		new_idade, new_tipo_sanguineo, new_fator_rh,
		new_especialidade)
{
	m_nivel_de_seguranca = new_nivel_de_seguranca;
}

Tratador::~Tratador(){}

void Tratador::Exibir_tratador(){
		cout << endl
		<< "Id: " << m_id << endl
		<< "Função: Tratador" << endl
		<< "Nome: " << m_nome << endl
		<< "CPF: " << m_cpf << endl
		<< "Idade: " << m_idade << endl
		<< "Tipo Sanguineo: " << m_tipo_sanguineo << endl
		<< "RH: " << m_fator_rh << endl
		<<"Especialidade: " << m_especialidade << endl
		<<"m_nivel_de_seguranca: " << m_nivel_de_seguranca << endl; 


}


ostream& operator<<(ostream &o, Tratador A)
{
	o << A.m_id << ";"
		<< "TRATADOR" << ";"
		<< A.m_nome << ";"
		<< A.m_cpf << ";"
		<< A.m_idade << ";"
		<< A.m_tipo_sanguineo << ";"
		<< A.m_fator_rh << ";"
		<< A.m_especialidade << ";"
		<< A.m_nivel_de_seguranca << ";";
	return o;
}

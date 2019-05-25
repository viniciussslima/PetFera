#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario(){}

Funcionario::Funcionario(int new_id, string new_nome, string new_cpf,
	short new_idade, string new_tipo_sanguineo, char new_fator_rh,
	string new_especialidade)
{
	m_id = new_id;
	m_nome = new_nome;
	m_cpf = new_cpf;
	m_idade = new_idade;
	m_tipo_sanguineo = new_tipo_sanguineo;
	m_fator_rh = new_fator_rh;
	m_especialidade = new_especialidade;
}

Funcionario::~Funcionario(){}

int Funcionario::get_id()
{
	return m_id;
}

string Funcionario::get_nome()
{
	return m_nome;
}

string Funcionario::get_cpf()
{
	return m_cpf;
}

short Funcionario::get_idade()
{
	return m_idade;
}

string Funcionario::get_tipo_sanguineo()
{
	return m_tipo_sanguineo;
}

char Funcionario::get_rh()
{
	return m_fator_rh;
}

string Funcionario::get_especialidade()
{
	return m_especialidade;
}
#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario():m_id(-1){}

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

int Funcionario::getId()
{
	return m_id;
}
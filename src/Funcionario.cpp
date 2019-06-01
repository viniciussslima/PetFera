/**
* @file Funcionario.cpp
*/

#include "Funcionario.h"

using namespace std;

/**
* @brief Construtor padrão da classe Funcionario.
*/

Funcionario::Funcionario():m_id(0){}

/**
* @brief construtor parametrizado da classe Funcionario.
* @param new_id Número que representa a identidade do funcionário. 
* @param new_nome Palavra(s) que representa o nome do funcionário. 
* @param new_cpf String que representa o cpf do funcionário. 
* @param new_idade Número que representa a idade do funcionário. 
* @param new_tipo_sanguinio String que representa o tipo sanguinio do funcionário (A, B, AB, O). 
* @param new_fator_rh Carácter que representa o fator RH do funcionário (+, -). 
* @param new_especialidade Palavra(s) que repreta(m) a especialidade do funcionário (Aves ou qualquer outro tipo de animail). 
*/

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

/**
* @brief Destrutor da classe Funcionario.
*/

Funcionario::~Funcionario(){}

/**
* @brief Método que retorna o Id do funcionário.
*/

int Funcionario::getId()
{
	return m_id;
}

/**
* @file Funcionario.cpp
* @brief Implementação da classe Funcionario.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Funcionario.h"

using namespace std;

/**
* @brief Construtor padrão da classe Funcionario.
* Nesse caso o funcionário é contruido com o ID igual a 0.
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
* @return Retorna o ID do funcionário.
*/

int Funcionario::get_id() const
{
	return m_id;
}

/**
* @brief Método que retorna o nome do funcionário.
* @return Retorna o nome do funcionário.
*/

string Funcionario::get_nome()
{
	return m_nome;
}

/**
* @brief Método que retorna o CPF do funcionário.
* @return Retorna o COF do funcionário.
*/

string Funcionario::get_cpf()
{
	return m_cpf;
}

/**
* @brief Método que retorna a idade do funcionário.
* @return Retorna a idade do funcionário.
*/

short Funcionario::get_idade()
{
	return m_idade;
}

/**
* @brief Método que retorna o tipo sanguínio do funcionário.
* @return Retorna o tipo sanguínio do funcionário.
*/

string Funcionario::get_tipo_sanguineo()
{
	return m_tipo_sanguineo;
}

/**
* @brief Método que retorna o fator RH do funcionário.
* @return Retorna o fator RH do funcionário.
*/

char Funcionario::get_rh()
{
	return m_fator_rh;
}

/**
* @brief Método que retorna a especialidae do funcionário.
* @return Retorna a especialidade do funcionário.
*/

string Funcionario::get_especialidade()
{
	return m_especialidade;
}
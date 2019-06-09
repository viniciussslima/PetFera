/**
* @file Veterinario.cpp
* @brief Classe que representa veterinários.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Veterinario.h"

using namespace std;

/**
* @brief Construtor padrão da classe Veterinario.
*/

Veterinario::Veterinario(){}

/**
* @brief construtor parametrizado da classe Veterinario.
* @param new_id Número que representa a identidade do funcionário. 
* @param new_nome Palavra(s) que representa o nome do funcionário. 
* @param new_cpf String que representa o cpf do funcionário. 
* @param new_idade Número que representa a idade do funcionário. 
* @param new_tipo_sanguinio String que representa o tipo sanguinio do funcionário (A, B, AB ou O). 
* @param new_fator_rh Carácter que representa o fator RH do funcionário (+ ou -). 
* @param new_especialidade Palavra(s) que repreta(m) a especialidade do funcionário (Aves ou qualquer outro tipo de animail). 
* @param new_crmv String a CRMV do veterinário.
*/

Veterinario::Veterinario(int new_id, string new_nome, string new_cpf,
	short new_idade, string new_tipo_sanguineo, char new_fator_rh,
	string new_especialidade, string new_crmv):
	Funcionario(new_id, new_nome, new_cpf,
		new_idade, new_tipo_sanguineo,
		new_fator_rh, new_especialidade)
{
	m_cmv = new_crmv;
}

/**
* @brief Destrutor da classe Veterinario.
*/

Veterinario::~Veterinario(){}

/**
* @brief Método que retorna a CRMV do veterinário.
* @return Retorna a CRMV do veterinário..
*/

string Veterinario::get_crmv()
{
	return m_cmv;
}

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do veterinário.
* @param V Veterinário que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações do veterinário em forma de stream.
*/

ostream& operator<<(ostream &o, Veterinario V)
{
	o << V.m_id << ";"
		<< "VETERINARIO" << ";"
		<< V.m_nome << ";"
		<< V.m_cpf << ";"
		<< V.m_idade << ";"
		<< V.m_tipo_sanguineo << ";"
		<< V.m_fator_rh << ";"
		<< V.m_especialidade << ";"
		<< V.m_cmv << ";";
	return o;
}
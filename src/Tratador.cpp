/**
* @file Tratador.cpp
*/

#include "Funcionario.h"
#include "Tratador.h"

using namespace std;

/**
* @brief Construtor padrão da classe Tratador.
*/

Tratador::Tratador(){}

/**
* @brief construtor parametrizado da classe Tratador.
* @param new_id Número que representa a identidade do funcionário. 
* @param new_nome Palavra(s) que representa o nome do funcionário. 
* @param new_cpf String que representa o cpf do funcionário. 
* @param new_idade Número que representa a idade do funcionário. 
* @param new_tipo_sanguinio String que representa o tipo sanguinio do funcionário (A, B, AB ou O). 
* @param new_fator_rh Carácter que representa o fator RH do funcionário (+ ou -). 
* @param new_especialidade Palavra(s) que repreta(m) a especialidade do funcionário (Aves ou qualquer outro tipo de animail). 
* @param new_nivel_de_seguranca Numero que repreta o nivel de segurança do tratador (0, 1 ou 2).
*/

Tratador::Tratador(int new_id, string new_nome, string new_cpf,
	short new_idade, string new_tipo_sanguineo, char new_fator_rh,
	string new_especialidade, int new_nivel_de_seguranca):
	Funcionario(new_id, new_nome, new_cpf,
		new_idade, new_tipo_sanguineo, new_fator_rh,
		new_especialidade)
{
	m_nivel_de_seguranca = new_nivel_de_seguranca;
}

/**
* @brief Destrutor da classe Tratador.
*/

Tratador::~Tratador(){}

/**
* @brief Método que imprime todas as informações do tratador na tela.
*/

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

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do tratador.
* @param T Tratador que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações do tratador em forma de stream.
*/

ostream& operator<<(ostream &o, Tratador T)
{
	o << T.m_id << ";"
		<< "TRATADOR" << ";"
		<< T.m_nome << ";"
		<< T.m_cpf << ";"
		<< T.m_idade << ";"
		<< T.m_tipo_sanguineo << ";"
		<< T.m_fator_rh << ";"
		<< T.m_especialidade << ";"
		<< T.m_nivel_de_seguranca << ";";
	return o;
}

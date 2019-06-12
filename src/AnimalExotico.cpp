/**
* @file AnimalExotico.cpp
* @brief Implementação da classe AnimalExotico.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "AnimalExotico.h"

using namespace std;

/**
* @brief Construtor padrão da classe AnimalExotico.
*/

AnimalExotico::AnimalExotico(){}

/**
* @brief construtor parametrizado da classe AnimalExotico.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_pais_origem Palavra(s) que representam o país de origem do animal exótico. 
* @param new_cidade_origem Palavra(s) que representam q cidade de origem do animal exótico.
*/

AnimalExotico::AnimalExotico(string new_autorizacao_ibama, 
	string new_pais_origem, string new_cidade_origem):
		AnimalSilvestre(new_autorizacao_ibama)
{
	m_pais_origem = new_pais_origem;
	m_cidade_origem = new_cidade_origem;
}

/**
* @brief Destrutor da classe AnimalExotico.
*/

AnimalExotico::~AnimalExotico(){}

/**
* @brief Método que retorna o país de origem do animal.
* @return Retorna o país de origem do animal.
*/

string AnimalExotico::get_pais_de_origem()
{
	return m_pais_origem;
}

/**
* @brief Método que retorna acidade de origem do animal.
* @return Retorna a acidade de origem do animal.
*/

string AnimalExotico::get_cidade_de_origem()
{
	return m_cidade_origem;
}
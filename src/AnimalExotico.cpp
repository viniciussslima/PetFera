/**
* @file AnimalExotico.cpp
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
*/

AnimalExotico::AnimalExotico(string new_autorizacao_ibama, 
	string new_pais_origem):
		AnimalSilvestre(new_autorizacao_ibama)
{
	m_pais_origem = new_pais_origem;
}

/**
* @brief Destrutor da classe AnimalExotico.
*/

AnimalExotico::~AnimalExotico(){}
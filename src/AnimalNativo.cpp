/**
* @file AnimalNativo.cpp
*/

#include "AnimalNativo.h"

/**
* @brief Construtor padrão da classe AnimalNativo.
*/

AnimalNativo::AnimalNativo(){}

/**
* @brief construtor parametrizado da classe AnimalNativo.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_uf_origem Sigla que representa o estado de origem do animal nativo. 
*/

AnimalNativo::AnimalNativo(string new_autorizacao_ibama,
	string new_uf_origem):
		AnimalSilvestre(new_autorizacao_ibama)
{
	m_uf_origem = new_uf_origem;
}

/**
* @brief Destrutor da classe AnimalNativo.
*/

AnimalNativo::~AnimalNativo(){}
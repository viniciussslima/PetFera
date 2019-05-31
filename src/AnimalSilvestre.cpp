/**
* @file AnimalSilvestre.cpp
*/

#include "AnimalSilvestre.h"

/**
* @brief Construtor padrão da classe AnimalSilvestre.
*/

AnimalSilvestre::AnimalSilvestre(){}

/**
* @brief construtor parametrizado da classe AnimalSilvestre.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
*/

AnimalSilvestre::AnimalSilvestre(string new_autorizacao_ibama)
{
	m_autorizacao_ibama = new_autorizacao_ibama;
}

/**
* @brief Destrutor da classe AnimalSilvestre.
*/

AnimalSilvestre::~AnimalSilvestre(){}
/**
* @file AnimalSilvestre.cpp
* @brief Classe que representa animais silvestres.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "AnimalSilvestre.h"

/**
* @brief Construtor padrão da classe AnimalSilvestre.
*/

AnimalSilvestre::AnimalSilvestre(){}

/**
* @brief construtor parametrizado da classe AnimalSilvestre.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do Ibama. 
*/

AnimalSilvestre::AnimalSilvestre(string new_autorizacao_ibama)
{
	m_autorizacao_ibama = new_autorizacao_ibama;
}

/**
* @brief Destrutor da classe AnimalSilvestre.
*/

AnimalSilvestre::~AnimalSilvestre(){}

/**
* @brief Método que retorna a autorização do Ibama do animal.
* @return Retorna a autorização do Ibama do animal.
*/

string AnimalSilvestre::get_autorizacao_ibama()
{
	return m_autorizacao_ibama;
}
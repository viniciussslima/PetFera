#include "AnimalSilvestre.h"

AnimalSilvestre::AnimalSilvestre(string new_autorizacao_ibama)
{
	m_autorizacao_ibama = new_autorizacao_ibama;
}

AnimalSilvestre::AnimalSilvestre(){}

AnimalSilvestre::~AnimalSilvestre(){}

string AnimalSilvestre::get_autorizacao_ibama()
{
	return m_autorizacao_ibama;
}
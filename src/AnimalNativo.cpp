#include "AnimalNativo.h"

AnimalNativo::AnimalNativo(){}

AnimalNativo::AnimalNativo(string new_autorizacao_ibama,
	string new_uf_origem):
		AnimalSilvestre(new_autorizacao_ibama)
{
	m_uf_origem = new_uf_origem;
}

AnimalNativo::~AnimalNativo(){}

string AnimalNativo::get_uf_de_origem()
{
	return m_uf_origem;
}
#include "AnimalExotico.h"

using namespace std;

AnimalExotico::AnimalExotico(){}

AnimalExotico::AnimalExotico(string new_autorizacao_ibama, 
	string new_pais_origem):
		AnimalSilvestre(new_autorizacao_ibama)
{
	m_pais_origem = new_pais_origem;
}

AnimalExotico::~AnimalExotico(){}

string AnimalExotico::get_pais_de_origem()
{
	return m_pais_origem;
}
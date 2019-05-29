/**
* @file Reptil.cpp
*/

#include "Reptil.h"

using namespace std;

Reptil::Reptil(){}

Reptil::Reptil(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, bool new_venenoso, 
	string new_tipo_veneno):
		Animal(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_venenoso = new_venenoso; 
	m_tipo_veneno = new_tipo_veneno;
}

Reptil::~Reptil(){}

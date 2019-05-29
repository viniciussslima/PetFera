/**
* @file Mamifero.cpp
*/

#include "Mamifero.h"

using namespace std;

Mamifero::Mamifero(){}

Mamifero::Mamifero(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, string new_cor_pelo):
		Animal(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_cor_pelo = new_cor_pelo;
}

Mamifero::~Mamifero(){}
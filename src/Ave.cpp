#include "Ave.h"

using namespace std;

Ave::Ave(){}

Ave::Ave(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, double new_tamanho_do_bico,
	double new_envergadura_das_asas):
		Animal(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_tamanho_do_bico = new_tamanho_do_bico;
	m_envergadura_das_asas = new_envergadura_das_asas;
}

Ave::~Ave(){}

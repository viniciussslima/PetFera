#include "Ave.h"

using namespace std;

Ave::Ave(){}

Ave::Ave(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, double new_tamanho_do_bico,
	double new_evergadura_das_asas):
		Animal(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_total_de_mudas = new_total_de_mudas;
	m_ultima_muda = new_ultima_muda;
}

Ave::~Ave(){}

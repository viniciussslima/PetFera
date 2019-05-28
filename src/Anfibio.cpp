#include "Anfibio.h"

using namespace std;

/**
* @brief Construtor padrão da classe anfibio.
*/

Anfibio::Anfibio(){}

/**
* @brief construtor parametrizado da classe anfibio.
* @param new_id: Numero que representa a identidade do anfibio.
*/

Anfibio::Anfibio(int new_id, string new_classe,
		string new_nome_cientifico,	char new_sexo,
		double new_tamanho,	string new_dieta,
		Veterinario new_veterinario, Tratador new_tratador,
		string new_nome_batismo, int new_total_de_mudas,
		date new_ultima_muda):
		Animal(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_total_de_mudas = new_total_de_mudas;
	m_ultima_muda = new_ultima_muda;
}

/**
* @brief Destrutor da classe anfibio
*/

Anfibio::~Anfibio(){}
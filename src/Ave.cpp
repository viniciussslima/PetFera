/**
* @file Ave.cpp
*/

#include "Ave.h"

using namespace std;

/**
* @brief Construtor padrão da classe Ave.
*/

Ave::Ave(){}

/**
* @brief construtor parametrizado da classe Ave.
* @param new_id Número que representa a identidade da ave. 
* @param new_classe Palavra que representa a classe do animal (Ave, réptil, aves, mamífero). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico da ave. 
* @param new_sexo Carácter que representa o sexo da ave (F, M). 
* @param new_tamanho Número que representa o tamanho da ave. 
* @param new_dieta Palavra(s) que representa a dieta da ave. 
* @param new_veterinario Veterinario responsável pela ave. 
* @param new_tratador Tratador responsável pela ave. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo da ave. 
* @param new_tamanho_do_bico Número que representa o tamanho do bico da ave. 
* @param new_envergadura_das_asas Numero que representa a envergadura da ave. 
*/

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

/**
* @brief Destrutor da classe Ave.
*/

Ave::~Ave(){}

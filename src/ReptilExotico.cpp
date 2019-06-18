/**
* @file ReptilExotico.cpp
* @brief Implementação da classe ReptilExotico.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "ReptilExotico.h"

/**
* @brief Construtor padrão da classe ReptilExotico.
*/

ReptilExotico::ReptilExotico(){}

/**
* @brief construtor parametrizado da classe ReptilExotico.
* @param new_id Número que representa a identidade do réptil. 
* @param new_classe Palavra que representa a classe do animal (Ave, réptil, aves, réptil). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do réptil. 
* @param new_sexo Carácter que representa o sexo do réptil (F, M). 
* @param new_tamanho Número que representa o tamanho do réptil. 
* @param new_dieta Palavra(s) que representa a dieta do réptil. 
* @param new_veterinario Veterinario responsável pelo réptil. 
* @param new_tratador Tratador responsável pelo réptil. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do réptil. 
* @param m_venenoso Variavel boleana que representa se o réptil é venenoso ou não (true ou false).
* @param m_tipo_veneno Palavra(s) que representa o tipo de veneno do réptil caso m_venenoso for igual a true.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_pais_origem Palavra(s) que representam o país de origem do réptil. 
* @param new_cidade_origem Palavra(s) que representam a cidade de origem do réptil .
*/

ReptilExotico::ReptilExotico(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, bool new_venenoso, 
	string new_tipo_veneno, string new_autorizacao_ibama, 
	string new_pais_origem, string new_cidade_origem):
		Reptil(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_venenoso, 
			new_tipo_veneno),
		AnimalExotico(new_autorizacao_ibama, 
			new_pais_origem, new_cidade_origem){}

/** 
* @brief Destrutor da classe ReptilExotico.
*/

ReptilExotico::~ReptilExotico(){}
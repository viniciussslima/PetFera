/**
* @file MamiferoExotico.cpp
* @brief Implementação da classe MamiferoExotico.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "MamiferoExotico.h"

/**
* @brief Construtor padrão da classe MamiferoExotico.
*/

MamiferoExotico::MamiferoExotico(){}

/**
* @brief construtor parametrizado da classe MamiferoExotico.
* @param new_id Número que representa a identidade do mamífero. 
* @param new_classe Palavra que representa a classe do animal (Ave, réptil, aves, mamífero). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do mamífero. 
* @param new_sexo Carácter que representa o sexo do mamífero (F, M). 
* @param new_tamanho Número que representa o tamanho do mamífero. 
* @param new_dieta Palavra(s) que representa a dieta do mamífero. 
* @param new_veterinario Veterinario responsável pelo mamífero. 
* @param new_tratador Tratador responsável pelo mamífero. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do mamífero. 
* @param new_cor_pelo Palavra(s) que representa a cor do pelo do mamífero.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_pais_origem Palavra(s) que representam o país de origem do mamífero. 
* @param new_cidade_origem Palavra(s) que representam a cidade de origem do mamífero.

*/

MamiferoExotico::MamiferoExotico(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, string new_cor_pelo, 
	string new_autorizacao_ibama, string new_pais_origem, string new_cidade_origem):
		Mamifero(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_cor_pelo),
		AnimalExotico(new_autorizacao_ibama, 
			new_pais_origem, new_cidade_origem){}

/**
* @brief Destrutor da classe MamiferoExotico.
*/

MamiferoExotico::~MamiferoExotico(){}
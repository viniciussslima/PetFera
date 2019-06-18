/**
* @file AnfibioExotico.cpp
* @brief Implementação da classe AnfibioExotico.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "AnfibioExotico.h"

/**
* @brief Construtor padrão da classe AnfibioExotico.
*/

AnfibioExotico::AnfibioExotico(){}

/**
* @brief construtor parametrizado da classe AnfibioExotico.
* @param new_id Número que representa a identidade do anfíbio. 
* @param new_classe Palavra que representa a classe do animal (anfíbio, réptil, aves, mamífero). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do anfíbio. 
* @param new_sexo Carácter que representa o sexo do anfíbio (F, M). 
* @param new_tamanho Número que representa o tamanho do anfíbio. 
* @param new_dieta Palavra(s) que representa a dieta do anfíbio. 
* @param new_veterinario Veterinario responsável pelo anfíbio. 
* @param new_tratador Tratador responsável pelo anfíbio. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do anfíbio. 
* @param new_total_de_mudas Número que representa a quantidade de vezes que o anfíbio trocou de pele. 
* @param new_ultima_muda Numeros que representam a data da última vez que o anfíbio trocou de pele. 
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_pais_origem Palavra(s) que representam o país de origem do anfíbio. 
* @param new_cidade_origem Palavra(s) que representam a cidade de origem do anfíbio.
*/

AnfibioExotico::AnfibioExotico(int new_id, string new_classe,
		string new_nome_cientifico,	char new_sexo,
		double new_tamanho,	string new_dieta,
		Veterinario new_veterinario, Tratador new_tratador,
		string new_nome_batismo, int new_total_de_mudas,
		date new_ultima_muda, string new_autorizacao_ibama, 
		string new_pais_origem, string new_cidade_origem):
			Anfibio(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_total_de_mudas, new_ultima_muda),
			AnimalExotico(new_autorizacao_ibama, 
				new_pais_origem, new_cidade_origem){}

/**
* @brief Destrutor da classe AnfibioExotico.
*/

AnfibioExotico::~AnfibioExotico(){}
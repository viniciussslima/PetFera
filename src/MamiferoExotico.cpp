/**
* @file MamiferoExotico.cpp
* @brief Implementação da classe que representa mamíferos exóticos.
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
*/

MamiferoExotico::MamiferoExotico(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, string new_cor_pelo, 
	string new_autorizacao_ibama, string new_pais_origem):
		Mamifero(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_cor_pelo),
		AnimalExotico(new_autorizacao_ibama, 
			new_pais_origem){}

/**
* @brief Destrutor da classe MamiferoExotico.
*/

MamiferoExotico::~MamiferoExotico(){}

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do MamiferoExotico.
* @param M Mamífero exótico que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações do mamífero exótico em forma de stream.
*/

ostream& operator<<(ostream &o, MamiferoExotico M)
{
	o << M.m_id << ";"
		<< M.m_classe << ";"
		<< M.m_nome_cientifico << ";"
		<< M.m_sexo << ";"
		<< M.m_tamanho << ";"
		<< M.m_dieta << ";"
		<< M.m_veterinario.get_id() << ";"
		<< M.m_tratador.get_id() << ";"
		<< M.m_nome_batismo << ";"
		<< M.m_cor_pelo << ";"
		<< M.m_autorizacao_ibama << ";"
		<< A.m_m_cidade_origem << ";"
		<< M.m_pais_origem << ";";
	return o;
}
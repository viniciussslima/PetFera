/**
* @file AveExotico.cpp
* @brief Implementação da classe que representa aves exóticas.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "AveExotico.h"

using namespace std;

/**
* @brief Construtor padrão da classe AveExotico.
*/

AveExotico::AveExotico(){}

/**
* @brief construtor parametrizado da classe AveExotico.
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
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_pais_origem Palavra(s) que representam o país de origem da ave. 
* @param new_cidade_origem Palavra(s) que representam a cidade de origem da ave.

*/

AveExotico::AveExotico(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, double new_tamanho_do_bico, 
	double new_evergadura_das_asas, string new_autorizacao_ibama,
	string new_pais_origem, string new_cidade_origem):
		Ave(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_tamanho_do_bico,
			new_evergadura_das_asas),
		AnimalExotico(new_autorizacao_ibama,
			new_pais_origem, new_cidade_origem){}

/**
* @brief Destrutor da classe AveExotico.
*/

AveExotico::~AveExotico(){}

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes da ave.
* @param A Ave exótica que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações da ave exótica em forma de stream.
*/

ostream& operator<<(ostream &o, AveExotico A)
{
	o << A.m_id << ";"
		<< A.m_classe << ";"
		<< A.m_nome_cientifico << ";"
		<< A.m_sexo << ";"
		<< A.m_tamanho << ";"
		<< A.m_dieta << ";"
		<< A.m_veterinario.get_id() << ";"
		<< A.m_tratador.get_id() << ";"
		<< A.m_nome_batismo << ";"
		<< A.m_tamanho_do_bico << ";"
		<< A.m_evergadura_das_asas << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_cidade_origem << ";"
		<< A.m_pais_origem << ";";
	return o;
}
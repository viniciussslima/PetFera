/**
* @file ReptilExotico.cpp
* @brief Implementação da classe que representa répteis exóticos.
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

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do ReptilExotico.
* @param R Réptil nativo que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações do réptil nativo em forma de stream.
*/

ostream& operator<<(ostream &o, ReptilExotico R)
{
	o << R.m_id << ";"
		<< R.m_classe << ";"
		<< R.m_nome_cientifico << ";"
		<< R.m_sexo << ";"
		<< R.m_tamanho << ";"
		<< R.m_dieta << ";"
		<< R.m_veterinario.get_id() << ";"
		<< R.m_tratador.get_id() << ";"
		<< R.m_nome_batismo << ";"
		<< R.m_venenoso << ";"
		<< R.m_tipo_veneno << ";"
		<< R.m_autorizacao_ibama << ";"
		<< R.m_cidade_origem << ";"
		<< R.m_pais_origem << ";";
	return o;
}
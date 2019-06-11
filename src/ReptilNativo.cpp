/**
* @file ReptilNativo.cpp
* @brief Implementação da classe que representa répteis nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "ReptilNativo.h"

/**
* @brief Construtor padrão da classe ReptilNativo.
*/

ReptilNativo::ReptilNativo(){}

/**
* @brief construtor parametrizado da classe ReptilNativo.
* @param new_id Número que representa a identidade do réptil. 
* @param new_classe Palavra que representa a classe do animal (Ave, réptil, aves, réptil). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do réptil. 
* @param new_sexo Carácter que representa o sexo do réptil (F, M). 
* @param new_tamanho Número que representa o tamanho do réptil. 
* @param new_dieta Palavra(s) que representa a dieta do réptil. 
* @param new_veterinario Veterinario responsável pelo réptil. 
* @param new_tratador Tratador responsável pelo réptil. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do réptil. 
* @param new_cor_pelo Palavra(s) que representa a cor do pelo do réptil.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_uf_origem Sigla que representa o estado de origem do réptil.
*/

ReptilNativo::ReptilNativo(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, bool new_venenoso, 
	string new_tipo_veneno, string new_autorizacao_ibama,
	string new_uf_origem):
		Reptil(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_venenoso, 
			new_tipo_veneno),
		AnimalNativo(new_autorizacao_ibama,
			new_uf_origem){}

/**
* @brief Destrutor da classe ReptilNativo.
*/

ReptilNativo::~ReptilNativo(){}

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do ReptilNativo.
* @param R Réptil nativo que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações do réptil nativo em forma de stream.
*/

ostream& operator<<(ostream &o, ReptilNativo R)
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
		<< R.m_uf_origem << ";";
	return o;
}
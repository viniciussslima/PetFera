/**
* @file Anfibio.cpp
* @brief Implementação da classe Anfibio.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Anfibio.h"

using namespace std;

/**
* @brief Construtor padrão da classe Anfibio.
*/

Anfibio::Anfibio(){}

/**
* @brief construtor parametrizado da classe Anfibio.
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
* @brief Destrutor da classe Anfibio.
*/

Anfibio::~Anfibio(){}

/**
* @brief Método que retorna o total de mudas do anfíbio.
* @return Retorna a quantidade de vezes que o anfíbio trocou de pele.
*/

int Anfibio::get_total_de_mudas()
{
	return m_total_de_mudas;
}

/**
* @brief Método que retorna a data da última muda do anfíbio.
* @return Retorna a data da última muda do anfíbio no formato DD/MM/AAAA.
*/

string Anfibio::get_data_da_ultima_muda()
{
	if (m_ultima_muda.day() == 0 && m_ultima_muda.month() == 0 && m_ultima_muda.year() == 0)
	{
		return "Sem data";
	}
	string temp;
	temp += to_string(m_ultima_muda.day());
	temp += "/";
	temp += to_string(m_ultima_muda.month());
	temp += "/";
	temp += to_string(m_ultima_muda.year());
	return temp;
}
/**
* @file Mamifero.cpp
* @brief Implementação da classe que representa mamíferos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Mamifero.h"

using namespace std;

/**
* @brief Construtor padrão da classe Mamifero.
*/

Mamifero::Mamifero(){}

/**
* @brief construtor parametrizado da classe Mamifero.
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
*/

Mamifero::Mamifero(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, string new_cor_pelo):
		Animal(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_cor_pelo = new_cor_pelo;
}

/**
* @brief Destrutor da classe Mamifero.
*/

Mamifero::~Mamifero(){}

/**
* @brief Método que retorna a cor do pelo mamífero.
* @return Retorna a cor do pelo mamífero.
*/

string Mamifero::get_cor_do_pelo()
{
	return m_cor_pelo;
}
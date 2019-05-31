/**
* @file Animal.cpp
*/

#include "Animal.h"

using namespace std;

/**
* @brief Construtor padrão da classe Animal.
*/

Animal::Animal(){}

/**
* @brief construtor parametrizado da classe Animal.
* @param new_id Número que representa a identidade do animal. 
* @param new_classe Palavra que representa a classe do animal (animal, réptil, aves, mamífero). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do animal. 
* @param new_sexo Carácter que representa o sexo do animal (F, M). 
* @param new_tamanho Número que representa o tamanho do animal. 
* @param new_dieta Palavra(s) que representa a dieta do animal. 
* @param new_veterinario Veterinário responsável pelo animal. 
* @param new_tratador Tratador responsável pelo animal. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do animal. 
*/

Animal::Animal(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo)
{
	m_id = new_id;
	m_classe = new_classe;
	m_nome_cientifico = new_nome_cientifico;
	m_sexo = new_sexo;
	m_tamanho = new_tamanho;
	m_dieta = new_dieta;
	m_veterinario = new_veterinario;
	m_tratador = new_tratador;
	m_nome_batismo = new_nome_batismo;
}

/**
* @brief Destrutor da classe Animal.
*/
	
Animal::~Animal(){}

/**
* @brief Método que retorna o id do animal.
*/

int Animal::getId()
{
	return m_id;
}
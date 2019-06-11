/**
* @file Animal.cpp
* @brief Implementação da classe que representa animais.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
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
* @param new_veterinario Veterinario responsável pelo animal. 
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
* @brief Método que retorna o ID do animal.
* @return Retorna o ID do animal.
*/

int Animal::get_id()
{
	return m_id;
}

/**
* @brief Método que retorna o nome científico do animal.
* @return Retorna o nome científico do animal.
*/

string Animal::get_nome_cientifico()
{
	return m_nome_cientifico;
}

/**
* @brief Método que retorna o sexo do animal.
* @return Retorna o sexo do animal.
*/

char Animal::get_sexo()
{
	return m_sexo;
}

/**
* @brief Método que retorna o tamanho do animal.
* @return Retorna o tamanho do animal.
*/

double Animal::get_tamanho()
{
	return m_tamanho;
}

/**
* @brief Método que retorna a dieta do animal.
* @return Retorna a dieta do animal.
*/

string Animal::get_dieta()
{
	return m_dieta;
}

/**
* @brief Método que retorna o ID do veterinário resposável do animal.
* @return Retorna o ID do veterinário resposável do animal.
*/

int Animal::get_veterinario_id()
{
	return m_veterinario.get_id();
}

/**
* @brief Método que retorna o ID do tratador resposável do animal.
* @return Retorna o ID do tratador resposável do animal.
*/

int Animal::get_tratador_id()
{
	return m_tratador.get_id();
}

/**
* @brief Método que retorna o nome de batismo do animal.
* @return Retorna o nome de batismo do animal.
*/

string Animal::get_nome_de_batismo()
{
	return m_nome_batismo;
}
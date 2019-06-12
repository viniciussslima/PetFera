/**
* @file Reptil.cpp
* @brief Implementação da classe Reptil.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Reptil.h"

using namespace std;

/**
* @brief Construtor padrão da classe Reptil.
*/

Reptil::Reptil(){}

/**
* @brief construtor parametrizado da classe réptil.
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
*/

Reptil::Reptil(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, bool new_venenoso, 
	string new_tipo_veneno):
		Animal(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo)
{
	m_venenoso = new_venenoso; 
	m_tipo_veneno = new_tipo_veneno;
}

/**
* @brief Destrutor da classe Mamifero.
*/

Reptil::~Reptil(){}

/**
* @brief Método que retorna se o réptil é venenoso ou não.
* @return Retorna se o réptil é venenoso ou não.
*/

bool Reptil::get_venenoso()
{
	return m_venenoso;
}

/**
* @brief Método que retorna o tipo de veneno do réptil.
* @return Retorna o tipo de veneno do réptil.
*/

string Reptil::get_tipo_de_veneno()
{
	if(m_venenoso)
		return m_tipo_veneno;
	return "Não venenoso";
}
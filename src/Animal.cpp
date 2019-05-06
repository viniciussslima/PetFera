#include "Animal.h"

using namespace std,

Animal::Animal(){}

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
	
Animal::~Animal();

#endif
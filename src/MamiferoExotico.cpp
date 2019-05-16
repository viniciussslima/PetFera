#include "MamiferoExotico.h"

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

MamiferoExotico::~MamiferoExotico(){}

ostream& operator<<(ostream &o, MamiferoExotico A)
{
	o << A.m_id << ";"
		<< A.m_classe << ";"
		<< A.m_nome_cientifico << ";"
		<< A.m_sexo << ";"
		<< A.m_tamanho << ";"
		<< A.m_dieta << ";"
		<< A.m_veterinario.getId() << ";"
		<< A.m_tratador.getId() << ";"
		<< A.m_nome_batismo << ";"
		<< A.m_cor_pelo << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_pais_origem << ";";
	return o;
}
#include "MamiferoNativo.h"

MamiferoNativo::MamiferoNativo(){}

MamiferoNativo::MamiferoNativo(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, string new_cor_pelo,
	string new_autorizacao_ibama, string new_uf_origem):
		Mamifero(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_cor_pelo),
		AnimalNativo(new_autorizacao_ibama,
			new_uf_origem){}

MamiferoNativo::~MamiferoNativo(){}

ostream& operator<<(ostream &o, MamiferoNativo A)
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
		<< A.m_cor_pelo << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_uf_origem << ";";
	return o;
}
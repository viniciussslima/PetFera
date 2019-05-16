#include "ReptilNativo.h"

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

ReptilNativo::~ReptilNativo(){}

ostream& operator<<(ostream &o, ReptilNativo A)
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
		<< A.m_venenoso << ";"
		<< A.m_tipo_veneno << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_uf_origem << ";";
	return o;
}
#include "AveNativo.h"

AveNativo::AveNativo(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, double new_tamanho_do_bico, 
	double new_envergadura_das_asas, string new_autorizacao_ibama,
	string new_uf_origem):
		Ave(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_tamanho_do_bico,
			new_envergadura_das_asas),
		AnimalNativo(new_autorizacao_ibama,
			new_uf_origem){}

AveNativo::~AveNativo(){}

ostream& operator<<(ostream &o, AveNativo A)
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
		<< A.m_tamanho_do_bico << ";"
		<< A.m_envergadura_das_asas << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_uf_origem << ";";
	return o;
}
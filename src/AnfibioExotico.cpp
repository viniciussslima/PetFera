#include "AnfibioExotico.h"

AnfibioExotico::AnfibioExotico(){}

AnfibioExotico::AnfibioExotico(int new_id, string new_classe,
		string new_nome_cientifico,	char new_sexo,
		double new_tamanho,	string new_dieta,
		Veterinario new_veterinario, Tratador new_tratador,
		string new_nome_batismo, int new_total_de_mudas,
		date new_ultima_muda, string new_autorizacao_ibama, 
		string new_pais_origem):
			Anfibio(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_total_de_mudas, new_ultima_muda),
			AnimalExotico(new_autorizacao_ibama, 
				new_pais_origem){}

AnfibioExotico::~AnfibioExotico(){}

ostream& operator<<(ostream &o, AnfibioExotico A)
{
	o << A.m_id << ";"
		<< A.m_classe << ";"
		<< A.m_nome_cientifico << ";"
		<< A.m_sexo << ";"
		<< A.m_tamanho << ";"
		<< A.m_dieta << ";";
	A.m_veterinario.getId() != -1 ? o << A.m_veterinario.getId() << ";" : o << ";";
	A.m_tratador.getId() != -1 ? o << A.m_tratador.getId() << ";" : o << ";";
	o << A.m_nome_batismo << ";"
		<< A.m_total_de_mudas << ";"
		<< A.m_ultima_muda << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_pais_origem << ";";
	return o;
}
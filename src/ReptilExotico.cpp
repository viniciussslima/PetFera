#include "ReptilExotico.h"

ReptilExotico::ReptilExotico(){}

ReptilExotico::ReptilExotico(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, bool new_venenoso, 
	string new_tipo_veneno, string new_autorizacao_ibama, 
	string new_pais_origem):
		Reptil(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_venenoso, 
			new_tipo_veneno),
		AnimalExotico(new_autorizacao_ibama, 
			new_pais_origem)
{

}

ReptilExotico::~ReptilExotico(){}

ostream& operator<<(ostream &o, ReptilExotico A)
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
		<< A.m_venenoso << ";"
		<< A.m_tipo_veneno << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_pais_origem << ";";
	return o;
}
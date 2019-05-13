#include "AveExotico.h"

using namespace std;

AveExotico::AveExotico(){}

AveExotico::AveExotico(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, int new_total_de_mudas, 
	date new_ultima_mulda, string new_autorizacao_ibama,
	string new_pais_origem):
		Ave(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_total_de_mudas,
			new_ultima_mulda),
		AnimalExotico(new_autorizacao_ibama,
			new_pais_origem){}

AveExotico::~AveExotico(){}

ostream& operator<<(ostream &o, AveExotico A)
{
	o << A.m_id << endl
		<< A.m_classe << endl
		<< A.m_nome_cientifico << endl
		<< A.m_sexo << endl
		<< A.m_tamanho << endl
		<< A.m_dieta << endl;
	
	if (A.m_veterinario.getNome().compare("") != 0)
	{
		o << A.m_veterinario.getNome() << endl;
	}

	if (A.m_tratador.getNome().compare("") != 0)
	{
		o << A.m_tratador.getNome() << endl;
	}

	o << A.m_nome_batismo << endl
		<< A.m_total_de_mudas << endl
		<< A.m_ultima_muda << endl
		<< A.m_autorizacao_ibama << endl
		<< A.m_pais_origem << endl;
	return o;
}
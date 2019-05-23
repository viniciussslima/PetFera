#include "MamiferoExotico.h"

MamiferoExotico::MamiferoExotico(){}

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

void MamiferoExotico::Exibir_informacoes()
{
	cout << endl
		<< "Id: " << m_id << endl
		<< "Classe: " << m_classe << endl
		<< "Nome cientifico: " << m_nome_cientifico << endl
		<< "Sexo: " << m_sexo << endl
		<< "Tamanho: " << m_tamanho << endl
		<< "Dieta: " << m_dieta << endl;
		if (m_veterinario.getId() != 0)
			cout << "Id do veterinario" << m_veterinario.getId() << endl;
		if (m_tratador.getId() != 0)
			cout << "Id do tratador" << m_tratador.getId() << endl;
	cout << "Nome batismo: " << m_nome_batismo << endl
		<< "Cor do pelo: " << m_cor_pelo << endl
		<< "Pais de origem: " << m_pais_origem << endl
		<< endl;
}

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
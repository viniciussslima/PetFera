/**
* @file AnfibioNativo.cpp
*/

#include "AnfibioNativo.h"

AnfibioNativo::AnfibioNativo(){}

AnfibioNativo::AnfibioNativo(int new_id, string new_classe,
		string new_nome_cientifico,	char new_sexo,
		double new_tamanho,	string new_dieta,
		Veterinario new_veterinario, Tratador new_tratador,
		string new_nome_batismo, int new_total_de_mudas,
		date new_ultima_muda, string new_autorizacao_ibama,
		string new_uf_origem):
		Anfibio(new_id, new_classe,
			new_nome_cientifico, new_sexo,
			new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_total_de_mudas,
			new_ultima_muda),
		AnimalNativo(new_autorizacao_ibama,
			new_uf_origem){}

AnfibioNativo::~AnfibioNativo(){}

void AnfibioNativo::Exibir_informacoes()
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
		<< "Total de mudas: " << m_total_de_mudas << endl
		<< "Data da ultima muda: " << m_ultima_muda << endl
		<< "Autorizacao ibama: " << m_autorizacao_ibama << endl
		<< "UF de origem: " << m_uf_origem << endl
		<< endl;
}

ostream& operator<<(ostream &o, AnfibioNativo A)
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
		<< A.m_total_de_mudas << ";"
		<< A.m_ultima_muda << ";"
		<< A.m_autorizacao_ibama << ";"
		<< A.m_uf_origem << ";";
	return o;
}
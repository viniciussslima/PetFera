#include "ReptilNativo.h"

ReptilNativo::ReptilNativo(){}

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

void ReptilNativo::Exibir_informacoes()
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
	cout << "Nome batismo: " << m_nome_batismo << endl;
		if (m_venenoso)
			cout << "Tipo de veneno: " << m_tipo_veneno << endl;
		else
			cout << "Tipo de veneno: não venenoso" << endl;
	cout << "UF de origem: " << m_uf_origem << endl
		<< endl;
}

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
/**
* @file AnfibioNativo.cpp
*/

#include "AnfibioNativo.h"

/**
* @brief Construtor padrão da classe AnfibioNativo.
*/

AnfibioNativo::AnfibioNativo(){}

/**
* @brief construtor parametrizado da classe AnfibioNativo.
* @param new_id Número que representa a identidade do anfíbio. 
* @param new_classe Palavra que representa a classe do animal (anfíbio, réptil, aves, mamífero). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do anfíbio. 
* @param new_sexo Carácter que representa o sexo do anfíbio (F, M). 
* @param new_tamanho Número que representa o tamanho do anfíbio. 
* @param new_dieta Palavra(s) que representa a dieta do anfíbio. 
* @param new_veterinario Veterinário responsável pelo anfíbio. 
* @param new_tratador Tratador responsável pelo anfíbio. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do anfíbio. 
* @param new_total_de_mudas Número que representa a quantidade de vezes que o anfíbio trocou de pele. 
* @param new_ultima_muda Numeros que representam a data da última vez que o anfíbio trocou de pele. 
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_uf_origem Sigla que representa o estado de origem do anfíbio. 
*/

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

/**
* @brief Destrutor da classe AnfibioNativo.
*/

AnfibioNativo::~AnfibioNativo(){}

/**
* @brief Método que imprime todas as informações do anfíbio na tela.
*/

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

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do anfíbio.
* @param A Anfibio nativo que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna a variavel o.
*/

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
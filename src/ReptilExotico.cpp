/**
* @file ReptilExotico.cpp
*/

#include "ReptilExotico.h"

/**
* @brief Construtor padrão da classe ReptilExotico.
*/

ReptilExotico::ReptilExotico(){}

/**
* @brief construtor parametrizado da classe ReptilExotico.
* @param new_id Número que representa a identidade do réptil. 
* @param new_classe Palavra que representa a classe do animal (Ave, réptil, aves, réptil). 
* @param new_nome_cientifico Palavra(s) que representa o nome científico do réptil. 
* @param new_sexo Carácter que representa o sexo do réptil (F, M). 
* @param new_tamanho Número que representa o tamanho do réptil. 
* @param new_dieta Palavra(s) que representa a dieta do réptil. 
* @param new_veterinario Veterinario responsável pelo réptil. 
* @param new_tratador Tratador responsável pelo réptil. 
* @param new_nome_batismo Palavra(s) que representam o nome de batismo do réptil. 
* @param m_venenoso Variavel boleana que representa se o réptil é venenoso ou não (true ou false).
* @param m_tipo_veneno Palavra(s) que representa o tipo de veneno do réptil caso m_venenoso for igual a true.
* @param new_autorizacao_ibama Conjunto de caracteres que representam a autorização do ibama. 
* @param new_pais_origem Palavra(s) que representam o país de origem do réptil. 
*/

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
			new_pais_origem){}

/** 
* @brief Destrutor da classe ReptilExotico.
*/

ReptilExotico::~ReptilExotico(){}

/**
* @brief Método que imprime todas as informações do réptil na tela.
*/

void ReptilExotico::Exibir_informacoes()
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
		cout << "Pais de origem: " << m_pais_origem << endl
		<< endl;
}

/**
* @brief Sobrecarga do operador de extração.
* @param o Parametro do tipo stream que recebe todas as informçãoes do ReptilExotico.
* @param A Réptil nativo que vai ter todas as suas infomações passadas para a variavel o;
* @return Retorna todas as infomações do réptil nativo em forma de stream.
*/

ostream& operator<<(ostream &o, ReptilExotico A)
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
		<< A.m_pais_origem << ";";
	return o;
}
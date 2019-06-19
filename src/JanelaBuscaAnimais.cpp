/**
* @file JanelaBuscaAnimais.cpp
* @brief Implementação da classe JanelaBuscaAnimais. 
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "JanelaBuscaAnimais.h"

using namespace Gtk;
using namespace std;

/**
* @brief Construtor padrão da classe JanelaBuscaAnimais.
*/

JanelaBuscaAnimais::JanelaBuscaAnimais(){}

/**
* @brief construtor parametrizado da classe JanelaBuscaAnimais.
* @param jptemp Janela principal do programa.
* @param funtemp  Map que contém todos os funcinários cadastrados.
* @param anitemp Map que contém todos os animais cadastrados.
*/

JanelaBuscaAnimais::JanelaBuscaAnimais(JanelaPrincipal &jptemp, map<int, Funcionario*> &funtemp, map<int, Animal*> &anitemp, int pagtemp, int idtemp):
											ModelColumnsTratador(), ModelColumnsVeterinario(), ModelColumnsAnfibioNativo(), 
											ModelColumnsAnfibioExotico(), ModelColumnsAveNativa(), ModelColumnsAveExotica(),
											ModelColumnsMamiferoNativo(), ModelColumnsMamiferoExotico(), ModelColumnsReptilNativo(), 
											ModelColumnsReptilExotico()
{ 
	// Atribuição de false para todas as variáveis boleanas que representão 
	// se existe ou não um certo tipo de animal sob responsabilidade do funcionário escolhido. 
	page_anfibios_exoticos = false;
	page_anfibios_nativos = false;
	page_aves_exoticas = false;
	page_aves_nativas = false;
	page_mamiferos_exoticos = false;
	page_mamiferos_nativos = false;
	page_repteis_exoticos = false;
	page_repteis_nativos = false;

	// Atribui os endereços de memória dos maps recebidos como parâmetros para os maps da classe JanelaEditarAnimal.
	janela_principal = &jptemp;

	funcionarios = &funtemp;
	animais = &anitemp;

	// Atribui os valores de pagtemp e idtemp para os atributos pagina e id da classe JanelaBuscaAnimais.
	pagina = pagtemp;
	id = idtemp;

	// inicialização dos atributos da classe GTK.
	window = new Window;
	box_principal = new VBox;
	entry_pesquisa = new SearchEntry;
	notebook_consulta = new Notebook;

	tree_view_anfibios_nativos = new TreeView;
	tree_view_anfibios_exoticos = new TreeView;
	tree_view_aves_nativas = new TreeView;
	tree_view_aves_exoticas = new TreeView;
	tree_view_mamiferos_nativos = new TreeView;
	tree_view_mamiferos_exoticos = new TreeView;
	tree_view_repteis_nativos = new TreeView;
	tree_view_repteis_exoticos = new TreeView;

	scrolled_window_anfibios_nativos = new ScrolledWindow;
	scrolled_window_anfibios_exoticos = new ScrolledWindow;
	scrolled_window_aves_nativas = new ScrolledWindow;
	scrolled_window_aves_exoticas = new ScrolledWindow;
	scrolled_window_mamiferos_nativos = new ScrolledWindow;
	scrolled_window_mamiferos_exoticos = new ScrolledWindow;
	scrolled_window_repteis_nativos = new ScrolledWindow;
	scrolled_window_repteis_exoticos = new ScrolledWindow;

	// Configuração dos atributos da classe GTK.
	window->set_default_size(1280, 720);
	window->set_resizable(true);
	window->set_border_width(5);
	window->set_title("Animais Do Funcionario");
	window->add(*box_principal);

	box_principal->pack_start(*entry_pesquisa, PACK_SHRINK);
	box_principal->add(*notebook_consulta);

	notebook_consulta->append_page(*scrolled_window_anfibios_nativos, "Anfibios nativos");
	notebook_consulta->append_page(*scrolled_window_anfibios_exoticos, "Anfibios exóticos");
	notebook_consulta->append_page(*scrolled_window_aves_nativas, "Aves nativas");
	notebook_consulta->append_page(*scrolled_window_aves_exoticas, "Aves exóticas");
	notebook_consulta->append_page(*scrolled_window_mamiferos_nativos, "Mamíferos nativos");
	notebook_consulta->append_page(*scrolled_window_mamiferos_exoticos, "Mamíferos exóticos");
	notebook_consulta->append_page(*scrolled_window_repteis_nativos, "Répteis nativos");
	notebook_consulta->append_page(*scrolled_window_repteis_exoticos, "Répteis exóticos");

	scrolled_window_anfibios_nativos->add(*tree_view_anfibios_nativos);
	scrolled_window_anfibios_exoticos->add(*tree_view_anfibios_exoticos);
	scrolled_window_aves_nativas->add(*tree_view_aves_nativas);
	scrolled_window_aves_exoticas->add(*tree_view_aves_exoticas);
	scrolled_window_mamiferos_nativos->add(*tree_view_mamiferos_nativos);
	scrolled_window_mamiferos_exoticos->add(*tree_view_mamiferos_exoticos);
	scrolled_window_repteis_nativos->add(*tree_view_repteis_nativos);
	scrolled_window_repteis_exoticos->add(*tree_view_repteis_exoticos);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	// Criando modelos de árvore.
	list_store_anfibios_nativos = ListStore::create(model_columns_anfibio_nativo);
	list_store_anfibios_exoticos = ListStore::create(model_columns_anfibio_exotico);
	list_store_aves_nativas = ListStore::create(model_columns_ave_nativa);
	list_store_aves_exoticas = ListStore::create(model_columns_ave_exotica);
	list_store_mamiferos_nativos = ListStore::create(model_columns_mamifero_nativo);
	list_store_mamiferos_exoticos = ListStore::create(model_columns_mamifero_exotico);
	list_store_repteis_nativos = ListStore::create(model_columns_reptil_nativo);
	list_store_repteis_exoticos = ListStore::create(model_columns_reptil_exotico);
	
	tree_view_anfibios_nativos->set_search_entry(*entry_pesquisa);
	tree_view_anfibios_nativos->set_model(list_store_anfibios_nativos);
	
	tree_view_anfibios_exoticos->set_search_entry(*entry_pesquisa);
	tree_view_anfibios_exoticos->set_model(list_store_anfibios_exoticos);
	
	tree_view_aves_nativas->set_search_entry(*entry_pesquisa);
	tree_view_aves_nativas->set_model(list_store_aves_nativas);
	
	tree_view_aves_exoticas->set_search_entry(*entry_pesquisa);
	tree_view_aves_exoticas->set_model(list_store_aves_exoticas);
	
	tree_view_mamiferos_nativos->set_search_entry(*entry_pesquisa);
	tree_view_mamiferos_nativos->set_model(list_store_mamiferos_nativos);
	
	tree_view_mamiferos_exoticos->set_search_entry(*entry_pesquisa);
	tree_view_mamiferos_exoticos->set_model(list_store_mamiferos_exoticos);
	
	tree_view_repteis_nativos->set_search_entry(*entry_pesquisa);
	tree_view_repteis_nativos->set_model(list_store_repteis_nativos);
	
	tree_view_repteis_exoticos->set_search_entry(*entry_pesquisa);
	tree_view_repteis_exoticos->set_model(list_store_repteis_exoticos);

	// Adicionado as colunas das TreeViews.
	tree_view_anfibios_nativos->append_column("ID", model_columns_anfibio_nativo.col_id);
	tree_view_anfibios_nativos->append_column("Nome Científico", model_columns_anfibio_nativo.col_nome_cientifico);
	tree_view_anfibios_nativos->append_column("Sexo", model_columns_anfibio_nativo.col_sexo);
	tree_view_anfibios_nativos->append_column("Tamanho", model_columns_anfibio_nativo.col_tamanho);
	tree_view_anfibios_nativos->append_column("Dieta", model_columns_anfibio_nativo.col_dieta);
	tree_view_anfibios_nativos->append_column("ID do Veterinario", model_columns_anfibio_nativo.col_veterinario);
	tree_view_anfibios_nativos->append_column("ID do Tratador", model_columns_anfibio_nativo.col_tratador);
	tree_view_anfibios_nativos->append_column("Nome de batismo", model_columns_anfibio_nativo.col_nome_batismo);
	tree_view_anfibios_nativos->append_column("Total de mudas", model_columns_anfibio_nativo.col_total_mudas);
	tree_view_anfibios_nativos->append_column("Data da última muda", model_columns_anfibio_nativo.col_data_ultima_muda);
	tree_view_anfibios_nativos->append_column("Autorização do ibama", model_columns_anfibio_nativo.col_autorizacao_ibama);
	tree_view_anfibios_nativos->append_column("UF", model_columns_anfibio_nativo.col_uf_origem);

	tree_view_anfibios_exoticos->append_column("ID", model_columns_anfibio_exotico.col_id);
	tree_view_anfibios_exoticos->append_column("Nome Científico", model_columns_anfibio_exotico.col_nome_cientifico);
	tree_view_anfibios_exoticos->append_column("Sexo", model_columns_anfibio_exotico.col_sexo);
	tree_view_anfibios_exoticos->append_column("Tamanho", model_columns_anfibio_exotico.col_tamanho);
	tree_view_anfibios_exoticos->append_column("Dieta", model_columns_anfibio_exotico.col_dieta);
	tree_view_anfibios_exoticos->append_column("ID do Veterinario", model_columns_anfibio_exotico.col_veterinario);
	tree_view_anfibios_exoticos->append_column("ID do Tratador", model_columns_anfibio_exotico.col_tratador);
	tree_view_anfibios_exoticos->append_column("Nome de batismo", model_columns_anfibio_exotico.col_nome_batismo);
	tree_view_anfibios_exoticos->append_column("Total de mudas", model_columns_anfibio_exotico.col_total_mudas);
	tree_view_anfibios_exoticos->append_column("Data da última muda", model_columns_anfibio_exotico.col_data_ultima_muda);
	tree_view_anfibios_exoticos->append_column("Autorização do ibama", model_columns_anfibio_exotico.col_autorizacao_ibama);
	tree_view_anfibios_exoticos->append_column("Nacionalidade", model_columns_anfibio_exotico.col_pais_origem);
	tree_view_anfibios_exoticos->append_column("Cidade", model_columns_anfibio_exotico.col_cidade_origem);

	tree_view_aves_nativas->append_column("ID", model_columns_ave_nativa.col_id);
	tree_view_aves_nativas->append_column("Nome Científico", model_columns_ave_nativa.col_nome_cientifico);
	tree_view_aves_nativas->append_column("Sexo", model_columns_ave_nativa.col_sexo);
	tree_view_aves_nativas->append_column("Tamanho", model_columns_ave_nativa.col_tamanho);
	tree_view_aves_nativas->append_column("Dieta", model_columns_ave_nativa.col_dieta);
	tree_view_aves_nativas->append_column("ID do Veterinario", model_columns_ave_nativa.col_veterinario);
	tree_view_aves_nativas->append_column("ID do Tratador", model_columns_ave_nativa.col_tratador);
	tree_view_aves_nativas->append_column("Nome de batismo", model_columns_ave_nativa.col_nome_batismo);
	tree_view_aves_nativas->append_column("Tamano do bico", model_columns_ave_nativa.col_tamanho_bico);
	tree_view_aves_nativas->append_column("Envergadura das asas", model_columns_ave_nativa.col_envergadura_asas);
	tree_view_aves_nativas->append_column("Autorização do ibama", model_columns_ave_nativa.col_autorizacao_ibama);
	tree_view_aves_nativas->append_column("UF", model_columns_ave_nativa.col_uf_origem);

	tree_view_aves_exoticas->append_column("ID", model_columns_ave_exotica.col_id);
	tree_view_aves_exoticas->append_column("Nome Científico", model_columns_ave_exotica.col_nome_cientifico);
	tree_view_aves_exoticas->append_column("Sexo", model_columns_ave_exotica.col_sexo);
	tree_view_aves_exoticas->append_column("Tamanho", model_columns_ave_exotica.col_tamanho);
	tree_view_aves_exoticas->append_column("Dieta", model_columns_ave_exotica.col_dieta);
	tree_view_aves_exoticas->append_column("ID do Veterinario", model_columns_ave_exotica.col_veterinario);
	tree_view_aves_exoticas->append_column("ID do Tratador", model_columns_ave_exotica.col_tratador);
	tree_view_aves_exoticas->append_column("Nome de batismo", model_columns_ave_exotica.col_nome_batismo);
	tree_view_aves_exoticas->append_column("Tamano do bico", model_columns_ave_exotica.col_tamanho_bico);
	tree_view_aves_exoticas->append_column("Envergadura das asas", model_columns_ave_exotica.col_envergadura_asas);
	tree_view_aves_exoticas->append_column("Autorização do ibama", model_columns_ave_exotica.col_autorizacao_ibama);
	tree_view_aves_exoticas->append_column("Nacionalidade", model_columns_ave_exotica.col_pais_origem);
	tree_view_aves_exoticas->append_column("Cidade", model_columns_ave_exotica.col_cidade_origem);

	tree_view_mamiferos_nativos->append_column("ID", model_columns_mamifero_nativo.col_id);
	tree_view_mamiferos_nativos->append_column("Nome Científico", model_columns_mamifero_nativo.col_nome_cientifico);
	tree_view_mamiferos_nativos->append_column("Sexo", model_columns_mamifero_nativo.col_sexo);
	tree_view_mamiferos_nativos->append_column("Tamanho", model_columns_mamifero_nativo.col_tamanho);
	tree_view_mamiferos_nativos->append_column("Dieta", model_columns_mamifero_nativo.col_dieta);
	tree_view_mamiferos_nativos->append_column("ID do Veterinario", model_columns_mamifero_nativo.col_veterinario);
	tree_view_mamiferos_nativos->append_column("ID do Tratador", model_columns_mamifero_nativo.col_tratador);
	tree_view_mamiferos_nativos->append_column("Nome de batismo", model_columns_mamifero_nativo.col_nome_batismo);
	tree_view_mamiferos_nativos->append_column("Cor do pelo", model_columns_mamifero_nativo.col_cor_pelo);
	tree_view_mamiferos_nativos->append_column("Autorização do ibama", model_columns_mamifero_nativo.col_autorizacao_ibama);
	tree_view_mamiferos_nativos->append_column("UF", model_columns_mamifero_nativo.col_uf_origem);

	tree_view_mamiferos_exoticos->append_column("ID", model_columns_mamifero_exotico.col_id);
	tree_view_mamiferos_exoticos->append_column("Nome Científico", model_columns_mamifero_exotico.col_nome_cientifico);
	tree_view_mamiferos_exoticos->append_column("Sexo", model_columns_mamifero_exotico.col_sexo);
	tree_view_mamiferos_exoticos->append_column("Tamanho", model_columns_mamifero_exotico.col_tamanho);
	tree_view_mamiferos_exoticos->append_column("Dieta", model_columns_mamifero_exotico.col_dieta);
	tree_view_mamiferos_exoticos->append_column("ID do Veterinario", model_columns_mamifero_exotico.col_veterinario);
	tree_view_mamiferos_exoticos->append_column("ID do Tratador", model_columns_mamifero_exotico.col_tratador);
	tree_view_mamiferos_exoticos->append_column("Nome de batismo", model_columns_mamifero_exotico.col_nome_batismo);
	tree_view_mamiferos_exoticos->append_column("Cor do pelo", model_columns_mamifero_exotico.col_cor_pelo);
	tree_view_mamiferos_exoticos->append_column("Autorização do ibama", model_columns_mamifero_exotico.col_autorizacao_ibama);
	tree_view_mamiferos_exoticos->append_column("Nacionalidade", model_columns_mamifero_exotico.col_pais_origem);
	tree_view_mamiferos_exoticos->append_column("Cidade", model_columns_mamifero_exotico.col_cidade_origem);

	tree_view_repteis_nativos->append_column("ID", model_columns_reptil_nativo.col_id);
	tree_view_repteis_nativos->append_column("Nome Científico", model_columns_reptil_nativo.col_nome_cientifico);
	tree_view_repteis_nativos->append_column("Sexo", model_columns_reptil_nativo.col_sexo);
	tree_view_repteis_nativos->append_column("Tamanho", model_columns_reptil_nativo.col_tamanho);
	tree_view_repteis_nativos->append_column("Dieta", model_columns_reptil_nativo.col_dieta);
	tree_view_repteis_nativos->append_column("ID do Veterinario", model_columns_reptil_nativo.col_veterinario);
	tree_view_repteis_nativos->append_column("ID do Tratador", model_columns_reptil_nativo.col_tratador);
	tree_view_repteis_nativos->append_column("Nome de batismo", model_columns_reptil_nativo.col_nome_batismo);
	tree_view_repteis_nativos->append_column("Veneno", model_columns_reptil_nativo.col_veneno);
	tree_view_repteis_nativos->append_column("Autorização do ibama", model_columns_reptil_nativo.col_autorizacao_ibama);
	tree_view_repteis_nativos->append_column("UF", model_columns_reptil_nativo.col_uf_origem);

	tree_view_repteis_exoticos->append_column("ID", model_columns_reptil_exotico.col_id);
	tree_view_repteis_exoticos->append_column("Nome Científico", model_columns_reptil_exotico.col_nome_cientifico);
	tree_view_repteis_exoticos->append_column("Sexo", model_columns_reptil_exotico.col_sexo);
	tree_view_repteis_exoticos->append_column("Tamanho", model_columns_reptil_exotico.col_tamanho);
	tree_view_repteis_exoticos->append_column("Dieta", model_columns_reptil_exotico.col_dieta);
	tree_view_repteis_exoticos->append_column("ID do Veterinario", model_columns_reptil_exotico.col_veterinario);
	tree_view_repteis_exoticos->append_column("ID do Tratador", model_columns_reptil_exotico.col_tratador);
	tree_view_repteis_exoticos->append_column("Nome de batismo", model_columns_reptil_exotico.col_nome_batismo);
	tree_view_repteis_exoticos->append_column("Veneno", model_columns_reptil_exotico.col_veneno);
	tree_view_repteis_exoticos->append_column("Autorização do ibama", model_columns_reptil_exotico.col_autorizacao_ibama);
	tree_view_repteis_exoticos->append_column("Nacionalidade", model_columns_reptil_exotico.col_pais_origem);
	tree_view_repteis_exoticos->append_column("Cidade", model_columns_reptil_exotico.col_cidade_origem);

	//Preenchendo o modelo de árvore.
	ProcurarAnimalPorFuncionario();
}

/**
* @brief Destrutor da classe JanelaBuscaAnimais.
*/

JanelaBuscaAnimais::~JanelaBuscaAnimais()
{
	delete window;
	delete box_principal;
	delete entry_pesquisa;
	delete notebook_consulta;
	delete tree_view_anfibios_nativos;
	delete tree_view_anfibios_exoticos;
	delete tree_view_aves_nativas;
	delete tree_view_aves_exoticas;
	delete tree_view_mamiferos_nativos;
	delete tree_view_mamiferos_exoticos;
	delete tree_view_repteis_nativos;
	delete tree_view_repteis_exoticos;
	delete scrolled_window_anfibios_nativos;
	delete scrolled_window_anfibios_exoticos;
	delete scrolled_window_aves_nativas;
	delete scrolled_window_aves_exoticas;
	delete scrolled_window_mamiferos_nativos;
	delete scrolled_window_mamiferos_exoticos;
	delete scrolled_window_repteis_nativos;
	delete scrolled_window_repteis_exoticos;
}

/**
* @brief Método que procura e coloca nas Treeviews os dados dos animais que estão sob a responsabilidade do funcionário escolhido pelo o usuário.
*/

void JanelaBuscaAnimais::ProcurarAnimalPorFuncionario()
{
	TreeModel::Row row;
	bool tipo;

	if (pagina == 0) // Se a pagina é igual a 0, o funcionários escolhido é um tratador.
	{
		for (map<int, Animal*>::iterator it = animais->begin(); it != animais->end(); it++)
		{
			if ((it->second)->get_tratador_id() == id && (it->second)->get_classe().compare("Amphibia") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_anfibios_exoticos = true;
					row = *(list_store_anfibios_exoticos->append());
					row[model_columns_anfibio_exotico.col_id] = it->second->get_id();
					row[model_columns_anfibio_exotico.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_anfibio_exotico.col_sexo] = temp;
					row[model_columns_anfibio_exotico.col_tamanho] = it->second->get_tamanho();
					row[model_columns_anfibio_exotico.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_anfibio_exotico.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_anfibio_exotico.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_anfibio_exotico.col_tratador] = "Sem tratador";
					else
						row[model_columns_anfibio_exotico.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_anfibio_exotico.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_anfibio_exotico.col_total_mudas] = dynamic_cast<Anfibio*>(it->second)->get_total_de_mudas();
					row[model_columns_anfibio_exotico.col_data_ultima_muda] = dynamic_cast<Anfibio*>(it->second)->get_data_da_ultima_muda();
					row[model_columns_anfibio_exotico.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_anfibio_exotico.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_anfibio_exotico.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_anfibios_nativos = true;
					row = *(list_store_anfibios_nativos->append());
					row[model_columns_anfibio_nativo.col_id] = it->second->get_id();
					row[model_columns_anfibio_nativo.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_anfibio_nativo.col_sexo] = temp;
					row[model_columns_anfibio_nativo.col_tamanho] = it->second->get_tamanho();
					row[model_columns_anfibio_nativo.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_anfibio_nativo.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_anfibio_nativo.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_anfibio_nativo.col_tratador] = "Sem tratador";
					else
						row[model_columns_anfibio_nativo.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_anfibio_nativo.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_anfibio_nativo.col_total_mudas] = dynamic_cast<Anfibio*>(it->second)->get_total_de_mudas();
					row[model_columns_anfibio_nativo.col_data_ultima_muda] = dynamic_cast<Anfibio*>(it->second)->get_data_da_ultima_muda();
					row[model_columns_anfibio_nativo.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_anfibio_nativo.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}

			else if ((it->second)->get_tratador_id() == id && (it->second)->get_classe().compare("Aves") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_aves_exoticas = true;
					row = *(list_store_aves_exoticas->append());
					row[model_columns_ave_exotica.col_id] = it->second->get_id();
					row[model_columns_ave_exotica.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_ave_exotica.col_sexo] = temp;
					row[model_columns_ave_exotica.col_tamanho] = it->second->get_tamanho();
					row[model_columns_ave_exotica.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_ave_exotica.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_ave_exotica.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_ave_exotica.col_tratador] = "Sem tratador";
					else
						row[model_columns_ave_exotica.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_ave_exotica.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_ave_exotica.col_tamanho_bico] = dynamic_cast<Ave*>(it->second)->get_tamanho_do_bico();
					row[model_columns_ave_exotica.col_envergadura_asas] = dynamic_cast<Ave*>(it->second)->get_envergadura_das_asas();
					row[model_columns_ave_exotica.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_ave_exotica.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_ave_exotica.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_aves_nativas = true;
					row = *(list_store_aves_nativas->append());
					row[model_columns_ave_nativa.col_id] = it->second->get_id();
					row[model_columns_ave_nativa.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_ave_nativa.col_sexo] = temp;
					row[model_columns_ave_nativa.col_tamanho] = it->second->get_tamanho();
					row[model_columns_ave_nativa.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_ave_nativa.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_ave_nativa.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_ave_nativa.col_tratador] = "Sem tratador";
					else
						row[model_columns_ave_nativa.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_ave_nativa.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_ave_nativa.col_tamanho_bico] = dynamic_cast<Ave*>(it->second)->get_tamanho_do_bico();
					row[model_columns_ave_nativa.col_envergadura_asas] = dynamic_cast<Ave*>(it->second)->get_envergadura_das_asas();
					row[model_columns_ave_nativa.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_ave_nativa.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}

			
			else if ((it->second)->get_tratador_id() == id)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_mamiferos_exoticos = true;
					row = *(list_store_mamiferos_exoticos->append());
					row[model_columns_mamifero_exotico.col_id] = it->second->get_id();
					row[model_columns_mamifero_exotico.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_mamifero_exotico.col_sexo] = temp;
					row[model_columns_mamifero_exotico.col_tamanho] = it->second->get_tamanho();
					row[model_columns_mamifero_exotico.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_mamifero_exotico.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_mamifero_exotico.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_mamifero_exotico.col_tratador] = "Sem tratador";
					else
						row[model_columns_mamifero_exotico.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_mamifero_exotico.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_mamifero_exotico.col_cor_pelo] = dynamic_cast<Mamifero*>(it->second)->get_cor_do_pelo();
					row[model_columns_mamifero_exotico.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_mamifero_exotico.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_mamifero_exotico.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_mamiferos_nativos = true;
					row = *(list_store_mamiferos_nativos->append());
					row[model_columns_mamifero_nativo.col_id] = it->second->get_id();
					row[model_columns_mamifero_nativo.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_mamifero_nativo.col_sexo] = temp;
					row[model_columns_mamifero_nativo.col_tamanho] = it->second->get_tamanho();
					row[model_columns_mamifero_nativo.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_mamifero_nativo.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_mamifero_nativo.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_mamifero_nativo.col_tratador] = "Sem tratador";
					else
						row[model_columns_mamifero_nativo.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_mamifero_nativo.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_mamifero_nativo.col_cor_pelo] = dynamic_cast<Mamifero*>(it->second)->get_cor_do_pelo();
					row[model_columns_mamifero_nativo.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_mamifero_nativo.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}


			else if ((it->second)->get_tratador_id() == id && (it->second)->get_classe().compare("Reptilia") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_repteis_exoticos = true;
					row = *(list_store_repteis_exoticos->append());
					row[model_columns_reptil_exotico.col_id] = it->second->get_id();
					row[model_columns_reptil_exotico.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_reptil_exotico.col_sexo] = temp;
					row[model_columns_reptil_exotico.col_tamanho] = it->second->get_tamanho();
					row[model_columns_reptil_exotico.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_reptil_exotico.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_reptil_exotico.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_reptil_exotico.col_tratador] = "Sem tratador";
					else
						row[model_columns_reptil_exotico.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_reptil_exotico.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_reptil_exotico.col_veneno] = dynamic_cast<Reptil*>(it->second)->get_tipo_de_veneno();
					row[model_columns_reptil_exotico.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_reptil_exotico.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_reptil_exotico.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_repteis_nativos = true;
					row = *(list_store_repteis_nativos->append());
					row[model_columns_reptil_nativo.col_id] = it->second->get_id();
					row[model_columns_reptil_nativo.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_reptil_nativo.col_sexo] = temp;
					row[model_columns_reptil_nativo.col_tamanho] = it->second->get_tamanho();
					row[model_columns_reptil_nativo.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_reptil_nativo.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_reptil_nativo.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_reptil_nativo.col_tratador] = "Sem tratador";
					else
						row[model_columns_reptil_nativo.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_reptil_nativo.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_reptil_nativo.col_veneno] = dynamic_cast<Reptil*>(it->second)->get_tipo_de_veneno();
					row[model_columns_reptil_nativo.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_reptil_nativo.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}
		}
	}
	else if (pagina == 1) // Se a pagina é igual a 1, o funcionários escolhido é um veterinário.
	{
		for (map<int, Animal*>::iterator it = animais->begin(); it != animais->end(); it++)
		{
			if ((it->second)->get_veterinario_id() == id && (it->second)->get_classe().compare("Amphibia") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_anfibios_exoticos = true;
					row = *(list_store_anfibios_exoticos->append());
					row[model_columns_anfibio_exotico.col_id] = it->second->get_id();
					row[model_columns_anfibio_exotico.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_anfibio_exotico.col_sexo] = temp;
					row[model_columns_anfibio_exotico.col_tamanho] = it->second->get_tamanho();
					row[model_columns_anfibio_exotico.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_anfibio_exotico.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_anfibio_exotico.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_anfibio_exotico.col_tratador] = "Sem tratador";
					else
						row[model_columns_anfibio_exotico.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_anfibio_exotico.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_anfibio_exotico.col_total_mudas] = dynamic_cast<Anfibio*>(it->second)->get_total_de_mudas();
					row[model_columns_anfibio_exotico.col_data_ultima_muda] = dynamic_cast<Anfibio*>(it->second)->get_data_da_ultima_muda();
					row[model_columns_anfibio_exotico.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_anfibio_exotico.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_anfibio_exotico.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_anfibios_nativos = true;
					row = *(list_store_anfibios_nativos->append());
					row[model_columns_anfibio_nativo.col_id] = it->second->get_id();
					row[model_columns_anfibio_nativo.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_anfibio_nativo.col_sexo] = temp;
					row[model_columns_anfibio_nativo.col_tamanho] = it->second->get_tamanho();
					row[model_columns_anfibio_nativo.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_anfibio_nativo.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_anfibio_nativo.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_anfibio_nativo.col_tratador] = "Sem tratador";
					else
						row[model_columns_anfibio_nativo.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_anfibio_nativo.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_anfibio_nativo.col_total_mudas] = dynamic_cast<Anfibio*>(it->second)->get_total_de_mudas();
					row[model_columns_anfibio_nativo.col_data_ultima_muda] = dynamic_cast<Anfibio*>(it->second)->get_data_da_ultima_muda();
					row[model_columns_anfibio_nativo.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_anfibio_nativo.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}

			else if ((it->second)->get_veterinario_id() == id && (it->second)->get_classe().compare("Aves") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_aves_exoticas = true;
					row = *(list_store_aves_exoticas->append());
					row[model_columns_ave_exotica.col_id] = it->second->get_id();
					row[model_columns_ave_exotica.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_ave_exotica.col_sexo] = temp;
					row[model_columns_ave_exotica.col_tamanho] = it->second->get_tamanho();
					row[model_columns_ave_exotica.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_ave_exotica.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_ave_exotica.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_ave_exotica.col_tratador] = "Sem tratador";
					else
						row[model_columns_ave_exotica.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_ave_exotica.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_ave_exotica.col_tamanho_bico] = dynamic_cast<Ave*>(it->second)->get_tamanho_do_bico();
					row[model_columns_ave_exotica.col_envergadura_asas] = dynamic_cast<Ave*>(it->second)->get_envergadura_das_asas();
					row[model_columns_ave_exotica.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_ave_exotica.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_ave_exotica.col_cidade_origem] = dynamic_cast<AnimalExotico*>((it->second))->get_cidade_de_origem();
				}
				else
				{
					page_aves_nativas = true;
					row = *(list_store_aves_nativas->append());
					row[model_columns_ave_nativa.col_id] = it->second->get_id();
					row[model_columns_ave_nativa.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_ave_nativa.col_sexo] = temp;
					row[model_columns_ave_nativa.col_tamanho] = it->second->get_tamanho();
					row[model_columns_ave_nativa.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_ave_nativa.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_ave_nativa.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_ave_nativa.col_tratador] = "Sem tratador";
					else
						row[model_columns_ave_nativa.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_ave_nativa.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_ave_nativa.col_tamanho_bico] = dynamic_cast<Ave*>(it->second)->get_tamanho_do_bico();
					row[model_columns_ave_nativa.col_envergadura_asas] = dynamic_cast<Ave*>(it->second)->get_envergadura_das_asas();
					row[model_columns_ave_nativa.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_ave_nativa.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}

			else if ((it->second)->get_veterinario_id() == id && (it->second)->get_classe().compare("Mammalia") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_mamiferos_exoticos = true;
					row = *(list_store_mamiferos_exoticos->append());
					row[model_columns_mamifero_exotico.col_id] = it->second->get_id();
					row[model_columns_mamifero_exotico.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_mamifero_exotico.col_sexo] = temp;
					row[model_columns_mamifero_exotico.col_tamanho] = it->second->get_tamanho();
					row[model_columns_mamifero_exotico.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_mamifero_exotico.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_mamifero_exotico.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_mamifero_exotico.col_tratador] = "Sem tratador";
					else
						row[model_columns_mamifero_exotico.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_mamifero_exotico.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_mamifero_exotico.col_cor_pelo] = dynamic_cast<Mamifero*>(it->second)->get_cor_do_pelo();
					row[model_columns_mamifero_exotico.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_mamifero_exotico.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_mamifero_exotico.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_mamiferos_nativos = true;
					row = *(list_store_mamiferos_nativos->append());
					row[model_columns_mamifero_nativo.col_id] = it->second->get_id();
					row[model_columns_mamifero_nativo.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_mamifero_nativo.col_sexo] = temp;
					row[model_columns_mamifero_nativo.col_tamanho] = it->second->get_tamanho();
					row[model_columns_mamifero_nativo.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_mamifero_nativo.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_mamifero_nativo.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_mamifero_nativo.col_tratador] = "Sem tratador";
					else
						row[model_columns_mamifero_nativo.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_mamifero_nativo.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_mamifero_nativo.col_cor_pelo] = dynamic_cast<Mamifero*>(it->second)->get_cor_do_pelo();
					row[model_columns_mamifero_nativo.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_mamifero_nativo.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}

			else if ((it->second)->get_veterinario_id() == id && (it->second)->get_classe().compare("Reptilia") == 0)
			{
				tipo = true;
				try
				{
					dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
				}
				catch(exception &ex)
				{
					tipo = false;
				}

				if (!tipo)
				{
					page_repteis_exoticos = true;
					row = *(list_store_repteis_exoticos->append());
					row[model_columns_reptil_exotico.col_id] = it->second->get_id();
					row[model_columns_reptil_exotico.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_reptil_exotico.col_sexo] = temp;
					row[model_columns_reptil_exotico.col_tamanho] = it->second->get_tamanho();
					row[model_columns_reptil_exotico.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_reptil_exotico.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_reptil_exotico.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_reptil_exotico.col_tratador] = "Sem tratador";
					else
						row[model_columns_reptil_exotico.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_reptil_exotico.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_reptil_exotico.col_veneno] = dynamic_cast<Reptil*>(it->second)->get_tipo_de_veneno();
					row[model_columns_reptil_exotico.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_reptil_exotico.col_pais_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_pais_de_origem();
					row[model_columns_reptil_exotico.col_cidade_origem] = dynamic_cast<AnimalExotico*>(it->second)->get_cidade_de_origem();
				}
				else
				{
					page_repteis_nativos = true;
					row = *(list_store_repteis_nativos->append());
					row[model_columns_reptil_nativo.col_id] = it->second->get_id();
					row[model_columns_reptil_nativo.col_nome_cientifico] = it->second->get_nome_cientifico();
					string temp;
					temp.push_back(it->second->get_sexo());
					row[model_columns_reptil_nativo.col_sexo] = temp;
					row[model_columns_reptil_nativo.col_tamanho] = it->second->get_tamanho();
					row[model_columns_reptil_nativo.col_dieta] = it->second->get_dieta();
					
					if (it->second->get_veterinario_id() == 0)
						row[model_columns_reptil_nativo.col_veterinario] = "Sem veterinario";
					else
						row[model_columns_reptil_nativo.col_veterinario] = to_string((it->second)->get_veterinario_id());

					if (it->second->get_tratador_id() == 0)
						row[model_columns_reptil_nativo.col_tratador] = "Sem tratador";
					else
						row[model_columns_reptil_nativo.col_tratador] = to_string((it->second)->get_tratador_id());
					
					row[model_columns_reptil_nativo.col_nome_batismo] = it->second->get_nome_de_batismo();
					row[model_columns_reptil_nativo.col_veneno] = dynamic_cast<Reptil*>(it->second)->get_tipo_de_veneno();
					row[model_columns_reptil_nativo.col_autorizacao_ibama] = dynamic_cast<AnimalSilvestre*>(it->second)->get_autorizacao_ibama();
					row[model_columns_reptil_nativo.col_uf_origem] = dynamic_cast<AnimalNativo*>(it->second)->get_uf_de_origem();
				}
			}
		}
	}

	// Caso certos tipos de animais não estiverem sob a responsabilidade do funcionário a pagina fica vazia, então ela é removida.
	if (!page_anfibios_exoticos)
		notebook_consulta->remove_page(*scrolled_window_anfibios_exoticos);
	if (!page_anfibios_nativos)
		notebook_consulta->remove_page(*scrolled_window_anfibios_nativos);
	if (!page_aves_exoticas)
		notebook_consulta->remove_page(*scrolled_window_aves_exoticas);
	if (!page_aves_nativas)
		notebook_consulta->remove_page(*scrolled_window_aves_nativas);
	if (!page_mamiferos_exoticos)
		notebook_consulta->remove_page(*scrolled_window_mamiferos_exoticos);
	if (!page_mamiferos_nativos)
		notebook_consulta->remove_page(*scrolled_window_mamiferos_nativos);
	if (!page_repteis_exoticos)
		notebook_consulta->remove_page(*scrolled_window_repteis_exoticos);
	if (!page_repteis_nativos)
		notebook_consulta->remove_page(*scrolled_window_repteis_nativos);
}

/**
* @brief Método que inicia a janela de busca de animais por funcionários.
*/

void JanelaBuscaAnimais::Run()
{
	// Caso não houver nenhum animal cadastrado a janela não abre e aparece um aviso.
	if (!page_anfibios_exoticos && !page_anfibios_nativos &&
		!page_aves_exoticas && !page_aves_nativas &&
		!page_mamiferos_exoticos && !page_mamiferos_nativos &&
		!page_repteis_exoticos && !page_repteis_nativos)
	{
		MessageDialog dialog(*window, "Sem animais cadastradados.");
		dialog.set_secondary_text("Esse funcionario não é responsavel por nenhum animal");
  		dialog.run();
		return;
	}

	window->show_all();
	Main::run(*window);
}
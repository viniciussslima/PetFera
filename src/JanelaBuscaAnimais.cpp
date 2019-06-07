#include "JanelaBuscaAnimais.h"

using namespace Gtk;
using namespace std;

JanelaBuscaAnimais::JanelaBuscaAnimais(map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp, map<int, AnfibioExotico> &anetemp, 
										map<int, AnfibioNativo> &anntemp, map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp, 
										map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, map<int, ReptilExotico> &retemp, 
										map<int, ReptilNativo> &rntemp, int pagtemp, int idtemp):
											ModelColumnsTratador(), ModelColumnsVeterinario(), ModelColumnsAnfibioNativo(), 
											ModelColumnsAnfibioExotico(), ModelColumnsAveNativa(), ModelColumnsAveExotica(),
											ModelColumnsMamiferoNativo(), ModelColumnsMamiferoExotico(), ModelColumnsReptilNativo(), 
											ModelColumnsReptilExotico()
{
	
	veterinarios = &vtemp;
	tratadores = &ttemp;

	anfibios_exoticos = &anetemp;
	anfibios_nativos = &anntemp;

	aves_exoticas = &avetemp;
	aves_nativas = &avntemp;

	mamiferos_exoticos = &metemp;
	mamiferos_nativos = &mntemp;

	repteis_exoticos = &retemp;
	repteis_nativos = &rntemp;

	pagina = pagtemp;
	id = idtemp;

	//inicialização
	window = new Window;
	button_confirmar = new Button("Buscar");
	entry_id = new Entry;
	box_principal = new VBox;
	box_dados = new HBox(true);
	label_id = new Label("ID: ");

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

	//configuração
	window->set_default_size(1280, 720);
	window->set_resizable(true);
	window->set_border_width(5);
	window->set_title("Animais Do Funcionario");
	window->add(*box_principal);

	box_principal->add(*box_dados);
	box_principal->pack_start(*button_confirmar, PACK_SHRINK);

	box_dados->add(*label_id);
	box_dados->add(*entry_id);

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

	
	
	if (id == 0)
	{
		valid_id = false;
		entry_id->set_text("0");
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_id->set_icon_tooltip_text("ID inválido");
	}
	else
	{
		valid_id = true;
		entry_id->set_text(to_string(id));
		entry_id->set_icon_from_pixbuf(pixbuf_check);
		entry_id->set_icon_tooltip_text("ID válido");
	}


	//Criando o modelo de arvore
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

	//Adicionado as colunas da TreeView

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

	//Preenchendo o modelo de arvore
	ProcurarAnimalPorFuncionario();

	//Conexão
	button_confirmar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaBuscaAnimais::Buscar));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaBuscaAnimais::AtualizarIconeId));
}

JanelaBuscaAnimais::~JanelaBuscaAnimais()
{
	delete window;
	delete box_principal;
	delete box_dados;
	delete entry_id;
	delete button_confirmar;
	delete label_id;
}

void JanelaBuscaAnimais::ProcurarAnimalPorFuncionario()
{
	list_store_anfibios_exoticos->clear();
	list_store_anfibios_nativos->clear();
	list_store_aves_exoticas->clear();
	list_store_aves_nativas->clear();
	list_store_mamiferos_exoticos->clear();
	list_store_mamiferos_nativos->clear();
	list_store_repteis_exoticos->clear();
	list_store_repteis_nativos->clear();

	TreeModel::Row row;

	bool page_anfibios_exoticos = false;
	bool page_anfibios_nativos = false;
	bool page_aves_exoticas = false;
	bool page_aves_nativas = false;
	bool page_mamiferos_exoticos = false;
	bool page_mamiferos_nativos = false;
	bool page_repteis_exoticos = false;
	bool page_repteis_nativos = false;

	if (pagina == 0)
	{
		for (map<int, AnfibioExotico>::iterator it = anfibios_exoticos->begin(); it != anfibios_exoticos->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_anfibios_exoticos = true;
				row = *(list_store_anfibios_exoticos->append());
				row[model_columns_anfibio_exotico.col_id] = it->second.get_id();
				row[model_columns_anfibio_exotico.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_anfibio_exotico.col_sexo] = temp;
				row[model_columns_anfibio_exotico.col_tamanho] = it->second.get_tamanho();
				row[model_columns_anfibio_exotico.col_dieta] = it->second.get_dieta();
				row[model_columns_anfibio_exotico.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_anfibio_exotico.col_tratador] = it->second.get_tratador_id();
				row[model_columns_anfibio_exotico.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_anfibio_exotico.col_total_mudas] = it->second.get_total_de_mudas();
				row[model_columns_anfibio_exotico.col_data_ultima_muda] = it->second.get_data_da_ultima_muda();
				row[model_columns_anfibio_exotico.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_anfibio_exotico.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}
		for (map<int, AnfibioNativo>::iterator it = anfibios_nativos->begin(); it != anfibios_nativos->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_anfibios_nativos = true;
				row = *(list_store_anfibios_nativos->append());
				row[model_columns_anfibio_nativo.col_id] = it->second.get_id();
				row[model_columns_anfibio_nativo.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_anfibio_nativo.col_sexo] = temp;
				row[model_columns_anfibio_nativo.col_tamanho] = it->second.get_tamanho();
				row[model_columns_anfibio_nativo.col_dieta] = it->second.get_dieta();
				row[model_columns_anfibio_nativo.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_anfibio_nativo.col_tratador] = it->second.get_tratador_id();
				row[model_columns_anfibio_nativo.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_anfibio_nativo.col_total_mudas] = it->second.get_total_de_mudas();
				row[model_columns_anfibio_nativo.col_data_ultima_muda] = it->second.get_data_da_ultima_muda();
				row[model_columns_anfibio_nativo.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_anfibio_nativo.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}
		for (map<int, AveExotico>::iterator it = aves_exoticas->begin(); it != aves_exoticas->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_aves_exoticas = true;
				row = *(list_store_aves_exoticas->append());
				row[model_columns_ave_exotica.col_id] = it->second.get_id();
				row[model_columns_ave_exotica.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_ave_exotica.col_sexo] = temp;
				row[model_columns_ave_exotica.col_tamanho] = it->second.get_tamanho();
				row[model_columns_ave_exotica.col_dieta] = it->second.get_dieta();
				row[model_columns_ave_exotica.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_ave_exotica.col_tratador] = it->second.get_tratador_id();
				row[model_columns_ave_exotica.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_ave_exotica.col_tamanho_bico] = it->second.get_tamanho_do_bico();
				row[model_columns_ave_exotica.col_envergadura_asas] = it->second.get_envergadura_das_asas();
				row[model_columns_ave_exotica.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_ave_exotica.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}

		for (map<int, AveNativo>::iterator it = aves_nativas->begin(); it != aves_nativas->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_aves_nativas = true;
				row = *(list_store_aves_nativas->append());
				row[model_columns_ave_nativa.col_id] = it->second.get_id();
				row[model_columns_ave_nativa.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_ave_nativa.col_sexo] = temp;
				row[model_columns_ave_nativa.col_tamanho] = it->second.get_tamanho();
				row[model_columns_ave_nativa.col_dieta] = it->second.get_dieta();
				row[model_columns_ave_nativa.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_ave_nativa.col_tratador] = it->second.get_tratador_id();
				row[model_columns_ave_nativa.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_ave_nativa.col_tamanho_bico] = it->second.get_tamanho_do_bico();
				row[model_columns_ave_nativa.col_envergadura_asas] = it->second.get_envergadura_das_asas();
				row[model_columns_ave_nativa.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_ave_nativa.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}

		for (map<int, MamiferoExotico>::iterator it = mamiferos_exoticos->begin(); it != mamiferos_exoticos->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_mamiferos_exoticos = true;
				row = *(list_store_mamiferos_exoticos->append());
				row[model_columns_mamifero_exotico.col_id] = it->second.get_id();
				row[model_columns_mamifero_exotico.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_mamifero_exotico.col_sexo] = temp;
				row[model_columns_mamifero_exotico.col_tamanho] = it->second.get_tamanho();
				row[model_columns_mamifero_exotico.col_dieta] = it->second.get_dieta();
				row[model_columns_mamifero_exotico.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_mamifero_exotico.col_tratador] = it->second.get_tratador_id();
				row[model_columns_mamifero_exotico.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_mamifero_exotico.col_cor_pelo] = it->second.get_cor_do_pelo();
				row[model_columns_mamifero_exotico.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_mamifero_exotico.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}

		for (map<int, MamiferoNativo>::iterator it = mamiferos_nativos->begin(); it != mamiferos_nativos->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_mamiferos_nativos = true;
				row = *(list_store_mamiferos_nativos->append());
				row[model_columns_mamifero_nativo.col_id] = it->second.get_id();
				row[model_columns_mamifero_nativo.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_mamifero_nativo.col_sexo] = temp;
				row[model_columns_mamifero_nativo.col_tamanho] = it->second.get_tamanho();
				row[model_columns_mamifero_nativo.col_dieta] = it->second.get_dieta();
				row[model_columns_mamifero_nativo.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_mamifero_nativo.col_tratador] = it->second.get_tratador_id();
				row[model_columns_mamifero_nativo.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_mamifero_nativo.col_cor_pelo] = it->second.get_cor_do_pelo();
				row[model_columns_mamifero_nativo.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_mamifero_nativo.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}

		for (map<int, ReptilExotico>::iterator it = repteis_exoticos->begin(); it != repteis_exoticos->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_repteis_exoticos = true;
				row = *(list_store_repteis_exoticos->append());
				row[model_columns_reptil_exotico.col_id] = it->second.get_id();
				row[model_columns_reptil_exotico.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_reptil_exotico.col_sexo] = temp;
				row[model_columns_reptil_exotico.col_tamanho] = it->second.get_tamanho();
				row[model_columns_reptil_exotico.col_dieta] = it->second.get_dieta();
				row[model_columns_reptil_exotico.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_reptil_exotico.col_tratador] = it->second.get_tratador_id();
				row[model_columns_reptil_exotico.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_reptil_exotico.col_veneno] = it->second.get_tipo_de_veneno();
				row[model_columns_reptil_exotico.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_reptil_exotico.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}

		for (map<int, ReptilNativo>::iterator it = repteis_nativos->begin(); it != repteis_nativos->end(); it++)
		{
			if ((it->second).get_tratador_id() == id)
			{
				page_repteis_nativos = true;
				row = *(list_store_repteis_nativos->append());
				row[model_columns_reptil_nativo.col_id] = it->second.get_id();
				row[model_columns_reptil_nativo.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_reptil_nativo.col_sexo] = temp;
				row[model_columns_reptil_nativo.col_tamanho] = it->second.get_tamanho();
				row[model_columns_reptil_nativo.col_dieta] = it->second.get_dieta();
				row[model_columns_reptil_nativo.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_reptil_nativo.col_tratador] = it->second.get_tratador_id();
				row[model_columns_reptil_nativo.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_reptil_nativo.col_veneno] = it->second.get_tipo_de_veneno();
				row[model_columns_reptil_nativo.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_reptil_nativo.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}
	}
	else if (pagina == 1)
	{
		for (map<int, AnfibioExotico>::iterator it = anfibios_exoticos->begin(); it != anfibios_exoticos->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_anfibios_exoticos = true;
				row = *(list_store_anfibios_exoticos->append());
				row[model_columns_anfibio_exotico.col_id] = it->second.get_id();
				row[model_columns_anfibio_exotico.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_anfibio_exotico.col_sexo] = temp;
				row[model_columns_anfibio_exotico.col_tamanho] = it->second.get_tamanho();
				row[model_columns_anfibio_exotico.col_dieta] = it->second.get_dieta();
				row[model_columns_anfibio_exotico.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_anfibio_exotico.col_tratador] = it->second.get_tratador_id();
				row[model_columns_anfibio_exotico.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_anfibio_exotico.col_total_mudas] = it->second.get_total_de_mudas();
				row[model_columns_anfibio_exotico.col_data_ultima_muda] = it->second.get_data_da_ultima_muda();
				row[model_columns_anfibio_exotico.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_anfibio_exotico.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}
		for (map<int, AnfibioNativo>::iterator it = anfibios_nativos->begin(); it != anfibios_nativos->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_anfibios_nativos = true;
				row = *(list_store_anfibios_nativos->append());
				row[model_columns_anfibio_nativo.col_id] = it->second.get_id();
				row[model_columns_anfibio_nativo.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_anfibio_nativo.col_sexo] = temp;
				row[model_columns_anfibio_nativo.col_tamanho] = it->second.get_tamanho();
				row[model_columns_anfibio_nativo.col_dieta] = it->second.get_dieta();
				row[model_columns_anfibio_nativo.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_anfibio_nativo.col_tratador] = it->second.get_tratador_id();
				row[model_columns_anfibio_nativo.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_anfibio_nativo.col_total_mudas] = it->second.get_total_de_mudas();
				row[model_columns_anfibio_nativo.col_data_ultima_muda] = it->second.get_data_da_ultima_muda();
				row[model_columns_anfibio_nativo.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_anfibio_nativo.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}
		for (map<int, AveExotico>::iterator it = aves_exoticas->begin(); it != aves_exoticas->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_aves_exoticas = true;
				row = *(list_store_aves_exoticas->append());
				row[model_columns_ave_exotica.col_id] = it->second.get_id();
				row[model_columns_ave_exotica.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_ave_exotica.col_sexo] = temp;
				row[model_columns_ave_exotica.col_tamanho] = it->second.get_tamanho();
				row[model_columns_ave_exotica.col_dieta] = it->second.get_dieta();
				row[model_columns_ave_exotica.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_ave_exotica.col_tratador] = it->second.get_tratador_id();
				row[model_columns_ave_exotica.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_ave_exotica.col_tamanho_bico] = it->second.get_tamanho_do_bico();
				row[model_columns_ave_exotica.col_envergadura_asas] = it->second.get_envergadura_das_asas();
				row[model_columns_ave_exotica.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_ave_exotica.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}

		for (map<int, AveNativo>::iterator it = aves_nativas->begin(); it != aves_nativas->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_aves_nativas = true;
				row = *(list_store_aves_nativas->append());
				row[model_columns_ave_nativa.col_id] = it->second.get_id();
				row[model_columns_ave_nativa.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_ave_nativa.col_sexo] = temp;
				row[model_columns_ave_nativa.col_tamanho] = it->second.get_tamanho();
				row[model_columns_ave_nativa.col_dieta] = it->second.get_dieta();
				row[model_columns_ave_nativa.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_ave_nativa.col_tratador] = it->second.get_tratador_id();
				row[model_columns_ave_nativa.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_ave_nativa.col_tamanho_bico] = it->second.get_tamanho_do_bico();
				row[model_columns_ave_nativa.col_envergadura_asas] = it->second.get_envergadura_das_asas();
				row[model_columns_ave_nativa.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_ave_nativa.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}

		for (map<int, MamiferoExotico>::iterator it = mamiferos_exoticos->begin(); it != mamiferos_exoticos->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_mamiferos_exoticos = true;
				row = *(list_store_mamiferos_exoticos->append());
				row[model_columns_mamifero_exotico.col_id] = it->second.get_id();
				row[model_columns_mamifero_exotico.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_mamifero_exotico.col_sexo] = temp;
				row[model_columns_mamifero_exotico.col_tamanho] = it->second.get_tamanho();
				row[model_columns_mamifero_exotico.col_dieta] = it->second.get_dieta();
				row[model_columns_mamifero_exotico.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_mamifero_exotico.col_tratador] = it->second.get_tratador_id();
				row[model_columns_mamifero_exotico.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_mamifero_exotico.col_cor_pelo] = it->second.get_cor_do_pelo();
				row[model_columns_mamifero_exotico.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_mamifero_exotico.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}

		for (map<int, MamiferoNativo>::iterator it = mamiferos_nativos->begin(); it != mamiferos_nativos->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_mamiferos_nativos = true;
				row = *(list_store_mamiferos_nativos->append());
				row[model_columns_mamifero_nativo.col_id] = it->second.get_id();
				row[model_columns_mamifero_nativo.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_mamifero_nativo.col_sexo] = temp;
				row[model_columns_mamifero_nativo.col_tamanho] = it->second.get_tamanho();
				row[model_columns_mamifero_nativo.col_dieta] = it->second.get_dieta();
				row[model_columns_mamifero_nativo.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_mamifero_nativo.col_tratador] = it->second.get_tratador_id();
				row[model_columns_mamifero_nativo.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_mamifero_nativo.col_cor_pelo] = it->second.get_cor_do_pelo();
				row[model_columns_mamifero_nativo.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_mamifero_nativo.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}

		for (map<int, ReptilExotico>::iterator it = repteis_exoticos->begin(); it != repteis_exoticos->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_repteis_exoticos = true;
				row = *(list_store_repteis_exoticos->append());
				row[model_columns_reptil_exotico.col_id] = it->second.get_id();
				row[model_columns_reptil_exotico.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_reptil_exotico.col_sexo] = temp;
				row[model_columns_reptil_exotico.col_tamanho] = it->second.get_tamanho();
				row[model_columns_reptil_exotico.col_dieta] = it->second.get_dieta();
				row[model_columns_reptil_exotico.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_reptil_exotico.col_tratador] = it->second.get_tratador_id();
				row[model_columns_reptil_exotico.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_reptil_exotico.col_veneno] = it->second.get_tipo_de_veneno();
				row[model_columns_reptil_exotico.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_reptil_exotico.col_pais_origem] = it->second.get_pais_de_origem();
			}
		}

		for (map<int, ReptilNativo>::iterator it = repteis_nativos->begin(); it != repteis_nativos->end(); it++)
		{
			if ((it->second).get_veterinario_id() == id)
			{
				page_repteis_nativos = true;
				row = *(list_store_repteis_nativos->append());
				row[model_columns_reptil_nativo.col_id] = it->second.get_id();
				row[model_columns_reptil_nativo.col_nome_cientifico] = it->second.get_nome_cientifico();
				string temp;
				temp.push_back(it->second.get_sexo());
				row[model_columns_reptil_nativo.col_sexo] = temp;
				row[model_columns_reptil_nativo.col_tamanho] = it->second.get_tamanho();
				row[model_columns_reptil_nativo.col_dieta] = it->second.get_dieta();
				row[model_columns_reptil_nativo.col_veterinario] = it->second.get_veterinario_id();
				row[model_columns_reptil_nativo.col_tratador] = it->second.get_tratador_id();
				row[model_columns_reptil_nativo.col_nome_batismo] = it->second.get_nome_de_batismo();
				row[model_columns_reptil_nativo.col_veneno] = it->second.get_tipo_de_veneno();
				row[model_columns_reptil_nativo.col_autorizacao_ibama] = it->second.get_autorizacao_ibama();
				row[model_columns_reptil_nativo.col_uf_origem] = it->second.get_uf_de_origem();
			}
		}
	}
	if(pagina == 0 || pagina == 1)
	{
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
}

void JanelaBuscaAnimais::Buscar()
{
	if(!valid_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi encontrado um funcionário com o ID apresentado, funcionários não podem ter IDs iguais.");
  		dialog.run();
	}
	else
	{
		// Não está readicionando as paginas
		for (int i = 0; i < notebook_consulta->get_n_pages(); i++)
		{
			notebook_consulta->remove_page(0);
		}

		notebook_consulta->append_page(*scrolled_window_anfibios_nativos, "Anfibios nativos");
		notebook_consulta->append_page(*scrolled_window_anfibios_exoticos, "Anfibios exóticos");
		notebook_consulta->append_page(*scrolled_window_aves_nativas, "Aves nativas");
		notebook_consulta->append_page(*scrolled_window_aves_exoticas, "Aves exóticas");
		notebook_consulta->append_page(*scrolled_window_mamiferos_nativos, "Mamíferos nativos");
		notebook_consulta->append_page(*scrolled_window_mamiferos_exoticos, "Mamíferos exóticos");
		notebook_consulta->append_page(*scrolled_window_repteis_nativos, "Répteis nativos");
		notebook_consulta->append_page(*scrolled_window_repteis_exoticos, "Répteis exóticos");
		
		id = stoi(entry_id->get_text());
		map<int, Veterinario>::iterator it_v = veterinarios->find(id);
		map<int, Tratador>::iterator it_t = tratadores->find(id);

		if(it_v != veterinarios->end())
			pagina = 1;
		else if (it_t != tratadores->end())
			pagina = 0;

		ProcurarAnimalPorFuncionario();
	}
}

void JanelaBuscaAnimais::AtualizarIconeId()
{
	string temp = entry_id->get_text();
	bool is_numeric = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false;
			break;
		}
	}
	if(is_numeric && !temp.empty())
	{
		int id = stoi(temp);
		map<int, Veterinario>::iterator it_v = veterinarios->find(id);
		map<int, Tratador>::iterator it_t = tratadores->find(id);

		if(it_v != veterinarios->end() || it_t != tratadores->end())
		{
			valid_id = true;
			entry_id->set_icon_from_pixbuf(pixbuf_check);
			entry_id->set_icon_tooltip_text("ID válido");
		}
		else
		{
			valid_id = false;
			entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_id->set_icon_tooltip_text("Algum outro funcionário já possui esse ID");
		}
	}
	else
	{
		valid_id = false;
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_id->set_icon_tooltip_text("ID inválido");
	}
}

void JanelaBuscaAnimais::Run()
{
	window->show_all();
	Main::run(*window);
}
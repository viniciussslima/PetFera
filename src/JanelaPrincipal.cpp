#include "JanelaPrincipal.h"
#include "JanelaCadastroFuncionario.h"
#include "JanelaCadastroAnimal.h"
#include "JanelaRemocaoFuncionario.h"
#include "JanelaRemocaoAnimal.h"

using namespace Gtk;
using namespace std;

JanelaPrincipal::JanelaPrincipal():ModelColumnsTratador(), ModelColumnsVeterinario(),
	ModelColumnsAnfibioNativo(), ModelColumnsAnfibioExotico(),
	ModelColumnsAveNativa(), ModelColumnsAveExotica(),
	ModelColumnsMamiferoNativo(), ModelColumnsMamiferoExotico(),
	ModelColumnsReptilNativo(), ModelColumnsReptilExotico()
{
	ifstream funcionarios_csv("Dados/funcionarios.csv");
	ifstream animais_csv("Dados/animais.csv");

	if(funcionarios_csv.is_open())
	{
		string linha;
		vector<string> palavras;

		while(getline(funcionarios_csv, linha))
		{
			palavras = Separador_csv(linha);

			int id = stoi(palavras[0]);
			string funcao = palavras[1];
			string nome = palavras[2];
			string cpf = palavras[3];
			short idade = stoi(palavras[4]);
			string tipo_sanguineo = palavras[5];
			char fator_rh = palavras[6][0];
			string especialidade = palavras[7];

			if(funcao.compare("TRATADOR") == 0)
			{
				int nivel_seguranca = stoi(palavras[8]);
				Tratador temp(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, nivel_seguranca);
				tratadores.insert(pair<int, Tratador>(id, temp));
			}
			else
			{
				string crmv = palavras[8];
				Veterinario temp(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, crmv);
				veterinarios.insert(pair<int, Veterinario>(id, temp));
			}
		}
	}

	if(animais_csv.is_open())
	{
		string linha;
		vector<string> palavras;

		while(getline(animais_csv, linha))
		{
			palavras = Separador_csv(linha);

			int id = stoi(palavras[0]);
			string classe = palavras[1];
			string nome_cientifico = palavras[2];
			char sexo = palavras[3][0];
			double tamanho = stod(palavras[4]);
			string dieta = palavras[5];
			Veterinario veterinario;
			if (stoi(palavras[6]) != 0)
				veterinario = veterinarios.find(stoi(palavras[6]))->second;
			Tratador tratador;
			if (stoi(palavras[7]) != 0)
				tratador = tratadores.find(stoi(palavras[7]))->second;
			string nome_batismo = palavras[8];
			string nacionalidade = palavras[palavras.size() - 1];

			if(classe.compare("AMPHIBIA") == 0)
		    {
		    	int total_mudas = stoi(palavras[9]);
		    	vector<int> data = Separador_data(palavras[10]);
		    	date data_ultima_muda(data[0], data[1], data[2]);
		    	string autorizacao_ibama = palavras[11];

				if(nacionalidade.length() == 2)
				{
					AnfibioNativo temp(id, classe, nome_cientifico, sexo, tamanho,
									   dieta, veterinario, tratador, nome_batismo, 
									   total_mudas, data_ultima_muda, autorizacao_ibama, nacionalidade);
			    	anfibios_nativos.insert(pair<int, AnfibioNativo>(id, temp));
				}
			    else
			    {
			    	AnfibioExotico temp(id, classe, nome_cientifico, sexo, tamanho,
									   dieta, veterinario, tratador, nome_batismo, 
									   total_mudas, data_ultima_muda, autorizacao_ibama, nacionalidade);
			    	anfibios_exoticos.insert(pair<int, AnfibioExotico>(id, temp));
			    }
		    }
		    if(classe.compare("AVES") == 0)
		    {
		    	double tamanho_bico = stod(palavras[9]);
		    	double envergadura_asas = stod(palavras[10]);
		    	string autorizacao_ibama = palavras[11];

				if(nacionalidade.length() == 2)
				{
					AveNativo temp(id, classe, nome_cientifico, sexo, tamanho,
								   dieta, veterinario, tratador, nome_batismo, 
								   tamanho_bico, envergadura_asas, autorizacao_ibama, nacionalidade);
			    	aves_nativas.insert(pair<int, AveNativo>(id, temp));
				}
			    else
			    {
					AveExotico temp(id, classe, nome_cientifico, sexo, tamanho,
								    dieta, veterinario, tratador, nome_batismo, 
								    tamanho_bico, envergadura_asas, autorizacao_ibama, nacionalidade);
			    	aves_exoticas.insert(pair<int, AveExotico>(id, temp));
			    }
		    }
		    if(classe.compare("MAMMALIA") == 0)
		    {
		    	string cor_pelo = palavras[9];
		    	string autorizacao_ibama = palavras[10];

				if(nacionalidade.length() == 2)
				{
					MamiferoNativo temp(id, classe, nome_cientifico, sexo, tamanho,
								        dieta, veterinario, tratador, nome_batismo, 
								   		cor_pelo, autorizacao_ibama, nacionalidade);
			    	mamiferos_nativos.insert(pair<int, MamiferoNativo>(id, temp));
				}
			    else
			    {
			    	MamiferoExotico temp(id, classe, nome_cientifico, sexo, tamanho,
								   		 dieta, veterinario, tratador, nome_batismo, 
								   		 cor_pelo, autorizacao_ibama, nacionalidade);
			    	mamiferos_exoticos.insert(pair<int, MamiferoExotico>(id, temp));
			    }
		    }
		    if(classe.compare("REPTILIA") == 0)
		    {
		    	bool venenoso = palavras[9].compare("1") == 0 ? true : false;
		    	string tipo_veneno = palavras[10];
		    	string autorizacao_ibama = palavras[11];

				if(nacionalidade.length() == 2)
				{
					ReptilNativo temp(id, classe, nome_cientifico, sexo, tamanho,
								       dieta, veterinario, tratador, nome_batismo, 
								       venenoso, tipo_veneno, autorizacao_ibama, nacionalidade);
			    	repteis_nativos.insert(pair<int, ReptilNativo>(id, temp));
				}
			    else
			    {
			    	ReptilExotico temp(id, classe, nome_cientifico, sexo, tamanho,
								       dieta, veterinario, tratador, nome_batismo, 
								       venenoso, tipo_veneno, autorizacao_ibama, nacionalidade);
			    	repteis_exoticos.insert(pair<int, ReptilExotico>(id, temp));
			    }
		    }
		}
	}

	//Inicialização
	window = new Window;

	button_cadastro_animal = new Button("Cadastrar animal");
	button_remocao_animal = new Button("Remover animal");
	button_cadastro_funcionario = new Button("Cadastrar funcionario");
	button_remocao_funcionario = new Button("Remover funcionario");
	button_editar = new Button("Editar");

	box_principal = new VBox;
	box_botoes = new HButtonBox;

	entry_pesquisa = new SearchEntry;

	notebook_consulta = new Notebook;

	tree_view_tratadores = new TreeView;
	tree_view_veterinarios = new TreeView;
	tree_view_anfibios_nativos = new TreeView;
	tree_view_anfibios_exoticos = new TreeView;
	tree_view_aves_nativas = new TreeView;
	tree_view_aves_exoticas = new TreeView;
	tree_view_mamiferos_nativos = new TreeView;
	tree_view_mamiferos_exoticos = new TreeView;
	tree_view_repteis_nativos = new TreeView;
	tree_view_repteis_exoticos = new TreeView;

	scrolled_window_tratadores = new ScrolledWindow;
	scrolled_window_veterinarios = new ScrolledWindow;
	scrolled_window_anfibios_nativos = new ScrolledWindow;
	scrolled_window_anfibios_exoticos = new ScrolledWindow;
	scrolled_window_aves_nativas = new ScrolledWindow;
	scrolled_window_aves_exoticas = new ScrolledWindow;
	scrolled_window_mamiferos_nativos = new ScrolledWindow;
	scrolled_window_mamiferos_exoticos = new ScrolledWindow;
	scrolled_window_repteis_nativos = new ScrolledWindow;
	scrolled_window_repteis_exoticos = new ScrolledWindow;

	//Configuração
	window->set_default_size(1280, 720);
	window->set_resizable(true);
	window->set_border_width(5);
	window->set_title("PetFera");
	window->add(*box_principal);

	box_principal->pack_start(*entry_pesquisa, PACK_SHRINK);
	box_principal->add(*notebook_consulta);
	box_principal->pack_start(*box_botoes, PACK_SHRINK);

	notebook_consulta->append_page(*scrolled_window_tratadores, "Tratadores");
	notebook_consulta->append_page(*scrolled_window_veterinarios, "Veterinarios");
	notebook_consulta->append_page(*scrolled_window_anfibios_nativos, "Anfibios nativos");
	notebook_consulta->append_page(*scrolled_window_anfibios_exoticos, "Anfibios exóticos");
	notebook_consulta->append_page(*scrolled_window_aves_nativas, "Aves nativas");
	notebook_consulta->append_page(*scrolled_window_aves_exoticas, "Aves exóticas");
	notebook_consulta->append_page(*scrolled_window_mamiferos_nativos, "Mamíferos nativos");
	notebook_consulta->append_page(*scrolled_window_mamiferos_exoticos, "Mamíferos exóticos");
	notebook_consulta->append_page(*scrolled_window_repteis_nativos, "Répteis nativos");
	notebook_consulta->append_page(*scrolled_window_repteis_exoticos, "Répteis exóticos");

	scrolled_window_tratadores->add(*tree_view_tratadores);
	scrolled_window_veterinarios->add(*tree_view_veterinarios);
	scrolled_window_anfibios_nativos->add(*tree_view_anfibios_nativos);
	scrolled_window_anfibios_exoticos->add(*tree_view_anfibios_exoticos);
	scrolled_window_aves_nativas->add(*tree_view_aves_nativas);
	scrolled_window_aves_exoticas->add(*tree_view_aves_exoticas);
	scrolled_window_mamiferos_nativos->add(*tree_view_mamiferos_nativos);
	scrolled_window_mamiferos_exoticos->add(*tree_view_mamiferos_exoticos);
	scrolled_window_repteis_nativos->add(*tree_view_repteis_nativos);
	scrolled_window_repteis_exoticos->add(*tree_view_repteis_exoticos);

	box_botoes->set_layout(BUTTONBOX_CENTER);
	box_botoes->pack_start(*button_cadastro_animal, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_remocao_animal, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_cadastro_funcionario, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_remocao_funcionario, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_editar, PACK_EXPAND_PADDING, 10);

	//Criando o modelo de arvore
	list_store_tratadores = ListStore::create(model_columns_tratador);
	list_store_veterinarios = ListStore::create(model_columns_veterinario);
	list_store_anfibios_nativos = ListStore::create(model_columns_anfibio_nativo);
	list_store_anfibios_exoticos = ListStore::create(model_columns_anfibio_exotico);
	list_store_aves_nativas = ListStore::create(model_columns_ave_nativa);
	list_store_aves_exoticas = ListStore::create(model_columns_ave_exotica);
	list_store_mamiferos_nativos = ListStore::create(model_columns_mamifero_nativo);
	list_store_mamiferos_exoticos = ListStore::create(model_columns_mamifero_exotico);
	list_store_repteis_nativos = ListStore::create(model_columns_reptil_nativo);
	list_store_repteis_exoticos = ListStore::create(model_columns_reptil_exotico);

	tree_view_tratadores->set_search_entry(*entry_pesquisa);
	tree_view_tratadores->set_model(list_store_tratadores);

	tree_view_veterinarios->set_search_entry(*entry_pesquisa);
	tree_view_veterinarios->set_model(list_store_veterinarios);
	
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
	tree_view_tratadores->append_column("ID", model_columns_tratador.col_id);
	tree_view_tratadores->append_column("Nome", model_columns_tratador.col_nome);
	tree_view_tratadores->append_column("CPF", model_columns_tratador.col_cpf);
	tree_view_tratadores->append_column("Idade", model_columns_tratador.col_idade);
	tree_view_tratadores->append_column("Tipo sanguineo", model_columns_tratador.col_tipo_sanguineo);
	tree_view_tratadores->append_column("RH", model_columns_tratador.col_rh);
	tree_view_tratadores->append_column("Especialidade", model_columns_tratador.col_especialidade);
	tree_view_tratadores->append_column("Nivel de segurança", model_columns_tratador.col_nivel_seguranca);

	tree_view_veterinarios->append_column("ID", model_columns_veterinario.col_id);
	tree_view_veterinarios->append_column("Nome", model_columns_veterinario.col_nome);
	tree_view_veterinarios->append_column("CPF", model_columns_veterinario.col_cpf);
	tree_view_veterinarios->append_column("Idade", model_columns_veterinario.col_idade);
	tree_view_veterinarios->append_column("Tipo sanguineo", model_columns_veterinario.col_tipo_sanguineo);
	tree_view_veterinarios->append_column("RH", model_columns_veterinario.col_rh);
	tree_view_veterinarios->append_column("Especialidade", model_columns_veterinario.col_especialidade);
	tree_view_veterinarios->append_column("CRMV", model_columns_veterinario.col_crmv);

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

	for(int i = 0; i < 10; i++)
	{
		AtualizarLista(i);
	}

	//Conexão
	button_cadastro_funcionario->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::CadastrarFuncionario));
	button_cadastro_animal->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::CadastrarAnimal));
	button_remocao_funcionario->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::RemoverFuncionario));
	button_remocao_animal->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::RemoverAnimal));
	button_editar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::Editar));
}

JanelaPrincipal::~JanelaPrincipal()
{
	delete window;
	delete button_cadastro_animal;
	delete button_remocao_animal;
	delete button_cadastro_funcionario;
	delete button_remocao_funcionario;
	delete box_principal;
	delete box_botoes;
	delete notebook_consulta;
	delete tree_view_tratadores;
	delete tree_view_veterinarios;
	delete tree_view_anfibios_nativos;
	delete tree_view_anfibios_exoticos;
	delete tree_view_aves_nativas;
	delete tree_view_aves_exoticas;
	delete tree_view_mamiferos_nativos;
	delete tree_view_mamiferos_exoticos;
	delete tree_view_repteis_nativos;
	delete tree_view_repteis_exoticos;
	delete scrolled_window_tratadores;
	delete scrolled_window_veterinarios;
	delete scrolled_window_anfibios_nativos;
	delete scrolled_window_anfibios_exoticos;
	delete scrolled_window_aves_nativas;
	delete scrolled_window_aves_exoticas;
	delete scrolled_window_mamiferos_nativos;
	delete scrolled_window_mamiferos_exoticos;
	delete scrolled_window_repteis_nativos;
	delete scrolled_window_repteis_exoticos;
}

void JanelaPrincipal::Run()
{
	window->show_all();
	Main::run(*window);
}

void JanelaPrincipal::CadastrarFuncionario()
{
	window->hide();
	JanelaCadastroFuncionario temp(*this, veterinarios, tratadores);
	temp.Run();
	this->Run();
}

void JanelaPrincipal::CadastrarAnimal()
{
	if (tratadores.empty() && veterinarios.empty())
	{
		MessageDialog dialog(*window, "Impossivel cadastrar um animal.");
		dialog.set_secondary_text("Não existem funcionarios cadastrados.");
  		dialog.run();
	}
	else
	{
		JanelaCadastroAnimal temp(*this, veterinarios, tratadores, anfibios_exoticos, anfibios_nativos, aves_exoticas,
								  aves_nativas, mamiferos_exoticos, mamiferos_nativos, repteis_exoticos, repteis_nativos);
		temp.Run();
	}
}

void JanelaPrincipal::RemoverFuncionario()
{
	window->hide();
	if (tratadores.empty() && veterinarios.empty())
	{
		MessageDialog dialog(*window, "Impossivel remover um funcionario.");
		dialog.set_secondary_text("Não existem funcionarios cadastrados.");
  		dialog.run();
	}
	else
	{
		JanelaRemocaoFuncionario temp(*this, veterinarios, tratadores, anfibios_exoticos, anfibios_nativos, aves_exoticas,
								  aves_nativas, mamiferos_exoticos, mamiferos_nativos, repteis_exoticos, repteis_nativos);
		temp.Run();
	}
	this->Run();
}

void JanelaPrincipal::RemoverAnimal()
{
	window->hide();
	if(anfibios_exoticos.empty() && anfibios_nativos.empty() && 
		aves_exoticas.empty() && aves_nativas.empty() && 
		mamiferos_exoticos.empty() && mamiferos_nativos.empty() &&
		repteis_exoticos.empty() && repteis_nativos.empty())
	{
		MessageDialog dialog(*window, "Impossivel remover um animal.");
		dialog.set_secondary_text("Não existem animais cadastrados.");
  		dialog.run();
	}
	else
	{
		JanelaRemocaoAnimal temp(*this, anfibios_exoticos, anfibios_nativos, aves_exoticas,
								 aves_nativas, mamiferos_exoticos, mamiferos_nativos, 
								 repteis_exoticos, repteis_nativos);
		temp.Run();
	}
	this->Run();
}

void JanelaPrincipal::Editar()
{
	switch(notebook_consulta->get_current_page())
	{
	case 0:
		{
			//tratadores
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_tratadores->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_tratador.col_id);
			cout << id << " "<< endl;
			/*window->hide();
			JanelaEditarFuncionario temp(*this, veterinarios, tratadores, id);
			temp.Run();
			this->Run();*/
			break;
		}
		case 1:
		{
			//veterinarios
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_veterinarios->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_veterinario.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 2:
		{
			//anfibios nativos
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_anfibios_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_anfibio_nativo.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 3:
		{
			//anfibios exoticos
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_anfibios_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_anfibio_exotico.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 4:
		{
			//aves nativas
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_aves_nativas->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_ave_nativa.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 5:
		{
			//aves exoticas
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_aves_exoticas->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_ave_exotica.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 6:
		{
			//mamiferos nativos
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_mamiferos_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_mamifero_nativo.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 7:
		{
			//mamiferos exoticos
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_mamiferos_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_mamifero_exotico.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 8:
		{
			//repteis nativos
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_repteis_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_reptil_nativo.col_id);
			cout << id << " "<< endl;
			break;
		}
		case 9:
		{
			//repteis exoticos
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_repteis_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			int id = row.get_value(model_columns_reptil_nativo.col_id);
			cout << id << " "<< endl;
			break;
		}
	}
}

void JanelaPrincipal::AtualizarLista(int i)
{
	TreeModel::Row row;
	switch(i)
	{
		case 0:
		{
			//tratadores
			notebook_consulta->set_current_page(0);
			list_store_tratadores->clear();
			for(map<int, Tratador>::iterator it = tratadores.begin(); it != tratadores.end(); it++)
			{
				row = *(list_store_tratadores->append());
				row[model_columns_tratador.col_id] = it->second.get_id();
				row[model_columns_tratador.col_nome] = it->second.get_nome();
				row[model_columns_tratador.col_cpf] = it->second.get_cpf();
				row[model_columns_tratador.col_idade] = it->second.get_idade();
				row[model_columns_tratador.col_tipo_sanguineo] = it->second.get_tipo_sanguineo();
				string temp;
				temp.push_back(it->second.get_rh());
				row[model_columns_tratador.col_rh] = temp;
				row[model_columns_tratador.col_especialidade] = it->second.get_especialidade();
				row[model_columns_tratador.col_nivel_seguranca] = it->second.get_nivel_de_seguranca();
			}
			break;
		}
		case 1:
		{
			//veterinarios
			notebook_consulta->set_current_page(1);
			list_store_veterinarios->clear();
			for(map<int, Veterinario>::iterator it = veterinarios.begin(); it != veterinarios.end(); it++)
			{
				row = *(list_store_veterinarios->append());
				row[model_columns_veterinario.col_id] = it->second.get_id();
				row[model_columns_veterinario.col_nome] = it->second.get_nome();
				row[model_columns_veterinario.col_cpf] = it->second.get_cpf();
				row[model_columns_veterinario.col_idade] = it->second.get_idade();
				row[model_columns_veterinario.col_tipo_sanguineo] = it->second.get_tipo_sanguineo();
				string temp;
				temp.push_back(it->second.get_rh());
				row[model_columns_veterinario.col_rh] = temp;
				row[model_columns_veterinario.col_especialidade] = it->second.get_especialidade();
				row[model_columns_veterinario.col_crmv] = it->second.get_crmv();
			}
			break;
		}
		case 2:
		{
			//anfibios nativos
			notebook_consulta->set_current_page(2);
			list_store_anfibios_nativos->clear();
			for(map<int, AnfibioNativo>::iterator it = anfibios_nativos.begin(); it != anfibios_nativos.end(); it++)
			{
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
			break;
		}
		case 3:
		{
			//anfibios exoticos
			notebook_consulta->set_current_page(3);
			list_store_anfibios_exoticos->clear();
			for(map<int, AnfibioExotico>::iterator it = anfibios_exoticos.begin(); it != anfibios_exoticos.end(); it++)
			{
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
			break;
		}
		case 4:
		{
			//aves nativas
			notebook_consulta->set_current_page(4);
			list_store_aves_nativas->clear();
			for(map<int, AveNativo>::iterator it = aves_nativas.begin(); it != aves_nativas.end(); it++)
			{
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
			break;
		}
		case 5:
		{
			//aves exoticas
			notebook_consulta->set_current_page(5);
			list_store_aves_exoticas->clear();
			for(map<int, AveExotico>::iterator it = aves_exoticas.begin(); it != aves_exoticas.end(); it++)
			{
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
			break;
		}
		case 6:
		{
			//mamiferos nativos
			notebook_consulta->set_current_page(6);
			list_store_mamiferos_nativos->clear();
			for(map<int, MamiferoNativo>::iterator it = mamiferos_nativos.begin(); it != mamiferos_nativos.end(); it++)
			{
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
			break;
		}
		case 7:
		{
			//mamiferos exoticos
			notebook_consulta->set_current_page(7);
			list_store_mamiferos_exoticos->clear();
			for(map<int, MamiferoExotico>::iterator it = mamiferos_exoticos.begin(); it != mamiferos_exoticos.end(); it++)
			{
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
			break;
		}
		case 8:
		{
			//repteis nativos
			notebook_consulta->set_current_page(8);
			list_store_repteis_nativos->clear();
			for(map<int, ReptilNativo>::iterator it = repteis_nativos.begin(); it != repteis_nativos.end(); it++)
			{
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
			break;
		}
		case 9:
		{
			//repteis exoticos
			notebook_consulta->set_current_page(9);
			list_store_repteis_exoticos->clear();
			for(map<int, ReptilExotico>::iterator it = repteis_exoticos.begin(); it != repteis_exoticos.end(); it++)
			{
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
			break;
		}
	}
}
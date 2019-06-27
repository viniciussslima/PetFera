/**
* @file JanelaPrincipal.cpp
* @brief Implementação da classe JanelaPrincipal.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "JanelaPrincipal.h"
#include "JanelaCadastroFuncionario.h"
#include "JanelaCadastroAnimal.h"
#include "JanelaEditarAnimal.h"
#include "JanelaEditarFuncionario.h"
#include "JanelaBuscaAnimais.h"

#include "RemoverFuncionario.h"
#include "RemoverAnimal.h"
#include "Responsabilidade.h"

using namespace Gtk;
using namespace std;

/**
* @brief Construtor padrão da classe JanelaPrincipal.
*/

JanelaPrincipal::JanelaPrincipal():ModelColumnsTratador(), ModelColumnsVeterinario(),
	ModelColumnsAnfibioNativo(), ModelColumnsAnfibioExotico(),
	ModelColumnsAveNativa(), ModelColumnsAveExotica(),
	ModelColumnsMamiferoNativo(), ModelColumnsMamiferoExotico(),
	ModelColumnsReptilNativo(), ModelColumnsReptilExotico()
{
	ifstream funcionarios_csv("Dados/funcionarios.csv");
	ifstream animais_csv("Dados/animais.csv");
	//Carregando os dados dos funcionários
	if(funcionarios_csv.is_open())
	{
		string linha;
		vector<string> palavras;

		while(getline(funcionarios_csv, linha))
		{
			palavras = Separador_csv(linha);
			//Carregando algumas das informações do funcionário
			int id = stoi(palavras[0]);
			string funcao = palavras[1];
			string nome = palavras[2];
			string cpf = palavras[3];
			short idade = stoi(palavras[4]);
			string tipo_sanguineo = palavras[5];
			char fator_rh = palavras[6][0];
			string especialidade = palavras[7];
			//Caso for um tratador
			if(funcao.compare("TRATADOR") == 0)
			{
				int nivel_seguranca = stoi(palavras[8]);
				Funcionario *temp = new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, nivel_seguranca);
				funcionarios.insert(pair<int, Funcionario*>(id, temp));
			}
			//Caso for um funcionário
			else
			{
				string crmv = palavras[8];
				Funcionario *temp = new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, crmv);
				funcionarios.insert(pair<int, Funcionario*>(id, temp));
			}
		}
	}
	//Carregando os dados dos animais
	if(animais_csv.is_open())
	{
		string linha;
		vector<string> palavras;

		while(getline(animais_csv, linha))
		{
			palavras = Separador_csv(linha);
			//Carregando algumas das informações do funcionário
			int id = stoi(palavras[0]);
			string classe = palavras[1];
			string nome_cientifico = palavras[2];
			char sexo = palavras[3][0];
			double tamanho = stod(palavras[4]);
			string dieta = palavras[5];
			Veterinario *veterinario = new Veterinario;
			if (stoi(palavras[6]) != 0)
				veterinario = dynamic_cast<Veterinario*>(funcionarios.find(stoi(palavras[6]))->second);
			Tratador *tratador = new Tratador;
			if (stoi(palavras[7]) != 0)
				tratador = dynamic_cast<Tratador*>(funcionarios.find(stoi(palavras[7]))->second);
			string nome_batismo = palavras[8];
			string nacionalidade = palavras[palavras.size() - 1];

			if(classe.compare("AMPHIBIA") == 0)
		    {
		    	int total_mudas = stoi(palavras[9]);
		    	vector<int> data = Separador_data(palavras[10]);
		    	date data_ultima_muda(data[0], data[1], data[2]);
		    	string autorizacao_ibama = palavras[11];
		    	string cidade_de_origem = palavras[12];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new AnfibioNativo(id, classe, nome_cientifico, sexo, tamanho,
									   dieta, *veterinario, *tratador, nome_batismo, 
									   total_mudas, data_ultima_muda, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
			    	Animal *temp = new AnfibioExotico(id, classe, nome_cientifico, sexo, tamanho,
									   dieta, *veterinario, *tratador, nome_batismo, 
									   total_mudas, data_ultima_muda, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		    if(classe.compare("AVES") == 0)
		    {
		    	double tamanho_bico = stod(palavras[9]);
		    	double envergadura_asas = stod(palavras[10]);
		    	string autorizacao_ibama = palavras[11];
		    	string cidade_de_origem = palavras[12];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new AveNativo(id, classe, nome_cientifico, sexo, tamanho,
								   dieta, *veterinario, *tratador, nome_batismo, 
								   tamanho_bico, envergadura_asas, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
					Animal *temp = new AveExotico(id, classe, nome_cientifico, sexo, tamanho,
								    dieta, *veterinario, *tratador, nome_batismo, 
								    tamanho_bico, envergadura_asas, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		    if(classe.compare("MAMMALIA") == 0)
		    {
		    	string cor_pelo = palavras[9];
		    	string autorizacao_ibama = palavras[10];
		    	string cidade_de_origem = palavras[11];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new MamiferoNativo(id, classe, nome_cientifico, sexo, tamanho,
								        dieta, *veterinario, *tratador, nome_batismo, 
								   		cor_pelo, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
			    	Animal *temp = new MamiferoExotico(id, classe, nome_cientifico, sexo, tamanho,
								   		 dieta, *veterinario, *tratador, nome_batismo, 
								   		 cor_pelo, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		    if(classe.compare("REPTILIA") == 0)
		    {
		    	bool venenoso = palavras[9].compare("1") == 0 ? true : false;
		    	string tipo_veneno = palavras[10];
		    	string autorizacao_ibama = palavras[11];
		    	string cidade_de_origem = palavras[12];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new ReptilNativo(id, classe, nome_cientifico, sexo, tamanho,
								       dieta, *veterinario, *tratador, nome_batismo, 
								       venenoso, tipo_veneno, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
			    	Animal *temp = new ReptilExotico(id, classe, nome_cientifico, sexo, tamanho,
								       dieta, *veterinario, *tratador, nome_batismo, 
								       venenoso, tipo_veneno, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		}
	}

	//Inicialização dos atributos da classe GTK.
	window = new Window;

	button_cadastro_animal = new Button("Cadastrar animal");
	button_remover = new Button("Remover");
	button_cadastro_funcionario = new Button("Cadastrar funcionário");
	button_editar = new Button("Editar");
	button_buscar_animal_por_funcionario = new Button("Buscar animal por funcionário");
	button_about = new Button;

	box_principal = new VBox;
	box_botoes = new HButtonBox;

	entry_pesquisa = new SearchEntry;

	notebook_consulta = new Notebook;

	IconeButao = new Image("icons/icone_informativo.ico");

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

	//Configuração dos atributos da classe GTK.
	pixbuf_icone = Gdk::Pixbuf::create_from_file("icons/icone_ sem_bico.ico");
	
	window->maximize();
	window->set_resizable(true);
	window->set_border_width(5);
	window->set_title("PetFera");
	window->set_icon(pixbuf_icone);
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
	box_botoes->pack_start(*button_remover, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_cadastro_funcionario, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_editar, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_buscar_animal_por_funcionario, PACK_EXPAND_PADDING, 10);
	box_botoes->pack_start(*button_about, PACK_SHRINK);

	button_about->set_image(*IconeButao);

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

	//Preenchendo o modelo de arvore

	for(int i = 0; i < 10; i++)
	{
		AtualizarLista(i);
	}

	//Conexões dos atributos da classe GTK.
	button_cadastro_funcionario->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::BotaoCadastrarFuncionario));
	button_cadastro_animal->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::BotaoCadastrarAnimal));
	button_remover->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::BotaoRemover));
	button_editar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::BotaoEditar));
	button_buscar_animal_por_funcionario->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::BotaoBuscarAnimalPorFuncionario));
	button_about->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::BotaoAbout));
}

/**
* @brief Destrutor da classe JanelaPrincipal.
*/

JanelaPrincipal::~JanelaPrincipal()
{
	delete window;
	delete button_cadastro_animal;
	delete button_remover;
	delete button_cadastro_funcionario;
	delete button_editar;
	delete button_buscar_animal_por_funcionario;
	delete button_about;
	delete box_principal;
	delete box_botoes;
	delete entry_pesquisa;
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

/**
* @brief Método que inicia a janela principal.
*/

void JanelaPrincipal::Run()
{
	window->show_all();
	Main::run(*window);
}

/**
* @brief Método que inicia a janela cadastrar funcionário.
*/

void JanelaPrincipal::BotaoCadastrarFuncionario()
{
	JanelaCadastroFuncionario temp(*this, funcionarios);
	temp.Run();
}

/**
* @brief Método que inicia a janela cadastrar animal.
*/

void JanelaPrincipal::BotaoCadastrarAnimal()
{
	if (funcionarios.empty())
	{
		MessageDialog dialog(*window, "Impossivel cadastrar um animal.");
		dialog.set_secondary_text("Não existe(m) funcionário(s) cadastrado(s).");
  		dialog.run();
	}
	else
	{
		JanelaCadastroAnimal temp(*this, funcionarios, animais);
		temp.Run();
	}
}

/**
* @brief Método chama as funções RemoverAnimal e RemoverFuncionario quando o botão remover é clicado.
*/

void JanelaPrincipal::BotaoRemover()
{
	int id;
	int pagina = notebook_consulta->get_current_page();
	int resposta;
	bool valid_row = true;
	switch(pagina)
	{
		case 0: // Caso a pagina for igual 0 remove um tratador.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_tratadores->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_tratador.col_id);
				if(!Responsabilidade(animais, id))
				{
					MessageDialog confirmacao(*window, "Tem certeza que quer remover esse funcionário? ");
					confirmacao.add_button("Não", 1);
					resposta = confirmacao.run();
					if (resposta == RESPONSE_OK)
					{
						RemoverFuncionario(*this, funcionarios, id);
					}
				}
				else
				{
					MessageDialog dialog(*window, "Não é possivel remover esse funcionario ");
					dialog.set_secondary_text("Esse funcionario é responsavel por algum animal");
					dialog.run();
				}

			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 1: // Caso a pagina for igual 1 remove um veterinário.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_veterinarios->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_veterinario.col_id);
				if(!Responsabilidade(animais, id))
				{
					MessageDialog confirmacao(*window, "Tem certeza que quer remover esse funcionário? ");
					confirmacao.add_button("Não", 1);
					resposta = confirmacao.run();
					if (resposta == RESPONSE_OK)
					{
						RemoverFuncionario(*this, funcionarios, id);
					}
				}
				else
				{
					MessageDialog dialog(*window, "Não é possivel remover esse funcionario ");
					dialog.set_secondary_text("Esse funcionario é responsavel por algum animal");
					dialog.run();
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 2: // Caso a pagina for igual 2 remove um anfíbio nativo.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_anfibios_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_anfibio_nativo.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 3: // Caso a pagina for igual 3 remove um anfíbio exótico.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_anfibios_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_anfibio_exotico.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 4: // Caso a pagina for igual 4 remove uma ave nativa.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_aves_nativas->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_ave_nativa.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 5: // Caso a pagina for igual 5 remove uma aves exótica.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_aves_exoticas->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_ave_exotica.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 6: // Caso a pagina for igual 6 remove um mamífero nativo.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_mamiferos_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_mamifero_nativo.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 7: // Caso a pagina for igual 7 remove um mamífero exótico.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_mamiferos_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_mamifero_exotico.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 8: // Caso a pagina for igual 8 remove um réptil nativo.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_repteis_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_reptil_nativo.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 9: // Caso a pagina for igual 9 remove um répteis exóticos.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_repteis_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_reptil_exotico.col_id);	
				MessageDialog confirmacao(*window, "Tem certeza que quer remover esse animal? ");
				confirmacao.add_button("Não", 1);
				resposta = confirmacao.run();
				if (resposta == RESPONSE_OK)
				{
					RemoverAnimal(*this, animais, id);
				}
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
	}
	if(!valid_row) // Caso nenhuam linha seja selecionada é aberta uma janela de aviso.
	{
		MessageDialog dialog(*window, "Nenhum animal ou funcionário selecionado.");
		dialog.set_secondary_text("Primeiro selecione um funcionário ou um animal e depois aperte o botão remover.");
  		dialog.run();
	}
}

/**
* @brief Método chama as janelas EditarAnimal e EditarFuncionario quando o botão editar é clicado.
*/

void JanelaPrincipal::BotaoEditar()
{
	int id;
	int pagina = notebook_consulta->get_current_page();
	bool valid_row = true;
	switch(pagina)
	{
	case 0: // Caso a pagina for igual 0 edita um tratador.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_tratadores->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_tratador.col_id);	
				JanelaEditarFuncionario temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 1: // Caso a pagina for igual 1 edita um veterinário.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_veterinarios->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_veterinario.col_id);	
				JanelaEditarFuncionario temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 2: // Caso a pagina for igual 2 edita um anfíbio nativo.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_anfibios_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_anfibio_nativo.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 3: // Caso a pagina for igual 3 edita um anfíbio exótico.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_anfibios_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_anfibio_exotico.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 4: // Caso a pagina for igual 4 edita uma ave nativa.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_aves_nativas->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL)
			{
				id = row.get_value(model_columns_ave_nativa.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 5: // Caso a pagina for igual 5 edita um ave exótica.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_aves_exoticas->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_ave_exotica.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 6: // Caso a pagina for igual 6 edita um mamífero nativo.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_mamiferos_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_mamifero_nativo.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 7: // Caso a pagina for igual 7 edita um mamífero exótico.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_mamiferos_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_mamifero_exotico.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 8: // Caso a pagina for igual 8 edita um réptel nativo.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_repteis_nativos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_reptil_nativo.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
		case 9: // Caso a pagina for igual 9 edita um réptil exótico.
		{
			// Pega a linha selecionada.
			Glib::RefPtr<Gtk::TreeSelection> selection = tree_view_repteis_exoticos->get_selection();
			Gtk::TreeModel::iterator selectedRow = selection->get_selected();
			Gtk::TreeModel::Row row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_reptil_exotico.col_id);	
				JanelaEditarAnimal temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		}
	}
	if(!valid_row) // Caso uma linha nãon tenha sido selecionada é aberta uma janela de aviso.
	{
		MessageDialog dialog(*window, "Nenhum animal ou funcionário selecionado.");
		dialog.set_secondary_text("Primeiro selecione um funcionário ou um animal e depois aperte o botão editar.");
  		dialog.run();
	}
}

/**
* @brief Método chama a janela JanelaBuscaAnimais quando o botão buscar é clicado.
*/

void JanelaPrincipal::BotaoBuscarAnimalPorFuncionario()
{
	int id;
	int pagina = notebook_consulta->get_current_page();
	Glib::RefPtr<Gtk::TreeSelection> selection;
	Gtk::TreeModel::iterator selectedRow;
	Gtk::TreeModel::Row row;
	bool valid_row = true;
	switch(pagina)
	{
		case 0: // Caso a pagina for igual 0 busca por animais de um tratador.
			selection = tree_view_tratadores->get_selection();
			selectedRow = selection->get_selected();
			row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
				id = row.get_value(model_columns_tratador.col_id);	
				JanelaBuscaAnimais temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		case 1:  // Caso a pagina for igual 0 busca por animais de um veterinarios.
			// Pega a linha selecionada.
			selection = tree_view_veterinarios->get_selection();			
			selectedRow = selection->get_selected();
			row = *selectedRow;
			if (row != NULL) // Caso uma linha tenha sido selecionada.
			{
			
				id = row.get_value(model_columns_tratador.col_id);	
				JanelaBuscaAnimais temp(*this, funcionarios, animais, pagina, id);
				temp.Run();
			}
			else // Caso uma linha não tenha sido selecionada.
			{
				valid_row = false;
			}
			break;
		default:
			MessageDialog dialog(*window, "Impossível fazer a busca.");
			dialog.set_secondary_text("O item selecionado não é um funcionário.");
	  		dialog.run();
	  		break;
	}
	if(!valid_row) // Caso uma linha não tenha sido selecionada.
	{
		MessageDialog dialog(*window, "Nenhum funcionário selecionado.");
		dialog.set_secondary_text("Primeiro selecione um funcionário e depois aperte o botão buscar animal por funcionário.");
  		dialog.run();
	}
}

/**
* @brief Método qu abre uma AboutDialog que contém as informações do programa, como a versão e o link do github.
*/

void JanelaPrincipal::BotaoAbout()
{
	AboutDialog about_dialog;
	about_dialog.set_logo(pixbuf_icone);
	about_dialog.set_version("Versão 1.0");
	about_dialog.set_program_name("PetFera");
	about_dialog.set_copyright("Hudson Bruno Macedo Alves\nJoão Vitor Kobata\nVinicius Santos Silva de Lima");
	about_dialog.set_comments("Programa de cadastro de animais e funcionários para lojas de animais silvestres.");
	about_dialog.set_license("MIT");
	about_dialog.set_website("https://github.com/viniciussslima/PetFera");
	about_dialog.set_website_label("GitHub");
	about_dialog.set_transient_for(*window);
	about_dialog.run();
}

/**
* @brief Método que atualiza as listas.
* @param i Indica qual lista vai atualizar.
*/

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
			for(map<int, Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++)
			{
				bool is_tratador = true;
				if (dynamic_cast<Tratador*>(it->second) == NULL)
				{
					is_tratador = false;
				}
				if(is_tratador)
				{
					row = *(list_store_tratadores->append());
					row[model_columns_tratador.col_id] = it->second->get_id();
					row[model_columns_tratador.col_nome] = it->second->get_nome();
					row[model_columns_tratador.col_cpf] = it->second->get_cpf();
					row[model_columns_tratador.col_idade] = it->second->get_idade();
					row[model_columns_tratador.col_tipo_sanguineo] = it->second->get_tipo_sanguineo();
					string temp;
					temp.push_back(it->second->get_rh());
					row[model_columns_tratador.col_rh] = temp;
					row[model_columns_tratador.col_especialidade] = it->second->get_especialidade();
					row[model_columns_tratador.col_nivel_seguranca] = dynamic_cast<Tratador*>(it->second)->get_nivel_de_seguranca();
				}
			}
			break;
		}
		case 1:
		{
			//veterinarios
			notebook_consulta->set_current_page(1);
			list_store_veterinarios->clear();
			for(map<int, Funcionario*>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++)
			{
				bool is_veterinario = true;
				if (dynamic_cast<Veterinario*>(it->second) == NULL)
				{
					is_veterinario = false;
				}
				if(is_veterinario)
				{	
					row = *(list_store_veterinarios->append());
					row[model_columns_veterinario.col_id] = it->second->get_id();
					row[model_columns_veterinario.col_nome] = it->second->get_nome();
					row[model_columns_veterinario.col_cpf] = it->second->get_cpf();
					row[model_columns_veterinario.col_idade] = it->second->get_idade();
					row[model_columns_veterinario.col_tipo_sanguineo] = it->second->get_tipo_sanguineo();
					string temp;
					temp.push_back(it->second->get_rh());
					row[model_columns_veterinario.col_rh] = temp;
					row[model_columns_veterinario.col_especialidade] = it->second->get_especialidade();
					row[model_columns_veterinario.col_crmv] = dynamic_cast<Veterinario*>(it->second) ->get_crmv();
				}
			}
			break;
		}
		case 2:
		{
			//anfibios nativos
			notebook_consulta->set_current_page(2);
			list_store_anfibios_nativos->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_anfibios_nativos = true;
				if (dynamic_cast<AnfibioNativo*>(it->second) == NULL)
				{
					is_anfibios_nativos = false;
				}
				if(is_anfibios_nativos)
				{
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
			break;
		}
		case 3:
		{
			//anfibios exoticos
			notebook_consulta->set_current_page(3);
			list_store_anfibios_exoticos->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_anfibios_exotico = true;
				if (dynamic_cast<AnfibioExotico*>(it->second) == NULL)
				{
					is_anfibios_exotico = false;
				}
				if(is_anfibios_exotico)
				{
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
			}
			break;
		}
		case 4:
		{
			//aves nativas
			notebook_consulta->set_current_page(4);
			list_store_aves_nativas->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_ave_nativa = true;
				if (dynamic_cast<AveNativo*>(it->second) == NULL)
				{
					is_ave_nativa = false;
				}
				if(is_ave_nativa)
				{
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
			break;
		}
		case 5:
		{
			//aves exoticas
			notebook_consulta->set_current_page(5);
			list_store_aves_exoticas->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_ave_exotica = true;
				if (dynamic_cast<AveExotico*>(it->second) == NULL)
				{
					is_ave_exotica = false;
				}
				if(is_ave_exotica)
				{
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
			}
			break;
		}
		case 6:
		{
			//mamiferos nativos
			notebook_consulta->set_current_page(6);
			list_store_mamiferos_nativos->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_mamifero_nativo = true;
				if (dynamic_cast<MamiferoNativo*>(it->second) == NULL)
				{
					is_mamifero_nativo = false;
				}
				if(is_mamifero_nativo)
				{
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
			break;
		}
		case 7:
		{
			//mamiferos exoticos
			notebook_consulta->set_current_page(7);
			list_store_mamiferos_exoticos->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_mamifero_exotico = true;
				if (dynamic_cast<MamiferoExotico*>(it->second) == NULL)
				{
					is_mamifero_exotico = false;
				}
				if(is_mamifero_exotico)
				{
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
			}
			break;
		}
		case 8:
		{
			//repteis nativos
			notebook_consulta->set_current_page(8);
			list_store_repteis_nativos->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_reptil_nativo = true;
				if (dynamic_cast<ReptilNativo*>(it->second) == NULL)
				{
					is_reptil_nativo = false;
				}
				if(is_reptil_nativo)
				{
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
			break;
		}
		case 9:
		{
			//repteis exoticos
			notebook_consulta->set_current_page(9);
			list_store_repteis_exoticos->clear();
			for(map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
			{
				bool is_reptil_exotico = true;
				if (dynamic_cast<ReptilExotico*>(it->second) == NULL)
				{
					is_reptil_exotico = false;
				}
				if(is_reptil_exotico)
				{
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
			}
			break;
		}
	}
}

#include "JanelaPrincipal.h"
#include "JanelaCadastroFuncionario.h"
#include "JanelaCadastroAnimal.h"
#include "JanelaRemocaoFuncionario.h"
#include <fstream>

using namespace Gtk;
using namespace std;

JanelaPrincipal::JanelaPrincipal()
{
	ifstream funcionarios_csv("../Dados/funcionarios.csv");
	ifstream animais_csv("../Dados/animais.csv");

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
			Veterinario veterinario = veterinarios.find(stoi(palavras[6]))->second;
			Tratador tratador = tratadores.find(stoi(palavras[7]))->second;
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
	button_consulta_animal = new Button("Consultar animal");
	button_consulta_funcionario = new Button("Consultar funcionario");

	box_principal = new VBox;
	box_botoes = new HBox;


	//Configuração
	window->set_default_size(700, 50);
	window->set_title("PetFera");
	window->add(*box_principal);

	box_principal->add(*box_botoes);

	box_botoes->add(*button_cadastro_animal);
	box_botoes->add(*button_remocao_animal);
	box_botoes->add(*button_cadastro_funcionario);
	box_botoes->add(*button_remocao_funcionario);
	box_botoes->add(*button_consulta_animal);
	box_botoes->add(*button_consulta_funcionario);

	//Conexão
	button_cadastro_funcionario->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::CadastrarFuncionario));
	button_cadastro_animal->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::CadastrarAnimal));
	button_remocao_funcionario->signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::RemoverFuncionario));
}

JanelaPrincipal::~JanelaPrincipal()
{
	delete window;
	delete button_cadastro_animal;
	delete button_remocao_animal;
	delete button_cadastro_funcionario;
	delete button_remocao_funcionario;
	delete button_consulta_animal;
	delete button_consulta_funcionario;
	delete box_principal;
	delete box_botoes;
}

void JanelaPrincipal::Run()
{
	window->show_all();
	Main::run(*window);
}

void JanelaPrincipal::CadastrarFuncionario()
{
	JanelaCadastroFuncionario temp(veterinarios, tratadores);
	temp.Run();
}

void JanelaPrincipal::CadastrarAnimal()
{
	JanelaCadastroAnimal temp(veterinarios, tratadores, anfibios_exoticos, anfibios_nativos, aves_exoticas,
							  aves_nativas, mamiferos_exoticos, mamiferos_nativos, repteis_exoticos, repteis_nativos);
	temp.Run();
}

void JanelaPrincipal::RemoverFuncionario()
{
	JanelaRemocaoFuncionario temp(veterinarios, tratadores);
	temp.Run();
}
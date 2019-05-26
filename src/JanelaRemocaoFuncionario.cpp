#include "JanelaRemocaoFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaRemocaoFuncionario::JanelaRemocaoFuncionario(map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp)
{
	veterinarios = &vtemp;
	tratadores = &ttemp;

	//Inicialização
	window = new Window;
	button_confirmar = new Button("Remover");
	entry_id = new Entry;
	box_principal = new VBox;
	box_dados = new HBox(true);
	label_id = new Label("ID: ");

	//Configuração
	window->set_default_size(50, 100);
	window->set_title("Remover Funcionário");
	window->add(*box_principal);

	box_principal->add(*box_dados);
	box_principal->pack_start(*button_confirmar, PACK_SHRINK);

	box_dados->add(*label_id);
	box_dados->add(*entry_id);

	//Conexão
	button_confirmar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaRemocaoFuncionario::Remover));
}


/*  int id;
	string funcao;
	string nome_do_funcionario;
	string cpf;
	short idade;
	string tipo_sanguineo;
	char rh;
	string especialidade;
	string crmv;
	int nivel_de_seguranca;
	*/

JanelaRemocaoFuncionario::~JanelaRemocaoFuncionario()
{
	delete window;
	delete entry_id;
	delete button_confirmar;
	delete box_principal;
	delete box_dados;
	delete label_id;
}

void JanelaRemocaoFuncionario::Run()
{
	window->show_all();
	Main::run(*window);
}

void JanelaRemocaoFuncionario::Remover()
{
	string linha;
	int id = stoi(entry_id->get_text());
	vector<string> palavras;
	ifstream funcionarios_csv("../Dados/funcionarios.csv");

	if(funcionarios_csv.is_open())
	{
		ofstream funcionarios_temp("../Dados/TempFuncionario.csv");
		while(getline(funcionarios_csv, linha))
		{
			palavras = Separador_csv(linha);
			if(stoi(palavras[0]) != id)
				funcionarios_temp << linha << endl;
			else
			{
				if(palavras[1].compare("TRATADOR") == 0)
					tratadores->erase(id);
				else
					veterinarios->erase(id);
			}
		}
		remove("../Dados/funcionarios.csv");
		rename("../Dados/TempFuncionario.csv", "../Dados/funcionarios.csv");
		funcionarios_temp.close();
	}
	else
	{
		MessageDialog dialog(*window, "Arquivo funcionarios.csv não encontrado.");
		dialog.set_secondary_text("Provavelmente nenhum funcionário foi cadastrado, certifique-se que existe algum funcionário antes de remover.");
  		dialog.run();
	}

	window->close();
}
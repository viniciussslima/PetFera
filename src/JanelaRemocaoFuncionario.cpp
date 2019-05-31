#include "JanelaRemocaoFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaRemocaoFuncionario::JanelaRemocaoFuncionario(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp)
{
	valid_id = false;

	janela_principal = &jptemp;

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
	window->set_title("Remover Funcionário");
	window->add(*box_principal);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_id->set_icon_tooltip_text("ID inválido");

	box_principal->add(*box_dados);
	box_principal->pack_start(*button_confirmar, PACK_SHRINK);

	box_dados->add(*label_id);
	box_dados->add(*entry_id);

	//Conexão
	button_confirmar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaRemocaoFuncionario::Remover));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaRemocaoFuncionario::AtualizarIconeId));
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
	if(valid_id)
	{
		string linha;
		int id = stoi(entry_id->get_text());
		vector<string> palavras;
		ifstream funcionarios_csv("Dados/funcionarios.csv");

		if(funcionarios_csv.is_open())
		{
			ofstream funcionarios_temp("Dados/TempFuncionario.csv");
			while(getline(funcionarios_csv, linha))
			{
				palavras = Separador_csv(linha);
				if(stoi(palavras[0]) != id)
					funcionarios_temp << linha << endl;
				else
				{
					if(palavras[1].compare("TRATADOR") == 0)
					{
						janela_principal->AtualizarLista(0);
						tratadores->erase(id);
					}
					else
					{
						janela_principal->AtualizarLista(1);
						veterinarios->erase(id);
					}
				}
			}
			remove("Dados/funcionarios.csv");
			rename("Dados/TempFuncionario.csv", "Dados/funcionarios.csv");
			funcionarios_temp.close();
		}
		else
		{
			MessageDialog dialog(*window, "Arquivo funcionarios.csv não encontrado.");
			dialog.set_secondary_text("Provavelmente nenhum funcionário foi cadastrado, certifique-se que existe algum funcionário antes de remover.");
	  		dialog.run();
		}
	}
	else
	{
		MessageDialog dialog(*window, "Funcionário com ID inexistente.");
		dialog.set_secondary_text("Não foi encontrado nenhum funcionário com o id apresentado.");
  		dialog.run();
	}

	window->close();
}

void JanelaRemocaoFuncionario::AtualizarIconeId()
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
			entry_id->set_icon_tooltip_text("Não foi encontrado nenhum funcionário com esse ID");
		}
	}
	else
	{
		valid_id = false;
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_id->set_icon_tooltip_text("ID inválido");
	}
	
}
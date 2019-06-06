#include "JanelaRemocaoFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaRemocaoFuncionario::JanelaRemocaoFuncionario(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp, map<int, AnfibioExotico> &anetemp, 
										   map<int, AnfibioNativo> &anntemp, map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp,
										   map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, 
										   map<int, ReptilExotico> &retemp, map<int, ReptilNativo> &rntemp)
{
	valid_id = false;

	janela_principal = &jptemp;

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

	//Inicialização
	window = new Window;
	button_confirmar = new Button("Remover");
	entry_id = new Entry;
	box_principal = new VBox;
	box_dados = new HBox(true);
	label_id = new Label("ID: ");

	//Configuração
	window->set_title("Remover Funcionário");
	window->set_resizable(false);
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
						tratadores->erase(id);
						janela_principal->AtualizarLista(0);
					}
					else
					{
						veterinarios->erase(id);
						janela_principal->AtualizarLista(1);
					}
				}
			}
			remove("Dados/funcionarios.csv");
			rename("Dados/TempFuncionario.csv", "Dados/funcionarios.csv");
			funcionarios_temp.close();
		}
	window->close();
	}
	else
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Não foi encontrado nenhum funcionário com o id apresentado ou esse fucionário é responsavel por algum animal.");
  		dialog.run();
	}
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
		bool animal_sob_responsabilidade = false;

		if(it_v != veterinarios->end() || it_t != tratadores->end())
		{
			valid_id = true;
			entry_id->set_icon_from_pixbuf(pixbuf_check);
			entry_id->set_icon_tooltip_text("ID válido");
			
			for (map<int, AnfibioExotico>::iterator it = anfibios_exoticos->begin(); it != anfibios_exoticos->end(); it++)
			{
				if ((it->second).get_veterinario_id() == id ||
					(it->second).get_tratador_id() == id)
				{
					animal_sob_responsabilidade = true;
					break;
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, AnfibioNativo>::iterator it = anfibios_nativos->begin(); it != anfibios_nativos->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, AveExotico>::iterator it = aves_exoticas->begin(); it != aves_exoticas->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, AveNativo>::iterator it = aves_nativas->begin(); it != aves_nativas->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, MamiferoExotico>::iterator it = mamiferos_exoticos->begin(); it != mamiferos_exoticos->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, MamiferoNativo>::iterator it = mamiferos_nativos->begin(); it != mamiferos_nativos->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, ReptilExotico>::iterator it = repteis_exoticos->begin(); it != repteis_exoticos->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if (!animal_sob_responsabilidade)
			{
				for (map<int, ReptilNativo>::iterator it = repteis_nativos->begin(); it != repteis_nativos->end(); it++)
				{
					if ((it->second).get_veterinario_id() == id ||
						(it->second).get_tratador_id() == id)
					{
						animal_sob_responsabilidade = true;
						break;
					}
				}
			}
			if(animal_sob_responsabilidade)
			{
				valid_id = false;
				entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
				entry_id->set_icon_tooltip_text("Esse funcionario é responsavel por animais, impossivel removelo");
			}
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
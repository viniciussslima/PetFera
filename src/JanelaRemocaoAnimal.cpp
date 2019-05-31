#include "JanelaRemocaoAnimal.h"

using namespace Gtk;
using namespace std;

JanelaRemocaoAnimal::JanelaRemocaoAnimal(JanelaPrincipal &jptemp, map<int, AnfibioExotico> &anetemp, map<int, AnfibioNativo> &anntemp, 
										 map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp,
										 map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, 
										 map<int, ReptilExotico> &retemp, map<int, ReptilNativo> &rntemp)
{
	valid_id = false;

	janela_principal = &jptemp;

	anfibios_exoticos = &anetemp;
	anfibios_nativos = &anntemp;

	aves_exoticas = &avetemp;
	aves_nativas = &avntemp;

	mamiferos_exoticos = &metemp;
	mamiferos_nativos = &mntemp;

	repteis_exoticos = &retemp;
	repteis_nativos = &rntemp;

	Veterinario veterinario;
	Tratador tratador;

	//Inicialização
	window = new Window;
	button_confirmar = new Button("Remover");
	entry_id = new Entry;
	box_principal = new VBox;
	box_dados = new HBox(true);
	label_id = new Label("ID: ");

	//Configuração
	window->set_title("Remover Animal");
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
	button_confirmar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaRemocaoAnimal::Remover));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaRemocaoAnimal::AtualizarIconeId));
}

JanelaRemocaoAnimal::~JanelaRemocaoAnimal()
{
	delete window;
	delete entry_id;
	delete button_confirmar;
	delete box_principal;
	delete box_dados;
	delete label_id;
}

void JanelaRemocaoAnimal::Run()
{
	window->show_all();
	Main::run(*window);
}

void JanelaRemocaoAnimal::Remover()
{
	if(valid_id)
	{
		string linha;
		int id = stoi(entry_id->get_text());
		vector<string> palavras;
		ifstream animais_csv("Dados/animais.csv");

		if(animais_csv.is_open())
		{
			ofstream animais_temp("Dados/temp_animais.csv");
			while(getline(animais_csv, linha))
			{
				palavras = Separador_csv(linha);
				if(stoi(palavras[0]) != id)
					animais_temp << linha << endl;
				else
				{
					if(palavras[1].compare("AMPHIBIA") == 0)
				    {
						if(palavras[palavras.size() - 1].length() == 2)
						{
							janela_principal->AtualizarLista(2);
					    	anfibios_nativos->erase(id);
						}
					    else
					    {
					    	janela_principal->AtualizarLista(3);
					    	anfibios_exoticos->erase(id);
					    }
				    }
				    if(palavras[1].compare("AVES") == 0)
				    {
						if(palavras[palavras.size() - 1].length() == 2)
						{
							janela_principal->AtualizarLista(4);
					    	aves_nativas->erase(id);
						}
					    else
					    {
					    	janela_principal->AtualizarLista(5);
					    	aves_exoticas->erase(id);
					    }
				    }
				    if(palavras[1].compare("MAMMALIA") == 0)
				    {
						if(palavras[palavras.size() - 1].length() == 2)
						{
							janela_principal->AtualizarLista(6);
					    	mamiferos_nativos->erase(id);
						}
					    else
					    {
					    	janela_principal->AtualizarLista(7);
					    	mamiferos_exoticos->erase(id);
					    }
				    }
				    if(palavras[1].compare("REPTILIA") == 0)
				    {
						if(palavras[palavras.size() - 1].length() == 2)
						{
							janela_principal->AtualizarLista(8);
					    	repteis_nativos->erase(id);
						}
					    else
					    {
					    	janela_principal->AtualizarLista(9);
					    	repteis_exoticos->erase(id);
					    }
				    }
				}
			}
			remove("Dados/animais.csv");
			rename("Dados/temp_animais.csv", "Dados/animais.csv");
			animais_temp.close();
		}
		else
		{
			MessageDialog dialog(*window, "Arquivo animais.csv não encontrado.");
			dialog.set_secondary_text("Provavelmente nenhum animal foi cadastrado, certifique-se que existe algum animal antes de remover.");
	  		dialog.run();
		}
	}
	else
	{
		MessageDialog dialog(*window, "Animal com ID inexistente.");
		dialog.set_secondary_text("Não foi encontrado nenhum animal com o id apresentado.");
  		dialog.run();
	}

	window->close();
}

void JanelaRemocaoAnimal::AtualizarIconeId()
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

		map<int, AnfibioNativo>::iterator it_an_n = anfibios_nativos->find(id);
		map<int, AnfibioExotico>::iterator it_an_e = anfibios_exoticos->find(id);
		map<int, AveNativo>::iterator it_av_n = aves_nativas->find(id);
		map<int, AveExotico>::iterator it_av_e = aves_exoticas->find(id);
		map<int, MamiferoNativo>::iterator it_m_n = mamiferos_nativos->find(id);
		map<int, MamiferoExotico>::iterator it_m_e = mamiferos_exoticos->find(id);
		map<int, ReptilNativo>::iterator it_r_n = repteis_nativos->find(id);
		map<int, ReptilExotico>::iterator it_r_e = repteis_exoticos->find(id);

		if(it_an_n != anfibios_nativos->end() || it_an_e != anfibios_exoticos->end() ||
		   it_av_n != aves_nativas->end() || it_av_e != aves_exoticas->end() ||
		   it_m_n != mamiferos_nativos->end() || it_m_e != mamiferos_exoticos->end() ||
		   it_r_n != repteis_nativos->end() || it_r_e != repteis_exoticos->end())
		{
			valid_id = true;
			entry_id->set_icon_from_pixbuf(pixbuf_check);
			entry_id->set_icon_tooltip_text("ID válido");
		}
		else
		{
			valid_id = false;
			entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_id->set_icon_tooltip_text("Não foi encontrado nenhum animal com esse ID");
		}
	}
	else
	{
		valid_id = false;
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_id->set_icon_tooltip_text("ID inválido");
	}
}
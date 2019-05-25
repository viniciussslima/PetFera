#include "JanelaRemocaoAnimal.h"

using namespace Gtk;
using namespace std;

JanelaRemocaoAnimal::JanelaRemocaoAnimal(map<int, AnfibioExotico> &anetemp, map<int, AnfibioNativo> &anntemp, 
										 map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp,
										 map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, 
										 map<int, ReptilExotico> &retemp, map<int, ReptilNativo> &rntemp)
{
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
	window->set_default_size(50, 100);
	window->set_title("Remover Animal");
	window->add(*box_principal);

	box_principal->add(*box_dados);
	box_principal->add(*button_confirmar);

	box_dados->add(*label_id);
	box_dados->add(*entry_id);

	//Conexão
	button_confirmar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaRemocaoAnimal::Remover));
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
	string linha;
	int id = stoi(entry_id->get_text());
	vector<string> palavras;
	ifstream animais_csv("../Dados/animais.csv");

	if(animais_csv.is_open())
	{
		ofstream animais_temp("../Dados/temp_animais.csv");
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
				    	anfibios_nativos->erase(id);
				    else
				    	anfibios_exoticos->erase(id);
			    }
			    if(palavras[1].compare("AVES") == 0)
			    {
					if(palavras[palavras.size() - 1].length() == 2)
				    	aves_nativas->erase(id);
				    else
				    	aves_exoticas->erase(id);
			    }
			    if(palavras[1].compare("MAMMALIA") == 0)
			    {
					if(palavras[palavras.size() - 1].length() == 2)
				    	mamiferos_nativos->erase(id);
				    else
				    	mamiferos_exoticos->erase(id);
			    }
			    if(palavras[1].compare("REPTILIA") == 0)
			    {
					if(palavras[palavras.size() - 1].length() == 2)
				    	repteis_nativos->erase(id);
				    else
				    	repteis_exoticos->erase(id);
			    }
			}
		}
		remove("../Dados/animais.csv");
		rename("../Dados/temp_animais.csv", "../Dados/animais.csv");
		animais_temp.close();
	}
	else
	{
		MessageDialog dialog(*window, "Arquivo animais.csv não encontrado.");
		dialog.set_secondary_text("Provavelmente nenhum animal foi cadastrado, certifique-se que existe algum animal antes de remover.");
  		dialog.run();
	}

	window->close();
}
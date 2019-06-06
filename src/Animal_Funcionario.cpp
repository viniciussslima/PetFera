#include "Animal_Funcionario.h"

using namespace Gtk;
using namespace std;
AnimalFuncionario::AnimalFuncionario(){
	//inicialização
		window = new Window;
	button_confirmar = new Button("Remover");
	entry_id = new Entry;
	box_principal = new VBox;
	box_dados = new HBox(true);
	label_id = new Label("ID: ");


	//configuração
	window->set_title("Animais Do Funcionario");
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

}



void AnimalFuncionario::Procurar_Animal_por_funcionario()
{
	int id = stoi(entry_id->get_text());
	string linha;
	string linha_F;
	int v = 0;
	int t = 0;
	vector<string> palavras;
	vector<string> palavras_F;
	vector<int> animais_Veterinario;
	vector<int> animais_Tratador;
	ifstream animais_csv("Dados/animais.csv");

	if(animais_csv.is_open())
	{
		while(getline(animais_csv,linha))
		{
			palavras = Separador_csv(linha);
			if(stoi(palavras[6]) == id)
			{
				animais_Veterinario[v] = stoi(palavras[6]);
				v++;
			}
			if(stoi(palavras[7]) == id)
			{
				animais_Tratador[t] = stoi(palavras[7]);
				t++;
			}
		}
		animais_csv.close();
	}
	else
	{

	}



}
void Animal_Funcionario::Run()
{
	window->show_all();
	Main::run(*window);
}
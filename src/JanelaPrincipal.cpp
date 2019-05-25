#include "JanelaPrincipal.h"
#include "JanelaCadastroFuncionario.h"
#include "JanelaCadastroAnimal.h"

using namespace Gtk;
using namespace std;

JanelaPrincipal::JanelaPrincipal()
{
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

/*
		map<int, Veterinario>& veterinarios;
		map<int, Tratador>& tratadores;

		map<int, AnfibioExotico>& anfibios_exoticos;
		map<int, AnfibioNativo>& anfibios_nativos;

		map<int, AveExotico>& aves_exoticas;
		map<int, AveNativo>& aves_nativas;

		map<int, MamiferoExotico>& mamiferos_exoticos;
		map<int, MamiferoNativo>& mamiferos_nativos;

		map<int, ReptilExotico>& repteis_exoticos;
		map<int, ReptilNativo>& repteis_nativos;
*/
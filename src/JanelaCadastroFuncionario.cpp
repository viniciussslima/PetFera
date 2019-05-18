#include "JanelaCadastroFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaCadastroFuncionario::JanelaCadastroFuncionario()
{
	//Inicialização
	window = new Window;

	entry_id = new Entry;
	entry_nome_do_funcionario = new Entry;
	entry_cpf = new Entry;
	entry_idade = new Entry;
	entry_especialidade = new Entry;
	entry_crmv = new Entry;

	combo_box_fucao = new ComboBox;
	combo_box_tipo_sanguineo = new ComboBox;
	combo_box_rh = new ComboBox;
	combo_box_nivel_de_segurança = new ComboBox;

	box_principal = new VBox;

	//Configuração
	window->set_default_size(700, 50);
	window->set_title("PetFera");
	window->add(*box_principal);

	box_botoes->add(*entry_id);
	box_botoes->add(*combo_box_fucao);
	box_botoes->add(*entry_nome_do_funcionario);
	box_botoes->add(*entry_cpf);
	box_botoes->add(*entry_idade);
	box_botoes->add(*combo_box_tipo_sanguineo);
	box_botoes->add(*combo_box_rh);
	box_botoes->add(*entry_especialidade);
	box_botoes->add(*entry_crmv);
	box_botoes->add(*button_cadastrar);	
	box_botoes->add(*combo_box_nivel_de_segurança);

	//Conexão
	//addTableButton->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::addMesaWindow));
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

JanelaCadastroFuncionario::~JanelaCadastroFuncionario()
{
	delete window;
	delete entry_id;
	delete entry_nome_do_funcionario;
	delete entry_cpf;
	delete entry_idade;
	delete entry_especialidade;
	delete entry_crmv;
	delete combo_box_fucao;
	delete combo_box_tipo_sanguineo;
	delete combo_box_rh;
	delete combo_box_nivel_de_segurança;
	delete box_principal;
}

void JanelaCadastroFuncionario::run()
{
	window->show_all();
	Main::run(*window);
}
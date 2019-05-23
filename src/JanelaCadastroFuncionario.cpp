#include <fstream>
#include "JanelaCadastroFuncionario.h"
#include "Tratador.h"
#include "Veterinario.h"

using namespace Gtk;
using namespace std;

JanelaCadastroFuncionario::JanelaCadastroFuncionario()
{
	//Inicialização
	window = new Window;

	button_cadastrar = new Button("Cadastrar");

	entry_id = new Entry;
	entry_nome_do_funcionario = new Entry;
	entry_cpf = new Entry;
	entry_idade = new Entry;
	entry_especialidade = new Entry;
	entry_crmv = new Entry;

	combo_box_fucao = new ComboBoxText;
	combo_box_tipo_sanguineo = new ComboBoxText;
	combo_box_rh = new ComboBoxText;
	combo_box_nivel_de_seguranca = new ComboBoxText;

	box_principal = new VBox;
	box_dados = new HBox;
	box_esquerda = new VBox;
	box_direita = new VBox;

	label_id = new Label("ID: ");
	label_funcao = new Label("Função: ");
	label_nome_do_funcionario = new Label("Nome: ");
	label_cpf = new Label("CPF: ");
	label_idade = new Label("Idade: ");
	label_tipo_sanguineo = new Label("Tipo Sanguineo: ");
	label_rh = new Label("RH: ");
	label_especialidade = new Label("Especialidade: ");
	label_crmv = new Label("CRMV: ");
	label_nivel_de_seguranca = new Label("Nivel de segurança: ");

	//Configuração
	window->set_default_size(50, 100);
	window->set_title("PetFera");
	window->add(*box_principal);

	combo_box_fucao->append("Veterinario");
	combo_box_fucao->append("Tratador");
	combo_box_fucao->set_active(0);

	combo_box_tipo_sanguineo->append("A");
	combo_box_tipo_sanguineo->append("B");
	combo_box_tipo_sanguineo->append("AB");
	combo_box_tipo_sanguineo->append("O");
	combo_box_tipo_sanguineo->set_active(0);

	combo_box_rh->append("+");
	combo_box_rh->append("-");
	combo_box_rh->set_active(0);

	combo_box_nivel_de_seguranca->append("0");
	combo_box_nivel_de_seguranca->append("1");
	combo_box_nivel_de_seguranca->append("2");
	combo_box_nivel_de_seguranca->set_active(0);

	box_principal->add(*box_dados);
	box_principal->add(*button_cadastrar);
	box_dados->add(*box_esquerda);
	box_dados->add(*box_direita);

	box_esquerda->add(*label_id);
	box_esquerda->add(*label_funcao);
	box_esquerda->add(*label_nome_do_funcionario);
	box_esquerda->add(*label_cpf);
	box_esquerda->add(*label_idade);
	box_esquerda->add(*label_tipo_sanguineo);
	box_esquerda->add(*label_rh);
	box_esquerda->add(*label_especialidade);
	box_esquerda->add(*label_crmv);
	box_esquerda->add(*label_nivel_de_seguranca);
	
	box_direita->add(*entry_id);
	box_direita->add(*combo_box_fucao);
	box_direita->add(*entry_nome_do_funcionario);
	box_direita->add(*entry_cpf);
	box_direita->add(*entry_idade);
	box_direita->add(*combo_box_tipo_sanguineo);
	box_direita->add(*combo_box_rh);
	box_direita->add(*entry_especialidade);
	box_direita->add(*entry_crmv);
	box_direita->add(*combo_box_nivel_de_seguranca);

	//Conexão
	button_cadastrar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::Cadastrar));
	combo_box_fucao->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::MudarFuncionario) );
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
	delete combo_box_nivel_de_seguranca;
	delete button_cadastrar;
	delete box_principal;
	delete box_dados;
	delete box_esquerda;
	delete box_direita;
	delete label_id;
	delete label_funcao;
	delete label_nome_do_funcionario;
	delete label_cpf;
	delete label_idade;
	delete label_tipo_sanguineo;
	delete label_rh;
	delete label_especialidade;
	delete label_crmv;
	delete label_nivel_de_seguranca;
}

void JanelaCadastroFuncionario::Run()
{
	window->show_all();
	combo_box_nivel_de_seguranca->hide();
	label_nivel_de_seguranca->hide();
	Main::run(*window);
}

void JanelaCadastroFuncionario::Cadastrar()
{
	ofstream outfile;
	string tipo_sanguineo;
	char rh;
	switch(combo_box_tipo_sanguineo->get_active_row_number())
	{
		case 0:
			tipo_sanguineo = "A";
			break;
		case 1:
			tipo_sanguineo = "B";
			break;
		case 2:
			tipo_sanguineo = "AB";
			break;
		case 3:
			tipo_sanguineo = "O";
			break;
	}
	switch(combo_box_rh->get_active_row_number())
	{
		case 0:
			rh = '+';
			break;
		case 1:
			rh = '-';
			break;
	}

	switch(combo_box_fucao->get_active_row_number())
	{
		case 0:
		{
			Veterinario veterinario(stoi(entry_id->get_text()), entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), entry_crmv->get_text());
			outfile.open("../Dados/funcionarios.csv", ios::app);
			outfile << veterinario << endl;
			break;
		}
		case 1:
		{
			Tratador tratador(stoi(entry_id->get_text()), entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), combo_box_nivel_de_seguranca->get_active_row_number());
			outfile.open("../Dados/funcionarios.csv", ios::app);
			outfile << tratador << endl;
			break;
		}
	}
	window->close();
}

void JanelaCadastroFuncionario::MudarFuncionario()
{
	switch(combo_box_fucao->get_active_row_number())
	{
		case 0:
			combo_box_nivel_de_seguranca->hide();
			label_nivel_de_seguranca->hide();
			entry_crmv->show();
			label_crmv->show();
			break;
		case 1:
			combo_box_nivel_de_seguranca->show();
			label_nivel_de_seguranca->show();
			entry_crmv->hide();
			label_crmv->hide();
			break;
	}
}
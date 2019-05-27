#include <fstream>
#include "JanelaCadastroFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaCadastroFuncionario::JanelaCadastroFuncionario(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp)
{
	janela_principal = &jptemp;

	veterinarios = &vtemp;
	tratadores = &ttemp;

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
	box_esquerda = new VBox(true);
	box_direita = new VBox(true);

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
	window->set_title("Cadastrar Funcionário");
	window->add(*box_principal);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_cpf->set_icon_from_pixbuf(pixbuf_uncheck);

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
	box_principal->pack_start(*button_cadastrar, PACK_SHRINK);
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
	combo_box_fucao->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::MudarFuncionario));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeId));
	entry_cpf->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeCPF));
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
	ofstream outfile("Dados/funcionarios.csv", ios::app);
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
			veterinarios->insert(pair<int, Veterinario>(stoi(entry_id->get_text()), veterinario));
			outfile << veterinario << endl;
			//janela_principal->AtualizarLista(1);
			break;
		}
		case 1:
		{
			Tratador tratador(stoi(entry_id->get_text()), entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), combo_box_nivel_de_seguranca->get_active_row_number());
			tratadores->insert(pair<int, Tratador>(stoi(entry_id->get_text()), tratador));
			outfile << tratador << endl;
			//janela_principal->AtualizarLista(0);
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
			AtualizarIconeId();
			break;
		case 1:
			combo_box_nivel_de_seguranca->show();
			label_nivel_de_seguranca->show();
			entry_crmv->hide();
			label_crmv->hide();
			AtualizarIconeId();
			break;
	}
}

void JanelaCadastroFuncionario::AtualizarIconeId()
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
			entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		else
			entry_id->set_icon_from_pixbuf(pixbuf_check);
	}
	else
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	
}

void JanelaCadastroFuncionario::AtualizarIconeCPF()
{
	string temp = entry_cpf->get_text();
	bool is_cpf = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]) && (i == 0 || i == 1 || i == 2 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10 || i == 12 || i == 13))
		{
			is_cpf = false;
			break;
		}
		if(((i == 3 || i == 7) && !(temp[i] == '.')) || (i == 11 && !(temp[i] == '-')))
		{
			is_cpf = false;
			break;
		}
	}

	if(is_cpf && temp.size() == 14)
	{
		//string cpf = temp[0] + temp[1] + temp[2] + temp[4] + temp[5] + temp[6] + temp[8] + temp[9] + temp[10] + temp[12] + temp[13];
		string cpf;
		int verificador_1 = 0, verificador_2 = 0;

		for(int i = 0; i < 14; i++)
		{
			if(i != 3 && i != 7 && i != 11)
				cpf += temp[i];
		}

		for(int i = 0; i < 10; i++)
		{
			if(i != 9)
				verificador_1 += stoi(cpf.substr(i, 1)) * (10 - i);
			verificador_2 += stoi(cpf.substr(i, 1)) * (11 - i);
		}

		if(verificador_1 * 10 % 11 == stoi(cpf.substr(9, 1)) && verificador_2 * 10 % 11 == stoi(cpf.substr(10, 1)))
			entry_cpf->set_icon_from_pixbuf(pixbuf_check);
		else
			entry_cpf->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
		entry_cpf->set_icon_from_pixbuf(pixbuf_uncheck);
}
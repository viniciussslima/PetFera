#include <fstream>
#include "JanelaCadastroFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaCadastroFuncionario::JanelaCadastroFuncionario(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp)
{
	valid_id = false;
	valid_nome_do_funcionario = false;
	valid_cpf = false;
	valid_idade = false;
	valid_especialidade = false;
	valid_crmv = false;

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
	window->set_title("Cadastrar Funcionário");
	window->set_resizable(false);
	window->add(*box_principal);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_id->set_icon_tooltip_text("ID válido");
	entry_nome_do_funcionario->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_cpf->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_cpf->set_icon_tooltip_text("CPF inválido");
	entry_idade->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_especialidade->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_crmv->set_icon_from_pixbuf(pixbuf_uncheck);

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
	
	box_direita->pack_start(*entry_id, PACK_SHRINK);
	box_direita->pack_start(*combo_box_fucao, PACK_SHRINK);
	box_direita->pack_start(*entry_nome_do_funcionario, PACK_SHRINK);
	box_direita->pack_start(*entry_cpf, PACK_SHRINK);
	box_direita->pack_start(*entry_idade, PACK_SHRINK);
	box_direita->pack_start(*combo_box_tipo_sanguineo, PACK_SHRINK);
	box_direita->pack_start(*combo_box_rh, PACK_SHRINK);
	box_direita->pack_start(*entry_especialidade, PACK_SHRINK);
	box_direita->pack_start(*entry_crmv, PACK_SHRINK);
	box_direita->pack_start(*combo_box_nivel_de_seguranca, PACK_SHRINK);

	//Conexão
	button_cadastrar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::Cadastrar));
	combo_box_fucao->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::MudarFuncionario));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeId));
	entry_nome_do_funcionario->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeNomeDoFuncionario));
	entry_idade->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeIdade));
	entry_cpf->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeCPF));
	entry_especialidade->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeEspecialidade));
	entry_crmv->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroFuncionario::AtualizarIconeCRMV));
}

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
	if(!valid_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi encontrado um funcionário com o ID apresentado, funcionários não podem ter IDs iguais.");
  		dialog.run();
	}
	else if(!valid_nome_do_funcionario)
	{
		MessageDialog dialog(*window, "Nome inválido.");
		dialog.set_secondary_text("Falta preencher o nome do funcionário.");
  		dialog.run();
	}
	else if(!valid_cpf)
	{
		MessageDialog dialog(*window, "CPF inválido.");
		dialog.set_secondary_text("O CPF apresentado é inválido.");
  		dialog.run();
	}
	else if(!valid_idade)
	{
		MessageDialog dialog(*window, "Idade inválida.");
		dialog.set_secondary_text("Falta preencher ou a idade é menor ou igual a 0.");
  		dialog.run();
	}
	else if(!valid_especialidade)
	{
		MessageDialog dialog(*window, "Especialidade inválida.");
		dialog.set_secondary_text("Falta preencher a especialidade do funcionário.");
  		dialog.run();
	}
	else if(!valid_crmv)
	{
		MessageDialog dialog(*window, "CRMV inválida.");
		dialog.set_secondary_text("Falta preencher a CRMV do funcionário.");
  		dialog.run();
	}
	else
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
				janela_principal->AtualizarLista(1);
				break;
			}
			case 1:
			{
				Tratador tratador(stoi(entry_id->get_text()), entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), combo_box_nivel_de_seguranca->get_active_row_number());
				tratadores->insert(pair<int, Tratador>(stoi(entry_id->get_text()), tratador));
				outfile << tratador << endl;
				janela_principal->AtualizarLista(0);
				break;
			}
		}
		window->close();
	}
}

void JanelaCadastroFuncionario::MudarFuncionario()
{
	switch(combo_box_fucao->get_active_row_number())
	{
		case 0:
			valid_crmv = false;
			combo_box_nivel_de_seguranca->hide();
			label_nivel_de_seguranca->hide();
			entry_crmv->show();
			label_crmv->show();
			AtualizarIconeId();
			break;
		case 1:
			valid_crmv = true;
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
		{
			valid_id = false;
			entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_id->set_icon_tooltip_text("Algum outro funcionário já possui esse ID");
		}
		else
		{
			valid_id = true;
			entry_id->set_icon_from_pixbuf(pixbuf_check);
			entry_id->set_icon_tooltip_text("ID válido");
		}
	}
	else
	{
		valid_id = false;
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_id->set_icon_tooltip_text("ID inválido");
	}
}

void JanelaCadastroFuncionario::AtualizarIconeNomeDoFuncionario()
{
	string temp = entry_nome_do_funcionario->get_text();
	if(temp.empty())
	{
			valid_nome_do_funcionario = false;
			entry_nome_do_funcionario->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_nome_do_funcionario = true;
		entry_nome_do_funcionario->set_icon_from_pixbuf(pixbuf_check);
	}
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
		{
			valid_cpf = true;
			entry_cpf->set_icon_from_pixbuf(pixbuf_check);
			entry_cpf->set_icon_tooltip_text("CPF válido");
		}
		else
		{
			valid_cpf = false;
			entry_cpf->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_cpf->set_icon_tooltip_text("CPF inválido");
		}
	}
	else
	{
		valid_cpf = false;
		entry_cpf->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_cpf->set_icon_tooltip_text("CPF inválido");
	}
}

void JanelaCadastroFuncionario::AtualizarIconeIdade()
{
	int temp;
	try
	{
		temp = stoi(entry_idade->get_text());
	}
	catch(exception &ex)
	{
		valid_idade = false;
		entry_idade->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_idade->set_icon_tooltip_text("Idade inválida");
		return;
	}	
	if(temp <= 0)
	{
			valid_idade = false;
			entry_idade->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_idade = true;
		entry_idade->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroFuncionario::AtualizarIconeEspecialidade()
{
	string temp = entry_especialidade->get_text();
	if(temp.empty())
	{
			valid_especialidade = false;
			entry_especialidade->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_especialidade = true;
		entry_especialidade->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroFuncionario::AtualizarIconeCRMV()
{
	string temp = entry_crmv->get_text();
	if(temp.empty())
	{
			valid_crmv = false;
			entry_crmv->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_crmv = true;
		entry_crmv->set_icon_from_pixbuf(pixbuf_check);
	}
}
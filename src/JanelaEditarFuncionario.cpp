/**
* @file JanelaEditarFuncionario.cpp
* @brief Implementação da classe JanelaEditarFuncionario.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "JanelaEditarFuncionario.h"

using namespace Gtk;
using namespace std;

/**
* @brief Construtor padrão da classe JanelaEditarAnimal.
*/

JanelaEditarFuncionario::JanelaEditarFuncionario(){}

/**
* @brief construtor parametrizado da classe JanelaEditarFuncionario.
* @param jptemp Janela principal do programa.
* @param funtemp  Map que contém todos os funcinários cadastrados.
* @param anitemp Map que contém todos os animais cadastrados.
*/

JanelaEditarFuncionario::JanelaEditarFuncionario(JanelaPrincipal &jptemp, map<int, Funcionario*> &funtemp, map<int, Animal*> &anitemp, int pagtemp, int idtemp)
{
	// Atribuição de true para todas as variáveis boleanas que representão 
	// se as informações digitados sobre o funcionário são validas ou não.
	valid_nome_do_funcionario = true;
	valid_cpf = true;
	valid_idade = true;
	valid_especialidade = true;
	valid_crmv = true;

	// Atribui os endereços de memória dos maps recebidos como parâmetros para os maps da classe JanelaEditarAnimal.
	janela_principal = &jptemp;

	funcionarios = &funtemp;
	animais = &anitemp;

	// Atribui os valores de pagtemp e idtemp para os atributos pagina e id da classe JanelaBuscaAnimais.
	pagina = pagtemp;
	id = idtemp;

	// Inicialização dos atributos da classe GTK.
	window = new Window;

	button_Editar = new Button("Editar");

	entry_nome_do_funcionario = new Entry;
	entry_cpf = new Entry;
	entry_idade = new Entry;
	entry_especialidade = new Entry;
	entry_crmv = new Entry;

	combo_box_nivel_de_seguranca = new ComboBoxText;
	combo_box_tipo_sanguineo = new ComboBoxText;

	radio_button_veterinario = new RadioButton("Veterinário");
	radio_button_tratador = new RadioButton("Tratador");
	radio_button_rh_negativo = new RadioButton("-");
	radio_button_rh_positivo = new RadioButton("+");

	box_principal = new VBox;
	box_dados = new HBox;
	box_esquerda = new VBox(true);
	box_direita = new VBox(true);
	box_funcao = new HBox(true);
	box_rh = new HBox(true);

	label_id = new Label("ID: ");
	label_id_numero = new Label(to_string(id));
	label_funcao = new Label("Função: ");
	label_nome_do_funcionario = new Label("Nome: ");
	label_cpf = new Label("CPF: ");
	label_idade = new Label("Idade: ");
	label_tipo_sanguineo = new Label("Tipo Sanguineo: ");
	label_rh = new Label("RH: ");
	label_especialidade = new Label("Especialidade: ");
	label_crmv = new Label("CRMV: ");
	label_nivel_de_seguranca = new Label("Nivel de segurança: ");

	// Configuração dos atributos da classe GTK.
	window->set_title("Editar Funcionário");
	window->set_resizable(false);
	window->add(*box_principal);
	window->set_transient_for(*janela_principal->window);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_nome_do_funcionario->set_icon_from_pixbuf(pixbuf_check);
	entry_cpf->set_icon_from_pixbuf(pixbuf_check);
	entry_cpf->set_icon_tooltip_text("CPF válido");
	entry_idade->set_icon_from_pixbuf(pixbuf_check);
	entry_especialidade->set_icon_from_pixbuf(pixbuf_check);
	entry_crmv->set_icon_from_pixbuf(pixbuf_check);

	combo_box_tipo_sanguineo->append("A");
	combo_box_tipo_sanguineo->append("B");
	combo_box_tipo_sanguineo->append("AB");
	combo_box_tipo_sanguineo->append("O");

	combo_box_nivel_de_seguranca->append("0");
	combo_box_nivel_de_seguranca->append("1");
	combo_box_nivel_de_seguranca->append("2");
	combo_box_nivel_de_seguranca->set_active(0);

	radio_button_tratador->join_group(*radio_button_veterinario);
	radio_button_rh_negativo->join_group(*radio_button_rh_positivo);

	box_principal->add(*box_dados);
	box_principal->pack_start(*button_Editar, PACK_SHRINK);
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
	
	box_direita->pack_start(*label_id_numero, PACK_SHRINK);
	box_direita->pack_start(*box_funcao, PACK_SHRINK);
	box_direita->pack_start(*entry_nome_do_funcionario, PACK_SHRINK);
	box_direita->pack_start(*entry_cpf, PACK_SHRINK);
	box_direita->pack_start(*entry_idade, PACK_SHRINK);
	box_direita->pack_start(*combo_box_tipo_sanguineo, PACK_SHRINK);
	box_direita->pack_start(*box_rh, PACK_SHRINK);
	box_direita->pack_start(*entry_especialidade, PACK_SHRINK);
	box_direita->pack_start(*entry_crmv, PACK_SHRINK);
	box_direita->pack_start(*combo_box_nivel_de_seguranca, PACK_SHRINK);

	box_funcao->pack_start(*radio_button_veterinario, PACK_SHRINK);
	box_funcao->pack_start(*radio_button_tratador, PACK_SHRINK);

	box_rh->pack_start(*radio_button_rh_positivo, PACK_SHRINK);
	box_rh->pack_start(*radio_button_rh_negativo, PACK_SHRINK);

	SetInformacooes();

	// Conexões dos atributos da classe GTK.
	button_Editar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::Editar));
	radio_button_veterinario->signal_toggled().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::MudarFuncionario));
	entry_nome_do_funcionario->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::AtualizarIconeNomeDoFuncionario));
	entry_idade->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::AtualizarIconeIdade));
	entry_cpf->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::AtualizarIconeCPF));
	entry_especialidade->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::AtualizarIconeEspecialidade));
	entry_crmv->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::AtualizarIconeCRMV));
}

/**
* @brief Destrutor da classe JanelaEditarFuncionario.
*/

JanelaEditarFuncionario::~JanelaEditarFuncionario()
{
	delete window;
	delete entry_nome_do_funcionario;
	delete entry_cpf;
	delete entry_idade;
	delete entry_especialidade;
	delete entry_crmv;
	delete radio_button_veterinario;
	delete radio_button_tratador;
	delete combo_box_tipo_sanguineo;
	delete radio_button_rh_negativo;
	delete radio_button_rh_positivo;
	delete combo_box_nivel_de_seguranca;
	delete button_Editar;
	delete box_principal;
	delete box_dados;
	delete box_esquerda;
	delete box_direita;
	delete box_funcao;
	delete box_rh;
	delete label_id;
	delete label_id_numero;
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

/**
* @brief Método que inicia a janela de edição de funcionários.
*/

void JanelaEditarFuncionario::Run()
{
	Main::run(*window);
}

/**
* @brief Método que escolhe os widgets que vão aparece e escreve as informações do funcionário nesse widgets 
* de acordo com o a função do funcinário escolhido.
*/

void JanelaEditarFuncionario::SetInformacooes()
{
	window->show_all();
	
	map<int, Funcionario*>::iterator it = funcionarios->find(id);
	
	entry_nome_do_funcionario->set_text((it->second)->get_nome());

	entry_cpf->set_text((it->second)->get_cpf());

	entry_idade->set_text(to_string((it->second)->get_idade()));

	string tipo_sanguineo = (it->second)->get_tipo_sanguineo();
	if (tipo_sanguineo.compare("A") == 0)
	{
		combo_box_tipo_sanguineo->set_active(0);
	}
	else if (tipo_sanguineo.compare("B") == 0)
	{
		combo_box_tipo_sanguineo->set_active(1);
	}
	else if (tipo_sanguineo.compare("AB") == 0)
	{
		combo_box_tipo_sanguineo->set_active(2);
	}
	else if (tipo_sanguineo.compare("O") == 0)
	{
		combo_box_tipo_sanguineo->set_active(3);
	}

	switch((it->second)->get_rh())
	{
		case '+':
			radio_button_rh_positivo->set_active(true);
			break;
		case '-':
			radio_button_rh_negativo->set_active(false);
			break;
	}

	entry_especialidade->set_text((it->second)->get_especialidade());

	if (pagina == 0) // Se a pagina é igual a 0, o funcionário escolhido é um tratador.
	{
		radio_button_tratador->set_active(true);
		MudarFuncionario();

		switch(dynamic_cast<Tratador*>(it->second)->get_nivel_de_seguranca())
		{
		case 0:
			combo_box_nivel_de_seguranca->set_active(0);
			break;
		case 1:
			combo_box_nivel_de_seguranca->set_active(1);
			break;
		case 2:
			combo_box_nivel_de_seguranca->set_active(2);
			break;
		}
	
	}
	else // Se a pagina é diferente de 0, o funcionário escolhido é um veteriário.
	{
		radio_button_veterinario->set_active(true);
		MudarFuncionario();

		entry_crmv->set_text(dynamic_cast<Veterinario*>(it->second)->get_crmv());
	}
}

/**
* @brief Método que salva todas as informações escritas se elas forem válidas.
*/

void JanelaEditarFuncionario::Editar()
{
	// Verificação se todas as informações são validas, caso uma delas não seja
	// aparecerá uma tela com um aviso informando qual a informação que está incorreta.
	if(Responsabilidade(*animais, id) && 
		pagina == 0 && radio_button_veterinario->get_active())
	{
			MessageDialog dialog(*window, "Erro.");
			dialog.set_secondary_text("Impossivel mudar a função desse funcionário, pois ele é responsavel por animais.");
  			dialog.run();
	}
	else if(Responsabilidade(*animais, id) && 
		pagina == 1 && radio_button_tratador->get_active())
	{
			MessageDialog dialog(*window, "Erro.");
			dialog.set_secondary_text("Impossivel mudar a função desse funcionário, pois ele é responsavel por animais.");
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
	// Caso todas as informações estiverem corretas as antigas informações do funcionário são apagadas e
	// as novas são escritas.
	else
	{
		RemoverFuncionario(*janela_principal, *funcionarios, id);
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

		if(radio_button_rh_positivo->get_active())
			rh = '+';
		else
			rh = '-';

		// Dependendo da função do funcionário a operação é diferente.
		if(radio_button_veterinario->get_active())
		{
			Funcionario *veterinario = new Veterinario(id, entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), entry_crmv->get_text());
			funcionarios->insert(pair<int, Funcionario*>(id, veterinario));
			outfile << *veterinario << endl;
			janela_principal->AtualizarLista(1);
		}
		else
		{
			Funcionario *tratador = new Tratador(id, entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), combo_box_nivel_de_seguranca->get_active_row_number());
			funcionarios->insert(pair<int, Funcionario*>(id, tratador));
			outfile << *tratador << endl;
			janela_principal->AtualizarLista(0);
		}
		window->close();
	}
}

/**
* @brief Método que decide os widgets que vão aparecer de acordo com a função do funcionário.
*/

void JanelaEditarFuncionario::MudarFuncionario()
{
	if(radio_button_veterinario->get_active())
	{
		if (pagina == 0)
		{
			valid_crmv = false;
			entry_crmv->set_icon_from_pixbuf(pixbuf_uncheck);
		}

		combo_box_nivel_de_seguranca->hide();
		label_nivel_de_seguranca->hide();
		entry_crmv->show();
		label_crmv->show();
	}
	else
	{
		valid_crmv = true;
		combo_box_nivel_de_seguranca->show();
		label_nivel_de_seguranca->show();
		entry_crmv->hide();
		label_crmv->hide();
	}
}

/**
* @brief Método que é responsável para atualizar o icone de válido ou inválido do nome do funcionário.
*/

void JanelaEditarFuncionario::AtualizarIconeNomeDoFuncionario()
{
	string temp = entry_nome_do_funcionario->get_text();
	if(temp.empty()) // Caso o nome do funcionario seja inválido.
	{
		valid_nome_do_funcionario = false;
		entry_nome_do_funcionario->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else // Caso o nome do funcionario seja válido.
	{
		valid_nome_do_funcionario = true;
		entry_nome_do_funcionario->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que é responsável para atualizar o icone de válido ou inválido do CPF.
*/

void JanelaEditarFuncionario::AtualizarIconeCPF()
{
	string temp = entry_cpf->get_text();
	bool is_cpf = true;
	//Verificando se o texto é na formatação de um CPF
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
	//Caso o dado informado estiver na forma de um cpf
	if(is_cpf && temp.size() == 14)
	{
		string cpf;
		int verificador_1 = 0, verificador_2 = 0;
		//Transformando a string da entry em uma string só com os numeros do CPF
		for(int i = 0; i < 14; i++)
		{
			if(i != 3 && i != 7 && i != 11)
				cpf += temp[i];
		}
		//Cálculo para validação do CPF
		for(int i = 0; i < 10; i++)
		{
			if(i != 9)
				verificador_1 += stoi(cpf.substr(i, 1)) * (10 - i);
			verificador_2 += stoi(cpf.substr(i, 1)) * (11 - i);
		}
		//Caso o CPF for válido
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

/**
* @brief Método que é responsável para atualizar o icone de válido ou inválido da idade.
*/

void JanelaEditarFuncionario::AtualizarIconeIdade()
{
	string entry_text = entry_idade->get_text();
	int temp;
	bool is_numeric = true;
	//Verificado se todos os caracteres são digitos
	for(unsigned int i = 0; i < entry_text.length(); i++)
	{
		if(!isdigit(entry_text[i]))
		{
			is_numeric = false;
			break;
		}
	}
	//Tenta fazer o stoI, existe a possibilidade de dar erro quando não houver nada digitado
	try
	{
		temp = stoi(entry_text);
	}
	catch(exception &ex)
	{
		valid_idade = false;
		entry_idade->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_idade->set_icon_tooltip_text("Idade inválida");
		return;
	}
	//Se a idade for maior que 0 e for numerico implica que é um dado válido
	if(temp > 0 && is_numeric)
	{
		valid_idade = true;
		entry_idade->set_icon_from_pixbuf(pixbuf_check);
	}
	else
	{
		valid_idade = false;
		entry_idade->set_icon_from_pixbuf(pixbuf_uncheck);
	}
}

/**
* @brief Método que é responsável para atualizar o icone de válido ou inválido da especialidade.
*/

void JanelaEditarFuncionario::AtualizarIconeEspecialidade()
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

/**
* @brief Método que é responsável para atualizar o icone de válido ou inválido do CRMV.
*/

void JanelaEditarFuncionario::AtualizarIconeCRMV()
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
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
* @param vtemp  Map que contém todos os veterinários cadastrados.
* @param ttemp Map que contém todos os tratadores cadastrados.
* @param anetemp Map que contém todos os anfíbios exóticos cadastrados.
* @param anntemp Map que contém todos os anfíbios nativos cadastrados.
* @param avetemp Map que contém todas as aves exóticas cadastrados.
* @param avntemp Map que contém todas as aves nativas cadastrados.
* @param metemp Map que contém todos os mamíferos exóticos cadastrados.
* @param mntemp Map que contém todos os mamíferos nativos cadastrados.
* @param retemp Map que contém todos os reptéis exóticos cadastrados.
* @param rntemp Map que contém todos os reptéis nativos cadastrados.
* @param pagtemp Número que representa a pagina do notbook que o usuário estava vendo.
* @param idtemp Número que representa o ID do funcionário que foi selecionado pelo o usuário.
*/

JanelaEditarFuncionario::JanelaEditarFuncionario(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp, map<int, AnfibioExotico> &anetemp, 
										   map<int, AnfibioNativo> &anntemp, map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp,
										   map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, 
										   map<int, ReptilExotico> &retemp, map<int, ReptilNativo> &rntemp, 
										   int pagtemp, int idtemp)
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

	combo_box_fucao = new ComboBoxText;
	combo_box_tipo_sanguineo = new ComboBoxText;
	combo_box_rh = new ComboBoxText;
	combo_box_nivel_de_seguranca = new ComboBoxText;

	box_principal = new VBox;
	box_dados = new HBox;
	box_esquerda = new VBox(true);
	box_direita = new VBox(true);

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

	combo_box_fucao->append("Veterinario");
	combo_box_fucao->append("Tratador");

	combo_box_tipo_sanguineo->append("A");
	combo_box_tipo_sanguineo->append("B");
	combo_box_tipo_sanguineo->append("AB");
	combo_box_tipo_sanguineo->append("O");

	combo_box_rh->append("+");
	combo_box_rh->append("-");

	combo_box_nivel_de_seguranca->append("0");
	combo_box_nivel_de_seguranca->append("1");
	combo_box_nivel_de_seguranca->append("2");
	combo_box_nivel_de_seguranca->set_active(0);

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
	box_direita->pack_start(*combo_box_fucao, PACK_SHRINK);
	box_direita->pack_start(*entry_nome_do_funcionario, PACK_SHRINK);
	box_direita->pack_start(*entry_cpf, PACK_SHRINK);
	box_direita->pack_start(*entry_idade, PACK_SHRINK);
	box_direita->pack_start(*combo_box_tipo_sanguineo, PACK_SHRINK);
	box_direita->pack_start(*combo_box_rh, PACK_SHRINK);
	box_direita->pack_start(*entry_especialidade, PACK_SHRINK);
	box_direita->pack_start(*entry_crmv, PACK_SHRINK);
	box_direita->pack_start(*combo_box_nivel_de_seguranca, PACK_SHRINK);

	SetInformacooes();

	// Conexões dos atributos da classe GTK.
	button_Editar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::Editar));
	combo_box_fucao->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarFuncionario::MudarFuncionario));
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
	delete combo_box_fucao;
	delete combo_box_tipo_sanguineo;
	delete combo_box_rh;
	delete combo_box_nivel_de_seguranca;
	delete button_Editar;
	delete box_principal;
	delete box_dados;
	delete box_esquerda;
	delete box_direita;
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
	string tipo_sanguineo;
	if (pagina == 0) // Se a pagina é igual a 0, o funcionário escolhido é um tratador.
	{
		map<int, Tratador>::iterator it_t = tratadores->find(id);
	
		entry_nome_do_funcionario->set_text((it_t->second).get_nome());

		entry_cpf->set_text((it_t->second).get_cpf());

		entry_idade->set_text(to_string((it_t->second).get_idade()));

		entry_especialidade->set_text((it_t->second).get_especialidade());

		combo_box_fucao->set_active(1);
		MudarFuncionario();


		tipo_sanguineo = (it_t->second).get_tipo_sanguineo();
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

		switch((it_t->second).get_rh())
		{
			case '+':
				combo_box_rh->set_active(0);
				break;
			case '-':
				combo_box_rh->set_active(1);
				break;
		}

		switch((it_t->second).get_nivel_de_seguranca())
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
		map<int, Veterinario>::iterator it_v = veterinarios->find(id);
			
		entry_nome_do_funcionario->set_text((it_v->second).get_nome());

		entry_cpf->set_text((it_v->second).get_cpf());

		entry_idade->set_text(to_string((it_v->second).get_idade()));

		entry_especialidade->set_text((it_v->second).get_especialidade());

		entry_crmv->set_text((it_v->second).get_crmv());

		combo_box_fucao->set_active(0);
		MudarFuncionario();

		tipo_sanguineo = (it_v->second).get_tipo_sanguineo();
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

		switch((it_v->second).get_rh())
		{
			case '+':
				combo_box_rh->set_active(0);
				break;
			case '-':
				combo_box_rh->set_active(1);
				break;
		}
	}
}

/**
* @brief Método que salva todas as informações escritas se elas forem válidas.
*/

void JanelaEditarFuncionario::Editar()
{
	map<int, Tratador>::iterator it_t = tratadores->find(id);
	map<int, Veterinario>::iterator it_v = veterinarios->find(id);

	// Verificação se todas as informações são validas, caso uma delas não seja
	// aparecerá uma tela com um aviso informando qual a informação que está incorreta.
	if(Responsabilidade(*anfibios_exoticos, *anfibios_nativos, *aves_exoticas,
					*aves_nativas, *mamiferos_exoticos, *mamiferos_nativos, 
					*repteis_exoticos, *repteis_nativos, id) && 
		it_t != tratadores->end() && combo_box_fucao->get_active_row_number() == 0)
	{
			MessageDialog dialog(*window, "Erro.");
			dialog.set_secondary_text("Impossivel mudar a função desse funcionário, pois ele é responsavel por animais.");
  			dialog.run();
	}
	else if(Responsabilidade(*anfibios_exoticos, *anfibios_nativos, *aves_exoticas,
					*aves_nativas, *mamiferos_exoticos, *mamiferos_nativos, 
					*repteis_exoticos, *repteis_nativos, id) && 
		it_v != veterinarios->end() && combo_box_fucao->get_active_row_number() == 1)
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
		RemoverFuncionario(*janela_principal, *veterinarios, *tratadores, id);
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
		// Dependendo da função do funcionário a operação é diferente.
		switch(combo_box_fucao->get_active_row_number())
		{
			case 0:
			{
				Veterinario veterinario(id, entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), entry_crmv->get_text());
				veterinarios->insert(pair<int, Veterinario>(id, veterinario));
				outfile << veterinario << endl;
				janela_principal->AtualizarLista(1);
				break;
			}
			case 1:
			{
				Tratador tratador(id, entry_nome_do_funcionario->get_text(), entry_cpf->get_text(), stoi(entry_idade->get_text()), tipo_sanguineo, rh, entry_especialidade->get_text(), combo_box_nivel_de_seguranca->get_active_row_number());
				tratadores->insert(pair<int, Tratador>(id, tratador));
				outfile << tratador << endl;
				janela_principal->AtualizarLista(0);
				break;
			}
		}
		window->close();
	}
}

/**
* @brief Método que decide os widgets que vão aparecer de acordo com a função do funcionário.
*/

void JanelaEditarFuncionario::MudarFuncionario()
{
	switch(combo_box_fucao->get_active_row_number())
	{
		case 0:
			{
			map<int, Tratador>::iterator it_t = tratadores->find(id);
			if (it_t != tratadores->end())
			{
				valid_crmv = false;
				entry_crmv->set_icon_from_pixbuf(pixbuf_uncheck);
			}

			combo_box_nivel_de_seguranca->hide();
			label_nivel_de_seguranca->hide();
			entry_crmv->show();
			label_crmv->show();
			break;
			}
		case 1:
			{
				valid_crmv = true;
				combo_box_nivel_de_seguranca->show();
				label_nivel_de_seguranca->show();
				entry_crmv->hide();
				label_crmv->hide();
				break;
			}
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
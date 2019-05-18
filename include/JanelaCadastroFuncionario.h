#ifndef _JANELA_CADASTRO_FUNCIONARIO_H_
#define _JANELA_CADASTRO_FUNCIONARIO_H_

#include <iostream>
#include <gtkmm.h>

using namespace Gtk;
using namespace std;

class JanelaCadastroFuncionario
{
	private:
		Window *window;

		VBox *box_principal;

		Entry *entry_id;
		ComboBox *combo_box_fucao;
		Entry *entry_nome_do_funcionario;
		Entry *entry_cpf;
		Entry *entry_idade;
		ComboBox *combo_box_tipo_sanguineo;
		ComboBox *combo_box_rh;
		Entry *entry_especialidade;
		Entry *entry_crmv;
		ComboBox *combo_box_nivel_de_segurança;

		Button *button_cadastrar;
	public:
		JanelaCadastroFuncionario();
		~JanelaCadastroFuncionario();

		void Run();
};

#endif

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
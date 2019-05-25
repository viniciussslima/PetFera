#ifndef _JANELA_CADASTRO_FUNCIONARIO_H_
#define _JANELA_CADASTRO_FUNCIONARIO_H_

#include <iostream>
#include <gtkmm.h>
#include <map>
#include "Veterinario.h"
#include "Tratador.h"

using namespace Gtk;
using namespace std;

class JanelaCadastroFuncionario
{
	private:
		Window *window;

		VBox *box_principal;
		HBox *box_dados;
		VBox *box_esquerda;
		VBox *box_direita;

		Entry *entry_id;
		ComboBoxText *combo_box_fucao;
		Entry *entry_nome_do_funcionario;
		Entry *entry_cpf;
		Entry *entry_idade;
		ComboBoxText *combo_box_tipo_sanguineo;
		ComboBoxText *combo_box_rh;
		Entry *entry_especialidade;
		Entry *entry_crmv;
		ComboBoxText *combo_box_nivel_de_seguranca;
		Button *button_cadastrar;

		Label *label_id;
		Label *label_funcao;
		Label *label_nome_do_funcionario;
		Label *label_cpf;
		Label *label_idade;
		Label *label_tipo_sanguineo;
		Label *label_rh;
		Label *label_especialidade;
		Label *label_crmv;
		Label *label_nivel_de_seguranca;

		map<int, Veterinario> *veterinarios;
		map<int, Tratador> *tratadores;
	public:
		JanelaCadastroFuncionario(map<int, Veterinario>&, map<int, Tratador>&);
		~JanelaCadastroFuncionario();

		void Run();
		void Cadastrar();
		void MudarFuncionario();
};

#endif
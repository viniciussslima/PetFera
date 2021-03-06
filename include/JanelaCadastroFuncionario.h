/**
* @file JanelaCadastroFuncionario.h
* @brief Classe que abre uma juanela que possibibilita cadastrar um funcionário.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _JANELA_CADASTRO_FUNCIONARIO_H_
#define _JANELA_CADASTRO_FUNCIONARIO_H_

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <gtkmm.h>

#include "Funcionario.h"
#include "Veterinario.h"
#include "Tratador.h"
#include "JanelaPrincipal.h"

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
		HBox *box_funcao;
		HBox *box_rh;

		Entry *entry_id;
		RadioButton *radio_button_veterinario;
		RadioButton *radio_button_tratador;
		Entry *entry_nome_do_funcionario;
		Entry *entry_cpf;
		Entry *entry_idade;
		ComboBoxText *combo_box_tipo_sanguineo;
		RadioButton *radio_button_rh_positivo;
		RadioButton *radio_button_rh_negativo;
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

		Glib::RefPtr<Gdk::Pixbuf> pixbuf_check;
		Glib::RefPtr<Gdk::Pixbuf> pixbuf_uncheck;

		JanelaPrincipal *janela_principal;

		bool valid_id;
		bool valid_nome_do_funcionario;
		bool valid_cpf;
		bool valid_idade;
		bool valid_especialidade;
		bool valid_crmv;

		map<int, Funcionario*> *funcionarios;

	public:
		JanelaCadastroFuncionario();
		JanelaCadastroFuncionario(JanelaPrincipal&, map<int, Funcionario*>&);
		~JanelaCadastroFuncionario();

		void Run();
		void Cadastrar();
		void MudarFuncionario();
		void AtualizarIconeId();
		void AtualizarIconeNomeDoFuncionario();
		void AtualizarIconeCPF();
		void AtualizarIconeIdade();
		void AtualizarIconeEspecialidade();
		void AtualizarIconeCRMV();
};

#endif
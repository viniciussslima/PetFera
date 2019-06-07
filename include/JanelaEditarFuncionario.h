#ifndef _JANELA_EDITAR_FUNCIONARIO_H_
#define _JANELA_EDITAR_FUNCIONARIO_H_

#include <iostream>
#include <gtkmm.h>
#include <map>
#include <string>
#include "Funcionario.h"
#include "Veterinario.h"
#include "Tratador.h"
#include "JanelaPrincipal.h"
#include "Separador.h"

using namespace Gtk;
using namespace std;

class JanelaEditarFuncionario
{
	private:
		Window *window;

		VBox *box_principal;
		HBox *box_dados;
		VBox *box_esquerda;
		VBox *box_direita;

		ComboBoxText *combo_box_fucao;
		Entry *entry_nome_do_funcionario;
		Entry *entry_cpf;
		Entry *entry_idade;
		ComboBoxText *combo_box_tipo_sanguineo;
		ComboBoxText *combo_box_rh;
		Entry *entry_especialidade;
		Entry *entry_crmv;
		ComboBoxText *combo_box_nivel_de_seguranca;
		Button *button_Editar;

		Label *label_id;
		Label *label_id_numero;
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
		int pagina;
		int id;

		map<int, Veterinario> *veterinarios;
		map<int, Tratador> *tratadores;

		map<int, AnfibioExotico> *anfibios_exoticos;
		map<int, AnfibioNativo> *anfibios_nativos;

		map<int, AveExotico> *aves_exoticas;
		map<int, AveNativo> *aves_nativas;

		map<int, MamiferoExotico> *mamiferos_exoticos;
		map<int, MamiferoNativo> *mamiferos_nativos;

		map<int, ReptilExotico> *repteis_exoticos;
		map<int, ReptilNativo> *repteis_nativos;
		
	public:
		JanelaEditarFuncionario(JanelaPrincipal&, map<int, Veterinario>&, map<int, Tratador>&, 
			map<int, AnfibioExotico>&, map<int, AnfibioNativo>&, map<int, AveExotico>&,
			map<int, AveNativo>&, map<int, MamiferoExotico>&, map<int, MamiferoNativo>&,
			map<int, ReptilExotico>&, map<int, ReptilNativo>&, int, int);
		~JanelaEditarFuncionario();

		void Run();
		void SetInformacooes();
		void Editar();
		void Remover();
		void MudarFuncionario();
		bool Responsabilidade();
		void AtualizarIconeNomeDoFuncionario();
		void AtualizarIconeCPF();
		void AtualizarIconeIdade();
		void AtualizarIconeEspecialidade();
		void AtualizarIconeCRMV();
};

#endif
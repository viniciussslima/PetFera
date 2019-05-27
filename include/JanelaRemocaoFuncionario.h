#ifndef _JANELA_REMOCAO_FUNCIONARIO_H_
#define _JANELA_REMOCAO_FUNCIONARIO_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include <map>

#include "Veterinario.h"
#include "Tratador.h"

#include "Separador.h"
#include "JanelaPrincipal.h"

using namespace Gtk;
using namespace std;

class JanelaRemocaoFuncionario
{
	private:
		Window *window;

		VBox *box_principal;
		HBox *box_dados;

		Entry *entry_id;
		Button *button_confirmar;

		Label *label_id;

		JanelaPrincipal *janela_principal;

		Glib::RefPtr<Gdk::Pixbuf> pixbuf_check;
		Glib::RefPtr<Gdk::Pixbuf> pixbuf_uncheck;

		bool valid_id;

		map<int, Veterinario> *veterinarios;
		map<int, Tratador> *tratadores;
	public:
		JanelaRemocaoFuncionario(JanelaPrincipal&, map<int, Veterinario>&, map<int, Tratador>&);
		~JanelaRemocaoFuncionario();

		void Run();
		void Remover();
		void AtualizarIconeId();
};

#endif
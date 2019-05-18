#ifndef _JANELA_PRINCIPAL_H_
#define _JANELA_PRINCIPAL_H_

#include <iostream>
#include <gtkmm.h>

using namespace Gtk;
using namespace std;

class JanelaPrincipal
{
	private:
		Window *window;

		VBox *box_principal;
		HBox *box_botoes;

		Button *button_cadastro_animal;
		Button *button_remocao_animal;
		Button *button_cadastro_funcionario;
		Button *button_remocao_funcionario;
		Button *button_consulta_animal;
		Button *button_consulta_funcionario;
	public:
		JanelaPrincipal();
		~JanelaPrincipal();

		void Run();
		void CadastrarFuncionario();
};

#endif
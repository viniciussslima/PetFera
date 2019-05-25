#ifndef _JANELA_PRINCIPAL_H_
#define _JANELA_PRINCIPAL_H_

#include <iostream>
#include <gtkmm.h>

#include "Separador.h"
#include "date.h"

#include "Veterinario.h"
#include "Tratador.h"

#include "AnfibioExotico.h"
#include "AnfibioNativo.h"

#include "AveExotico.h"
#include "AveNativo.h"

#include "MamiferoExotico.h"
#include "MamiferoNativo.h"

#include "ReptilExotico.h"
#include "ReptilNativo.h"

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
		map<int, Veterinario> veterinarios;
		map<int, Tratador> tratadores;

		map<int, AnfibioExotico> anfibios_exoticos;
		map<int, AnfibioNativo> anfibios_nativos;

		map<int, AveExotico> aves_exoticas;
		map<int, AveNativo> aves_nativas;

		map<int, MamiferoExotico> mamiferos_exoticos;
		map<int, MamiferoNativo> mamiferos_nativos;

		map<int, ReptilExotico> repteis_exoticos;
		map<int, ReptilNativo> repteis_nativos;
		
		JanelaPrincipal();
		~JanelaPrincipal();

		void Run();
		void CadastrarFuncionario();
		void CadastrarAnimal();
		void RemoverFuncionario();
		void RemoverAnimal();
};

#endif
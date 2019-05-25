#ifndef _JANELA_CADASTRO_ANIMAL_H_
#define _JANELA_CADASTRO_ANIMAL_H_

#include <iostream>
#include <gtkmm.h>
#include "Separador.h"

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

class JanelaCadastroAnimal
{
	private:
		Window *window;

		VBox *box_principal;
		HBox *box_dados;
		VBox *box_esquerda;
		VBox *box_direita;

		Entry *entry_id;
		ComboBoxText *combo_box_classe;
		Entry *entry_nome_cientifico;
		ComboBoxText *combo_box_sexo; //
		Entry *entry_tamanho;
		Entry *entry_dieta;
		CheckButton *check_button_veterinario_incluso;
		Entry *entry_veterinario_id;
		CheckButton *check_button_tratador_incluso;
		Entry *entry_tratador_id;
		Entry *entry_nome_batismo;
		Entry *entry_autorizacao_ibama;
		ComboBoxText *combo_box_regiao;
		Entry *entry_nacionalidade;
		Entry *entry_uf;
		Button *button_cadastrar;

		Entry *entry_total_de_mudas;
		Entry *entry_data_da_ultima_muda;
		Entry *entry_tamanho_do_bico;
		Entry *entry_envergadura_das_asas;
		Entry *entry_cor_dos_pelos;
		CheckButton *check_button_venenoso;
		Entry *entry_tipo_de_veneno;

		Label *label_id;
		Label *label_classe;
		Label *label_nome_cientifico;
		Label *label_sexo;
		Label *label_tamanho;
		Label *label_dieta;
		Label *label_veterinario_incluso;
		Label *label_veterinario_id;
		Label *label_tratador_incluso;
		Label *label_tratador_id;
		Label *label_nome_batismo;
		Label *label_total_de_mudas;
		Label *label_data_da_ultima_muda;
		Label *label_tamanho_do_bico;
		Label *label_envergadura_das_asas;
		Label *label_cor_dos_pelos;
		Label *label_venenoso;
		Label *label_tipo_de_veneno;
		Label *label_autorizacao_do_ibama;
		Label *label_regiao;
		Label *label_nacionalidade;
		Label *label_uf;

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
		JanelaCadastroAnimal(map<int, Veterinario>&, map<int, Tratador>&, map<int, AnfibioExotico>&, 
							 map<int, AnfibioNativo>&, map<int, AveExotico>&, map<int, AveNativo>&,
							 map<int, MamiferoExotico>&, map<int, MamiferoNativo>&, 
							 map<int, ReptilExotico>&, map<int, ReptilNativo>&);
		~JanelaCadastroAnimal();

		void Run();
		void Cadastrar();
		void MudarClasse();
		void MudarRegiao();
		void MostrarVeterinario();
		void MostrarTratador();
		void MostrarVenenoso();
};

/*
int id;
	bool teste_id;
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	char veterinario_incluso;
	char tratador_incluso;
	string nome_batismo;
	string nacionalidade;
*/

#endif
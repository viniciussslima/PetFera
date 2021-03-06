/**
* @file JanelaCadastroAnimal.h
* @brief Classe que abre uma juanela que possibibilita cadastrar um animal.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _JANELA_CADASTRO_ANIMAL_H_
#define _JANELA_CADASTRO_ANIMAL_H_

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

#include <gtkmm.h>

#include "JanelaPrincipal.h"
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
		HBox *box_sexo;
		HBox *box_regiao;

		Entry *entry_id;
		ComboBoxText *combo_box_classe;
		Entry *entry_nome_cientifico;
		RadioButton *radio_button_sexo_m;
		RadioButton *radio_button_sexo_f;
		Entry *entry_tamanho;
		Entry *entry_dieta;
		CheckButton *check_button_veterinario_incluso;
		ComboBoxText *combo_box_veterinario_id;
		CheckButton *check_button_tratador_incluso;
		ComboBoxText *combo_box_tratador_id;
		Entry *entry_nome_batismo;
		Entry *entry_autorizacao_ibama;
		RadioButton *radio_button_regiao_nativo;
		RadioButton *radio_button_regiao_exotico;
		Entry *entry_nacionalidade;
		ComboBoxText *combo_box_uf;
		Entry *entry_cidade;
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
		Label *label_cidade;

		Glib::RefPtr<Gdk::Pixbuf> pixbuf_check;
		Glib::RefPtr<Gdk::Pixbuf> pixbuf_uncheck;

		JanelaPrincipal *janela_principal;

		bool valid_id;
		bool valid_nome_cientifico;
		bool valid_tamanho;
		bool valid_dieta;
		bool valid_nome_batismo;
		bool valid_autorizacao_ibama;
		bool valid_nacionalidade;
		bool valid_cidade;
		bool valid_total_de_mudas;
		bool valid_data_da_ultima_muda;
		bool valid_tamanho_do_bico;
		bool valid_envergadura_das_asas;
		bool valid_cor_dos_pelos;
		bool valid_tipo_veneno;

		map<int, Funcionario*> *funcionarios;
		map<int, Animal*> *animais;

	public:
		JanelaCadastroAnimal(JanelaPrincipal&, map<int, Funcionario*>&, map<int, Animal*>&);
		~JanelaCadastroAnimal();

		void Run();
		void Cadastrar();
		void MudarClasse();
		void MudarRegiao();
		void MostrarVeterinario();
		void MostrarTratador();
		void MostrarVenenoso();
		void AtualizarIconeId();
		void AtualizarIconeNomeCientifico();
		void AtualizarIconeTamanho();
		void AtualizarIconeDieta();
		void AtualizarIconeNomeBatismo();
		void AtualizarIconeAutorizacaoIbama();
		void AtualizarIconeNacionalidade();
		void AtualizarIconeTotalDeMudas();
		void AtualizarIconeDataDaUltimaMuda();
		void AtualizarIconeTamanhoDoBico();
		void AtualizarIconeEnvergaduraDasAsas();
		void AtualizarIconeCorDosPelos();
		void AtualizarIconeTipoDeVeneno();
		void AtualizarIconeCidade();
};

#endif
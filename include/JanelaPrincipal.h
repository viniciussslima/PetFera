/**
* @file JanelaPrincipal.h
* @brief Classe que abre uma janela que possibilita vizualizar todos os animais e funcionários cadastrados.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _JANELA_PRINCIPAL_H_
#define _JANELA_PRINCIPAL_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>

#include "Separador.h"
#include "date.h"

#include "Funcionario.h"
#include "Veterinario.h"
#include "Tratador.h"

#include "Animal.h"
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

class ModelColumnsTratador : public Gtk::TreeModel::ColumnRecord
{
	public:
  		ModelColumnsTratador()
    	{ 
    		add(col_id); 
    		add(col_nome); 
    		add(col_cpf); 
    		add(col_idade);
    		add(col_tipo_sanguineo);
    		add(col_rh);
    		add(col_especialidade);
    		add(col_nivel_seguranca);
    	}

    	TreeModelColumn<int> col_id;
    	TreeModelColumn<string> col_nome;
    	TreeModelColumn<string> col_cpf;
    	TreeModelColumn<int> col_idade;
    	TreeModelColumn<string> col_tipo_sanguineo;
    	TreeModelColumn<string> col_rh;
    	TreeModelColumn<string> col_especialidade;
    	TreeModelColumn<int> col_nivel_seguranca;
};

class ModelColumnsVeterinario : public Gtk::TreeModel::ColumnRecord
{
	public:
		ModelColumnsVeterinario()
		{ 
		add(col_id); 
		add(col_nome); 
		add(col_cpf); 
		add(col_idade);
		add(col_tipo_sanguineo);
		add(col_rh);
		add(col_especialidade);
		add(col_crmv);
		}

	TreeModelColumn<int> col_id;
	TreeModelColumn<string> col_nome;
	TreeModelColumn<string> col_cpf;
	TreeModelColumn<int> col_idade;
	TreeModelColumn<string> col_tipo_sanguineo;
	TreeModelColumn<string> col_rh;
	TreeModelColumn<string> col_especialidade;
	TreeModelColumn<string> col_crmv;
};

class ModelColumnsAnfibioNativo : public Gtk::TreeModel::ColumnRecord
{
	public:
		ModelColumnsAnfibioNativo()
		{ 
		add(col_id); 
		add(col_nome_cientifico); 
		add(col_sexo); 
		add(col_tamanho);
		add(col_dieta);
		add(col_veterinario);
		add(col_tratador);
		add(col_nome_batismo);
		add(col_total_mudas);
		add(col_data_ultima_muda);
		add(col_autorizacao_ibama);
		add(col_uf_origem);
		}

	TreeModelColumn<int> col_id;
	TreeModelColumn<string> col_nome_cientifico;
	TreeModelColumn<string> col_sexo;
	TreeModelColumn<double> col_tamanho;
	TreeModelColumn<string> col_dieta;
	TreeModelColumn<string> col_veterinario;
	TreeModelColumn<string> col_tratador;
	TreeModelColumn<string> col_nome_batismo;
	TreeModelColumn<int> col_total_mudas;
	TreeModelColumn<string> col_data_ultima_muda;
	TreeModelColumn<string> col_autorizacao_ibama;
	TreeModelColumn<string> col_uf_origem;
};

class ModelColumnsAnfibioExotico : public Gtk::TreeModel::ColumnRecord
{
	public:
			ModelColumnsAnfibioExotico()
			{ 
			add(col_id); 
			add(col_nome_cientifico); 
			add(col_sexo); 
			add(col_tamanho);
			add(col_dieta);
			add(col_veterinario);
			add(col_tratador);
			add(col_nome_batismo);
			add(col_total_mudas);
			add(col_data_ultima_muda);
			add(col_autorizacao_ibama);
			add(col_pais_origem);
			add(col_cidade_origem);
			}

		TreeModelColumn<int> col_id;
		TreeModelColumn<string> col_nome_cientifico;
		TreeModelColumn<string> col_sexo;
		TreeModelColumn<double> col_tamanho;
		TreeModelColumn<string> col_dieta;
		TreeModelColumn<string> col_veterinario;
		TreeModelColumn<string> col_tratador;
		TreeModelColumn<string> col_nome_batismo;
		TreeModelColumn<int> col_total_mudas;
		TreeModelColumn<string> col_data_ultima_muda;
		TreeModelColumn<string> col_autorizacao_ibama;
		TreeModelColumn<string> col_pais_origem;
		TreeModelColumn<string> col_cidade_origem;
};

class ModelColumnsAveNativa : public Gtk::TreeModel::ColumnRecord
{
	public:
			ModelColumnsAveNativa()
			{ 
			add(col_id); 
			add(col_nome_cientifico); 
			add(col_sexo); 
			add(col_tamanho);
			add(col_dieta);
			add(col_veterinario);
			add(col_tratador);
			add(col_nome_batismo);
			add(col_tamanho_bico);
			add(col_envergadura_asas);
			add(col_autorizacao_ibama);
			add(col_uf_origem);
			}

		TreeModelColumn<int> col_id;
		TreeModelColumn<string> col_nome_cientifico;
		TreeModelColumn<string> col_sexo;
		TreeModelColumn<double> col_tamanho;
		TreeModelColumn<string> col_dieta;
		TreeModelColumn<string> col_veterinario;
		TreeModelColumn<string> col_tratador;
		TreeModelColumn<string> col_nome_batismo;
		TreeModelColumn<double> col_tamanho_bico;
		TreeModelColumn<double> col_envergadura_asas;
		TreeModelColumn<string> col_autorizacao_ibama;
		TreeModelColumn<string> col_uf_origem;
};

class ModelColumnsAveExotica : public Gtk::TreeModel::ColumnRecord
{
	public:
		ModelColumnsAveExotica()
		{ 
			add(col_id); 
			add(col_nome_cientifico); 
			add(col_sexo); 
			add(col_tamanho);
			add(col_dieta);
			add(col_veterinario);
			add(col_tratador);
			add(col_nome_batismo);
			add(col_tamanho_bico);
			add(col_envergadura_asas);
			add(col_autorizacao_ibama);
			add(col_pais_origem);
			add(col_cidade_origem);
		}

		TreeModelColumn<int> col_id;
		TreeModelColumn<string> col_nome_cientifico;
		TreeModelColumn<string> col_sexo;
		TreeModelColumn<double> col_tamanho;
		TreeModelColumn<string> col_dieta;
		TreeModelColumn<string> col_veterinario;
		TreeModelColumn<string> col_tratador;
		TreeModelColumn<string> col_nome_batismo;
		TreeModelColumn<double> col_tamanho_bico;
		TreeModelColumn<double> col_envergadura_asas;
		TreeModelColumn<string> col_autorizacao_ibama;
		TreeModelColumn<string> col_pais_origem;
		TreeModelColumn<string> col_cidade_origem;

};

class ModelColumnsMamiferoNativo : public Gtk::TreeModel::ColumnRecord
{
	public:
  		ModelColumnsMamiferoNativo()
    	{ 
    		add(col_id); 
    		add(col_nome_cientifico); 
    		add(col_sexo); 
    		add(col_tamanho);
    		add(col_dieta);
    		add(col_veterinario);
    		add(col_tratador);
    		add(col_nome_batismo);
    		add(col_cor_pelo);
    		add(col_autorizacao_ibama);
    		add(col_uf_origem);
    	}

    	TreeModelColumn<int> col_id;
    	TreeModelColumn<string> col_nome_cientifico;
    	TreeModelColumn<string> col_sexo;
    	TreeModelColumn<double> col_tamanho;
    	TreeModelColumn<string> col_dieta;
    	TreeModelColumn<string> col_veterinario;
    	TreeModelColumn<string> col_tratador;
    	TreeModelColumn<string> col_nome_batismo;
    	TreeModelColumn<string> col_cor_pelo;
    	TreeModelColumn<string> col_autorizacao_ibama;
    	TreeModelColumn<string> col_uf_origem;
};

class ModelColumnsMamiferoExotico : public Gtk::TreeModel::ColumnRecord
{
	public:
  		ModelColumnsMamiferoExotico()
    	{ 
    		add(col_id); 
    		add(col_nome_cientifico); 
    		add(col_sexo); 
    		add(col_tamanho);
    		add(col_dieta);
    		add(col_veterinario);
    		add(col_tratador);
    		add(col_nome_batismo);
    		add(col_cor_pelo);
    		add(col_autorizacao_ibama);
    		add(col_pais_origem);
    		add(col_cidade_origem);
    	}

    	TreeModelColumn<int> col_id;
    	TreeModelColumn<string> col_nome_cientifico;
    	TreeModelColumn<string> col_sexo;
    	TreeModelColumn<double> col_tamanho;
    	TreeModelColumn<string> col_dieta;
    	TreeModelColumn<string> col_veterinario;
    	TreeModelColumn<string> col_tratador;
    	TreeModelColumn<string> col_nome_batismo;
    	TreeModelColumn<string> col_cor_pelo;
    	TreeModelColumn<string> col_autorizacao_ibama;
    	TreeModelColumn<string> col_pais_origem;
    	TreeModelColumn<string> col_cidade_origem;
};

class ModelColumnsReptilNativo : public Gtk::TreeModel::ColumnRecord
{
	public:
  		ModelColumnsReptilNativo()
    	{ 
    		add(col_id); 
    		add(col_nome_cientifico); 
    		add(col_sexo); 
    		add(col_tamanho);
    		add(col_dieta);
    		add(col_veterinario);
    		add(col_tratador);
    		add(col_nome_batismo);
    		add(col_veneno);
    		add(col_autorizacao_ibama);
    		add(col_uf_origem);
    	}

    	TreeModelColumn<int> col_id;
    	TreeModelColumn<string> col_nome_cientifico;
    	TreeModelColumn<string> col_sexo;
    	TreeModelColumn<double> col_tamanho;
    	TreeModelColumn<string> col_dieta;
    	TreeModelColumn<string> col_veterinario;
    	TreeModelColumn<string> col_tratador;
    	TreeModelColumn<string> col_nome_batismo;
    	TreeModelColumn<string> col_veneno;
    	TreeModelColumn<string> col_autorizacao_ibama;
    	TreeModelColumn<string> col_uf_origem;
};

class ModelColumnsReptilExotico : public Gtk::TreeModel::ColumnRecord
{
	public:
  		ModelColumnsReptilExotico()
    	{ 
    		add(col_id); 
    		add(col_nome_cientifico); 
    		add(col_sexo); 
    		add(col_tamanho);
    		add(col_dieta);
    		add(col_veterinario);
    		add(col_tratador);
    		add(col_nome_batismo);
    		add(col_veneno);
    		add(col_autorizacao_ibama);
    		add(col_pais_origem);
    		add(col_cidade_origem);
    	}

    	TreeModelColumn<int> col_id;
    	TreeModelColumn<string> col_nome_cientifico;
    	TreeModelColumn<string> col_sexo;
    	TreeModelColumn<double> col_tamanho;
    	TreeModelColumn<string> col_dieta;
    	TreeModelColumn<string> col_veterinario;
    	TreeModelColumn<string> col_tratador;
    	TreeModelColumn<string> col_nome_batismo;
    	TreeModelColumn<string> col_veneno;
    	TreeModelColumn<string> col_autorizacao_ibama;
    	TreeModelColumn<string> col_pais_origem;
    	TreeModelColumn<string> col_cidade_origem;
};

class JanelaPrincipal : public ModelColumnsTratador, public ModelColumnsVeterinario,
	public ModelColumnsAnfibioNativo, public ModelColumnsAnfibioExotico,
	public ModelColumnsAveNativa, public ModelColumnsAveExotica,
	public ModelColumnsMamiferoNativo, public ModelColumnsMamiferoExotico,
	public ModelColumnsReptilNativo, public ModelColumnsReptilExotico
{
	private:
		VBox *box_principal;
		HButtonBox *box_botoes;

		Notebook *notebook_consulta;

		Image *IconeButao;

		Button *button_cadastro_animal;
		Button *button_remocao_animal;
		Button *button_cadastro_funcionario;
		Button *button_remover;
		Button *button_editar;
		Button *button_buscar_animal_por_funcionario;
		Button *button_about;

		Glib::RefPtr<Gdk::Pixbuf> pixbuf_icone;

		SearchEntry *entry_pesquisa;

		TreeView *tree_view_tratadores;
		TreeView *tree_view_veterinarios;
		TreeView *tree_view_anfibios_nativos;
		TreeView *tree_view_anfibios_exoticos;
		TreeView *tree_view_aves_nativas;
		TreeView *tree_view_aves_exoticas;
		TreeView *tree_view_mamiferos_nativos;
		TreeView *tree_view_mamiferos_exoticos;
		TreeView *tree_view_repteis_nativos;
		TreeView *tree_view_repteis_exoticos;

		ScrolledWindow *scrolled_window_tratadores;
		ScrolledWindow *scrolled_window_veterinarios;
		ScrolledWindow *scrolled_window_anfibios_nativos;
		ScrolledWindow *scrolled_window_anfibios_exoticos;
		ScrolledWindow *scrolled_window_aves_nativas;
		ScrolledWindow *scrolled_window_aves_exoticas;
		ScrolledWindow *scrolled_window_mamiferos_nativos;
		ScrolledWindow *scrolled_window_mamiferos_exoticos;
		ScrolledWindow *scrolled_window_repteis_nativos;
		ScrolledWindow *scrolled_window_repteis_exoticos;

	  	ModelColumnsTratador model_columns_tratador;
	  	ModelColumnsVeterinario model_columns_veterinario;
	  	ModelColumnsAnfibioNativo model_columns_anfibio_nativo;
	  	ModelColumnsAnfibioExotico model_columns_anfibio_exotico;
	  	ModelColumnsAveNativa model_columns_ave_nativa;
	  	ModelColumnsAveExotica model_columns_ave_exotica;
	  	ModelColumnsMamiferoNativo model_columns_mamifero_nativo;
	  	ModelColumnsMamiferoExotico model_columns_mamifero_exotico;
	  	ModelColumnsReptilNativo model_columns_reptil_nativo;
	  	ModelColumnsReptilExotico model_columns_reptil_exotico;

	  	Glib::RefPtr<ListStore> list_store_tratadores;
	  	Glib::RefPtr<ListStore> list_store_veterinarios;
	  	Glib::RefPtr<ListStore> list_store_anfibios_nativos;
	  	Glib::RefPtr<ListStore> list_store_anfibios_exoticos;
	  	Glib::RefPtr<ListStore> list_store_aves_nativas;
	  	Glib::RefPtr<ListStore> list_store_aves_exoticas;
	  	Glib::RefPtr<ListStore> list_store_mamiferos_nativos;
	  	Glib::RefPtr<ListStore> list_store_mamiferos_exoticos;
	  	Glib::RefPtr<ListStore> list_store_repteis_nativos;
	  	Glib::RefPtr<ListStore> list_store_repteis_exoticos;
	public:
		Window *window;
		
		map<int, Funcionario*> funcionarios;

		map<int, Animal*> animais;
		
		JanelaPrincipal();
		~JanelaPrincipal();

		void Run();
		void BotaoCadastrarFuncionario();
		void BotaoCadastrarAnimal();
		void BotaoRemover();
		void BotaoEditar();
		void BotaoBuscarAnimalPorFuncionario();
		void BotaoAbout();
		void AtualizarLista(int);
};

#endif
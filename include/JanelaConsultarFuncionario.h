#ifndef _JANELA_CONSULTAR_FUNCIONARIO_H_
#define _JANELA_CONSULTAR_FUNCIONARIO_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include <map>
#include "Veterinario.h"
#include "Tratador.h"
#include "Separador.h"

using namespace Gtk;
using namespace std;

class JanelaConsultarFuncionario
{
	private:
		Window *window;

		HBox *box_principal;
		TreeView *tree_view_tratadores;
		TreeView *tree_view_veterinarios;
		ScrolledWindow *scrolled_window_tratadores;
		ScrolledWindow *scrolled_window_veterinarios;

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
		    	TreeModelColumn<char> col_rh;
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
		    	TreeModelColumn<char> col_rh;
		    	TreeModelColumn<string> col_especialidade;
		    	TreeModelColumn<string> col_crmv;
	  	};

	  	ModelColumnsTratador model_columns_tratador;
	  	ModelColumnsVeterinario model_columns_veterinario;
	  	Glib::RefPtr<Gtk::ListStore> list_store_tratadores;
	  	Glib::RefPtr<Gtk::ListStore> list_store_veterinario;

		map<int, Veterinario> *veterinarios;
		map<int, Tratador> *tratadores;
	public:
		JanelaConsultarFuncionario(map<int, Veterinario>&, map<int, Tratador>&);
		~JanelaConsultarFuncionario();

		void Run();
};

#endif
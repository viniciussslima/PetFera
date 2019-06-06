#ifndef ANIMAL_FUNCIONARIO_H_
#define ANIMAL_FUNCIONARIO_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include <map>

#include "JanelaPrincipal.h"

#include "AnfibioExotico.h"
#include "AnfibioNativo.h"

#include "AveExotico.h"
#include "AveNativo.h"

#include "MamiferoExotico.h"
#include "MamiferoNativo.h"

#include "ReptilExotico.h"
#include "ReptilNativo.h"

#include "Separador.h"

using namespace Gtk;
using namespace std;

class JanelaBuscaAnimais : public ModelColumnsTratador, public ModelColumnsVeterinario,
	public ModelColumnsAnfibioNativo, public ModelColumnsAnfibioExotico,
	public ModelColumnsAveNativa, public ModelColumnsAveExotica,
	public ModelColumnsMamiferoNativo, public ModelColumnsMamiferoExotico,
	public ModelColumnsReptilNativo, public ModelColumnsReptilExotico
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

		Notebook *notebook_consulta;

		SearchEntry *entry_pesquisa;

		TreeView *tree_view_anfibios_nativos;
		TreeView *tree_view_anfibios_exoticos;
		TreeView *tree_view_aves_nativas;
		TreeView *tree_view_aves_exoticas;
		TreeView *tree_view_mamiferos_nativos;
		TreeView *tree_view_mamiferos_exoticos;
		TreeView *tree_view_repteis_nativos;
		TreeView *tree_view_repteis_exoticos;

		ScrolledWindow *scrolled_window_anfibios_nativos;
		ScrolledWindow *scrolled_window_anfibios_exoticos;
		ScrolledWindow *scrolled_window_aves_nativas;
		ScrolledWindow *scrolled_window_aves_exoticas;
		ScrolledWindow *scrolled_window_mamiferos_nativos;
		ScrolledWindow *scrolled_window_mamiferos_exoticos;
		ScrolledWindow *scrolled_window_repteis_nativos;
		ScrolledWindow *scrolled_window_repteis_exoticos;

	  	ModelColumnsAnfibioNativo model_columns_anfibio_nativo;
	  	ModelColumnsAnfibioExotico model_columns_anfibio_exotico;
	  	ModelColumnsAveNativa model_columns_ave_nativa;
	  	ModelColumnsAveExotica model_columns_ave_exotica;
	  	ModelColumnsMamiferoNativo model_columns_mamifero_nativo;
	  	ModelColumnsMamiferoExotico model_columns_mamifero_exotico;
	  	ModelColumnsReptilNativo model_columns_reptil_nativo;
	  	ModelColumnsReptilExotico model_columns_reptil_exotico;

	  	Glib::RefPtr<ListStore> list_store_anfibios_nativos;
	  	Glib::RefPtr<ListStore> list_store_anfibios_exoticos;
	  	Glib::RefPtr<ListStore> list_store_aves_nativas;
	  	Glib::RefPtr<ListStore> list_store_aves_exoticas;
	  	Glib::RefPtr<ListStore> list_store_mamiferos_nativos;
	  	Glib::RefPtr<ListStore> list_store_mamiferos_exoticos;
	  	Glib::RefPtr<ListStore> list_store_repteis_nativos;
	  	Glib::RefPtr<ListStore> list_store_repteis_exoticos;

		bool valid_id;

		map<int, AnfibioExotico> *anfibios_exoticos;
		map<int, AnfibioNativo> *anfibios_nativos;

		map<int, AveExotico> *aves_exoticas;
		map<int, AveNativo> *aves_nativas;

		map<int, MamiferoExotico> *mamiferos_exoticos;
		map<int, MamiferoNativo> *mamiferos_nativos;

		map<int, ReptilExotico> *repteis_exoticos;
		map<int, ReptilNativo> *repteis_nativos;
	public:
		JanelaBuscaAnimais(map<int, AnfibioExotico>&, map<int, AnfibioNativo>&, map<int, AveExotico>&, 
							map<int, AveNativo>&, map<int, MamiferoExotico>&, map<int, MamiferoNativo>&, 
							map<int, ReptilExotico>&, map<int, ReptilNativo>&, int id = 0);
		~JanelaBuscaAnimais();

		void ProcurarAnimalPorFuncionario();
		void Run();
};

#endif
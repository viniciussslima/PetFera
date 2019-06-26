/**
* @file JanelaBuscaAnimais.h
* @brief Classe que representa uma janela com os animais sob a responsabilidade de um funcionário.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _JANELA_BUSCA_ANIMAIS_H_
#define _JANELA_BUSCA_ANIMAIS_H_

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <gtkmm.h>

#include "PetFera.so"
#include "JanelaPrincipal.h"
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

		bool page_anfibios_exoticos = false;
		bool page_anfibios_nativos = false;
		bool page_aves_exoticas = false;
		bool page_aves_nativas = false;
		bool page_mamiferos_exoticos = false;
		bool page_mamiferos_nativos = false;
		bool page_repteis_exoticos = false;
		bool page_repteis_nativos = false;
		int pagina;
		int id;

		map<int, Funcionario*> *funcionarios;
		map<int, Animal*> *animais;

	public:
		JanelaBuscaAnimais();
		JanelaBuscaAnimais(JanelaPrincipal&, map<int, Funcionario*>&, map<int, Animal*>&, int, int);
		~JanelaBuscaAnimais();

		void ProcurarAnimalPorFuncionario();
		void Run();
};

#endif
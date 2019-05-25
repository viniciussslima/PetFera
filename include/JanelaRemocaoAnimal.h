#ifndef _JANELA_REMOCAO_ANIMAL_H_
#define _JANELA_REMOCAO_ANIMAL_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include <map>

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

class JanelaRemocaoAnimal
{
	private:
		Window *window;

		VBox *box_principal;
		HBox *box_dados;

		Entry *entry_id;
		Button *button_confirmar;

		Label *label_id;

		map<int, AnfibioExotico> *anfibios_exoticos;
		map<int, AnfibioNativo> *anfibios_nativos;

		map<int, AveExotico> *aves_exoticas;
		map<int, AveNativo> *aves_nativas;

		map<int, MamiferoExotico> *mamiferos_exoticos;
		map<int, MamiferoNativo> *mamiferos_nativos;

		map<int, ReptilExotico> *repteis_exoticos;
		map<int, ReptilNativo> *repteis_nativos;
	public:
		JanelaRemocaoAnimal(map<int, AnfibioExotico>&, map<int, AnfibioNativo>&, 
							     map<int, AveExotico>&, map<int, AveNativo>&,
							 	 map<int, MamiferoExotico>&, map<int, MamiferoNativo>&, 
							 	 map<int, ReptilExotico>&, map<int, ReptilNativo>&);
		~JanelaRemocaoAnimal();

		void Run();
		void Remover();
};

#endif
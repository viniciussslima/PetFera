#ifndef _REMOVER_FUNCIONARIO_H_
#define _REMOVER_FUNCIONARIO_H_

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

void RemoverFuncionario(JanelaPrincipal&, map<int, Veterinario>&, map<int, Tratador>&, 
					map<int, AnfibioExotico>&, map<int, AnfibioNativo>&, map<int, AveExotico>&,
					map<int, AveNativo>&, map<int, MamiferoExotico>&, map<int, MamiferoNativo>&,
					map<int, ReptilExotico>&, map<int, ReptilNativo>&, int);

bool Responsabilidade(map<int, AnfibioExotico> &, map<int, AnfibioNativo> &, 
						map<int, AveExotico> &, map<int, AveNativo> &, 
						map<int, MamiferoExotico> &, map<int, MamiferoNativo> &, 
						map<int, ReptilExotico> &, map<int, ReptilNativo> &, int);

#endif
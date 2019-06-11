/**
* @file RemoverFuncionario.h
* @brief Declaração da fução RemoverFuncionario.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _REMOVER_FUNCIONARIO_H_
#define _REMOVER_FUNCIONARIO_H_

#include <iostream>
#include <fstream>
#include <gtkmm.h>
#include <map>

#include "JanelaPrincipal.h"

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

void RemoverFuncionario(JanelaPrincipal&, map<int, Veterinario>&, map<int, Tratador>&, int);

#endif
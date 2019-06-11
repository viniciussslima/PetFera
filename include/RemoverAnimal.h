/**
* @file RemoverAnimal.h
* @brief Função que remove animais.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _REMOVER_ANIMAL_H_
#define _REMOVER_ANIMAL_H_

#include <iostream>
#include <fstream>
#include <map>
#include <gtkmm.h>

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

using namespace std;

void RemoverAnimal(JanelaPrincipal&, map<int, AnfibioExotico>&, map<int, AnfibioNativo>&, 
					map<int, AveExotico>&, map<int, AveNativo>&,
					map<int, MamiferoExotico>&, map<int, MamiferoNativo>&, 
					map<int, ReptilExotico>&, map<int, ReptilNativo>&, int, int);

#endif
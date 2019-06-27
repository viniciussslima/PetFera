#ifndef _EXPORTAR_H_
#define _EXPORTAR_H_

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <exception>

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

using namespace std;

map<int, Animal*> Carregar();

#endif
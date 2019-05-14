#ifndef _H_CARREGAR_H_
#define _H_CARREGAR_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "AnfibioNativo.h" 
#include "AnfibioExotico.h" 
#include "MamiferoNativo.h" 
#include "MamiferoExotico.h" 
#include "ReptilNativo.h" 
#include "ReptilExotico.h" 
#include "AveNativo.h" 
#include "AveExotico.h" 
#include "Veterinario.h"
#include "Tratador.h"
#include "separador.h"

using namespace std;

void carregar (vector<AnfibioExotico> &AnfibiosExoticos&,
	vector<AnfibioNativo> &AnfibiosNativos, 
	vector<AveExotico> &AvesExoticos,
	vector<AveNativo> &AvesNativos,
	vector<MamiferoExotico> &MamiferosExoticos,
	vector<MamiferoNativo> &MamiferosNativos,
	vector<ReptilExotico> &RepteisExoticos,
	vector<ReptilNativo> &RepteislNativos, 
	vector<Tratador> &Tratadores,
	vector<Veterinario> &Veterinarios);

#endif
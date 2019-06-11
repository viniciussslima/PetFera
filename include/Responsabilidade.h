/**
* @file Responsabilidade.h
* @brief Função que verifica se um funcionário é responsavel por animais.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _RESPONSABILIDADE_H_
#define _RESPONSABILIDADE_H_

#include <iostream>
#include <fstream>
#include <map>

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

using namespace std;

bool Responsabilidade(map<int, AnfibioExotico> &, map<int, AnfibioNativo> &, 
						map<int, AveExotico> &, map<int, AveNativo> &, 
						map<int, MamiferoExotico> &, map<int, MamiferoNativo> &, 
						map<int, ReptilExotico> &, map<int, ReptilNativo> &, int);

#endif
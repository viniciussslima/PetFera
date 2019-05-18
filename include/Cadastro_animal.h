#ifndef _H_CADASTRO_ANIMAL_H_
#define _H_CADASTRO_ANIMAL_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Cadastro_animal.h"
#include "AnfibioNativo.h" 
#include "AnfibioExotico.h" 
#include "MamiferoNativo.h" 
#include "MamiferoExotico.h" 
#include "ReptilNativo.h" 
#include "ReptilExotico.h" 
#include "AveNativo.h" 
#include "AveExotico.h" 
#include "Funcionario.h"
#include "Veterinario.h"
#include "Tratador.h"
#include "separador_csv.h"

void Cadastro_animal(vector<Animal> &Animais, 
	vector<Funcionario> &Funcionarios);

#endif

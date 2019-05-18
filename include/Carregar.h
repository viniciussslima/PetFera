#ifndef _H_CARREGAR_H_
#define _H_CARREGAR_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Animal.h"
#include "Funcionario.h"
#include "Veterinario.h"
#include "Tratador.h"
#include "separador_csv.h"

using namespace std;

void carregar (vector<Animal> &Animais, 
	vector<Funcionario> &Funcionario);

#endif
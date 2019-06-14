/**
* @file RemoverAnimal.h
* @brief Declaração da fução RemoverAnimal.
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

#include "Animal.h"

#include "Separador.h"

using namespace std;

void RemoverAnimal(JanelaPrincipal&, map<int, Animal*>&, int);

#endif
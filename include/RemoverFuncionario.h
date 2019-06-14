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

#include "Funcionario.h"

using namespace Gtk;
using namespace std;

void RemoverFuncionario(JanelaPrincipal&, map<int, Funcionario*>&, int);

#endif
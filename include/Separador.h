/**
* @file Separador.h
* @brief Funções que separam os dados de uma arquivo csv e de uma data.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_SEPARADOR_H_
#define _H_SEPARADOR_H_
#include <string>
#include <vector>

using namespace std;

vector<string> Separador_csv(string);
vector<int> Separador_data(string);

#endif
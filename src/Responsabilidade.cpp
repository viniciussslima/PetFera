/**
* @file Responsabilidade.cpp
* @brief Função que verifica se um funcionário é responsavel por animais.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Responsabilidade.h"

bool Responsabilidade(map<int, Animal*> &animais, int id)
{
	bool animal_sob_responsabilidade = false;
	for (map<int, Animal*>::iterator it = animais.begin(); it != animais.end(); it++)
	{
		if ((it->second)->get_veterinario_id() == id ||
			(it->second)->get_tratador_id() == id)
		{
			animal_sob_responsabilidade = true;
			break;
		}
	}
	return animal_sob_responsabilidade;
}
/**
* @file Responsabilidade.cpp
* @brief Função que verifica se um funcionário é responsavel por animais.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "Responsabilidade.h"

bool Responsabilidade(map<int, AnfibioExotico> &anfibios_exoticos, map<int, AnfibioNativo> &anfibios_nativos, 
						map<int, AveExotico> &aves_exoticas, map<int, AveNativo> &aves_nativas, 
						map<int, MamiferoExotico> &mamiferos_exoticos, map<int, MamiferoNativo> &mamiferos_nativos, 
						map<int, ReptilExotico> &repteis_exoticos, map<int, ReptilNativo> &repteis_nativos, int id)
{
	bool animal_sob_responsabilidade = false;
	for (map<int, AnfibioExotico>::iterator it = anfibios_exoticos.begin(); it != anfibios_exoticos.end(); it++)
	{
		if ((it->second).get_veterinario_id() == id ||
			(it->second).get_tratador_id() == id)
		{
			animal_sob_responsabilidade = true;
			break;
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, AnfibioNativo>::iterator it = anfibios_nativos.begin(); it != anfibios_nativos.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, AveExotico>::iterator it = aves_exoticas.begin(); it != aves_exoticas.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, AveNativo>::iterator it = aves_nativas.begin(); it != aves_nativas.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, MamiferoExotico>::iterator it = mamiferos_exoticos.begin(); it != mamiferos_exoticos.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, MamiferoNativo>::iterator it = mamiferos_nativos.begin(); it != mamiferos_nativos.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, ReptilExotico>::iterator it = repteis_exoticos.begin(); it != repteis_exoticos.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	if (!animal_sob_responsabilidade)
	{
		for (map<int, ReptilNativo>::iterator it = repteis_nativos.begin(); it != repteis_nativos.end(); it++)
		{
			if ((it->second).get_veterinario_id() == id ||
				(it->second).get_tratador_id() == id)
			{
				animal_sob_responsabilidade = true;
				break;
			}
		}
	}
	return animal_sob_responsabilidade;
}
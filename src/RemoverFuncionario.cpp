/**
* @file RemoverFuncionario.cpp
* @brief Função que remove funcionários.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "RemoverFuncionario.h"

using namespace std;

void RemoverFuncionario(JanelaPrincipal &janela_principal, map<int, Veterinario> &veterinarios, map<int, Tratador> &tratadores, 
						map<int, AnfibioExotico> &anfibios_exoticos, map<int, AnfibioNativo> &anfibios_nativos, 
						map<int, AveExotico> &aves_exoticas, map<int, AveNativo> &aves_nativas, 
						map<int, MamiferoExotico> &mamiferos_exoticos, map<int, MamiferoNativo> &mamiferos_nativos, 
						map<int, ReptilExotico> &repteis_exoticos, map<int, ReptilNativo> &repteis_nativos, int id)
{

	string linha;
	vector<string> palavras;
	ifstream funcionarios_csv("Dados/funcionarios.csv");

	if(!Responsabilidade(anfibios_exoticos, anfibios_nativos, aves_exoticas, aves_nativas, 
						mamiferos_exoticos, mamiferos_nativos, repteis_exoticos, repteis_nativos, id))
	{
		ofstream funcionarios_temp("Dados/TempFuncionario.csv");
		while(getline(funcionarios_csv, linha))
		{
			palavras = Separador_csv(linha);
			if(stoi(palavras[0]) != id)
				funcionarios_temp << linha << endl;
			else
			{
				if(palavras[1].compare("TRATADOR") == 0)
				{
					tratadores.erase(id);
					janela_principal.AtualizarLista(0);
				}
				else
				{
					veterinarios.erase(id);
					janela_principal.AtualizarLista(1);
				}
			}
		}
		remove("Dados/funcionarios.csv");
		rename("Dados/TempFuncionario.csv", "Dados/funcionarios.csv");
		funcionarios_temp.close();
	}
}

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
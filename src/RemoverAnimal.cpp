/**
* @file RemoverAnimal.cpp
* @brief Função que remove animais.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "RemoverAnimal.h"

using namespace std;

void RemoverAnimal(JanelaPrincipal &janela_principal, map<int, Animal*> &animais, int id)
{
	string linha;
	vector<string> palavras;
	ifstream animais_csv("Dados/animais.csv");

	ofstream animais_temp("Dados/temp_animais.csv");
	while(getline(animais_csv, linha))
	{
		palavras = Separador_csv(linha);
		if(stoi(palavras[0]) != id)
			animais_temp << linha << endl;
		else
		{
			if(palavras[1].compare("AMPHIBIA") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	animais.erase(id);
					janela_principal.AtualizarLista(2);
				}
			    else
			    {
			    	animais.erase(id);
			    	janela_principal.AtualizarLista(3);
			    }
		    }
		    if(palavras[1].compare("AVES") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	animais.erase(id);
					janela_principal.AtualizarLista(4);
				}
			    else
			    {
			    	animais.erase(id);
			    	janela_principal.AtualizarLista(5);
			    }
		    }
		    if(palavras[1].compare("MAMMALIA") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	animais.erase(id);
					janela_principal.AtualizarLista(6);
				}
			    else
			    {
			    	animais.erase(id);
			    	janela_principal.AtualizarLista(7);
			    }
		    }
		    if(palavras[1].compare("REPTILIA") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	animais.erase(id);
					janela_principal.AtualizarLista(8);
				}
			    else
			    {
			    	animais.erase(id);
			    	janela_principal.AtualizarLista(9);
			    }
		    }
		}
	}
	animais_csv.close();
	remove("Dados/animais.csv");
	rename("Dados/temp_animais.csv", "Dados/animais.csv");
	animais_temp.close();
}

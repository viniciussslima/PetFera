#include "RemoverAnimal.h"

using namespace std;

void RemoverAnimal(JanelaPrincipal &janela_principal, map<int, AnfibioExotico> &anfibios_exoticos, map<int, AnfibioNativo> &anfibios_nativos, 
										 map<int, AveExotico> &aves_exoticas, map<int, AveNativo> &aves_nativas,
										 map<int, MamiferoExotico> &mamiferos_exoticos, map<int, MamiferoNativo> &mamiferos_nativos, 
										 map<int, ReptilExotico> &repteis_exoticos, map<int, ReptilNativo> &repteis_nativos, 
										 int pagina, int id)
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
			    	anfibios_nativos.erase(id);
					janela_principal.AtualizarLista(2);
				}
			    else
			    {
			    	anfibios_exoticos.erase(id);
			    	janela_principal.AtualizarLista(3);
			    }
		    }
		    if(palavras[1].compare("AVES") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	aves_nativas.erase(id);
					janela_principal.AtualizarLista(4);
				}
			    else
			    {
			    	aves_exoticas.erase(id);
			    	janela_principal.AtualizarLista(5);
			    }
		    }
		    if(palavras[1].compare("MAMMALIA") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	mamiferos_nativos.erase(id);
					janela_principal.AtualizarLista(6);
				}
			    else
			    {
			    	mamiferos_exoticos.erase(id);
			    	janela_principal.AtualizarLista(7);
			    }
		    }
		    if(palavras[1].compare("REPTILIA") == 0)
		    {
				if(palavras[palavras.size() - 1].length() == 2)
				{
			    	repteis_nativos.erase(id);
					janela_principal.AtualizarLista(8);
				}
			    else
			    {
			    	repteis_exoticos.erase(id);
			    	janela_principal.AtualizarLista(9);
			    }
		    }
		}
	}
	remove("Dados/animais.csv");
	rename("Dados/temp_animais.csv", "Dados/animais.csv");
	animais_temp.close();
}

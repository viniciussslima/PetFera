#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "AnfibioNativo.h" 
#include "AnfibioExotico.h" 
#include "MamiferoNativo.h" 
#include "MamiferoExotico.h" 
#include "ReptilNativo.h" 
#include "ReptilExotico.h" 
#include "AveNativo.h" 
#include "AveExotico.h" 
#include "Veterinario.h"
#include "Tratador.h"
#include "separador.h"

using namespace std;

void carregar (vector<AnfibioExotico> &AnfibiosExoticos&,
	vector<AnfibioNativo> &AnfibiosNativos, 
	vector<AveExotico> &AvesExoticos,
	vector<AveNativo> &AvesNativos,
	vector<MamiferoExotico> &MamiferosExoticos,
	vector<MamiferoNativo> &MamiferosNativos,
	vector<ReptilExotico> &RepteisExoticos,
	vector<ReptilNativo> &RepteislNativos, 
	vector<Tratador> &Tratadores,
	vector<Veterinario> &Veterinarios)
{
	string files[] = {"animais", "funcionarios"}
	string data;
	vector <string> dados;
	for (int i = 0; i < 2; i++)
	{
		ifstream infile.open("../Dados/" + file[i] + ".csv")
		while(getline(infile, data))
		{
			separador(data, dados);
			if (dados[1].compare("Amphibia"))
			{
				if (dados[11].size() == 2)
				{
					AnfibioNativo anfibioNativo();
					AnfibiosNativos.push_back(anfibioNativo);
				}
			}
			dados.clear();
		}
		infile.close();
	}
}
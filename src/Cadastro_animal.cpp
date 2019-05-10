#include <iostream>
#include <string>
#include <fstream>

#include "Cadastro_animal.h"
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

using namespace std;
 
void Cadastro_animal()
{
	int id;
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	int veterinario_incluso;
	int tratador_incluso;
	string nome_batismo;
	string nascionalidade;

	cout << "" << endl;
	cin >> id;

	cout << "" << endl;
	cin >> classe;

	cout << "" << endl;
	cin >> nome_cientifico;

	cout << "" << endl;
	cin >> sexo;

	cout << "" << endl;
	cin >> tamanho;

	cout << "" << endl;
	cin >> dieta;

	cout << "" << endl;
	cin >> veterinario_incluso;

	cout << "" << endl;
	cin >> tratador_incluso;

	cout << "" << endl;
	cin >> nome_batismo;

	cout << "" << endl;
	cin >> nascionalidade;

	if(nascionalidade.compare("Brasileiro"))
	{
		if (classe.compare("Aves"))
		{
			//AveNativo aveNativo();
		}
	}
	else
	{
		if (classe.compare("Aves"))
		{
			int total_de_mudas;
			date ultima_mulda;
			string autorizacao_ibama;
			string nome_veterinario;
			string nome_tratador;

			cout << "" << endl;
			cin >> total_de_mudas;

			cout << "" << endl;
			cin >> ultima_mulda;

			cout << "" << endl;
			cin >> autorizacao_ibama;
			
			if (veterinario_incluso == 0 &&
				tratador_incluso == 0)
			{
				cin >> nome_veterinario;
				cin >> nome_tratador;
				//verifica se existe
				Veterinario veterinario;
				Tratador tratador;

				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, total_de_mudas, ultima_mulda,
				autorizacao_ibama, nascionalidade);

			}

			else if (veterinario_incluso == 0)
			{
				cin >> nome_veterinario;
				//verifica se existe
				Veterinario veterinario;
				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario,
				nome_batismo, total_de_mudas, ultima_mulda,
				autorizacao_ibama, nascionalidade);

			}

			else if (tratador_incluso == 0)
			{	
				cin >> nome_tratador;
				//verifica se existe
				Tratador tratador;

				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, tratador,
				nome_batismo, total_de_mudas, ultima_mulda,
				autorizacao_ibama, nascionalidade);

			}
		
			cout << aveExotico << endl;	
		}
	}
}

/*
Amphibia (anfíbio), 
Reptilia (réptil), 
Aves (ave),
Mammalia (mamífero)
*/
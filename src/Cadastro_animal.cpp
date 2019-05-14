#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
	ofstream outfile;

	cout << "id: ";
	cin >> id;

	cout << "classe: ";
	cin >> classe;

	cout << "nome cientifico: ";
	cin >> nome_cientifico;

	cout << "sexo: ";
	cin >> sexo;

	cout << "tamanho: ";
	cin >> tamanho;

	cout << "dieta: ";
	cin >> dieta;

	cout << "veterinario incluso: ";
	cin >> veterinario_incluso;

	cout << "tratador incluso: ";
	cin >> tratador_incluso;

	cout << "nome batismo: ";
	cin >> nome_batismo;

	cout << "nascionalidade: ";
	cin >> nascionalidade;

	if(nascionalidade.compare("Brasileiro") == 0)
	{
		if (classe.compare("Aves") == 0)
		{
			//AveNativo aveNativo();
		}
	}
	else
	{
		if (classe.compare("Aves") == 0)
		{
			int total_de_mudas;
			date ultima_mulda;
			string autorizacao_ibama;
			string nome_veterinario;
			string nome_tratador;

			cout << "total de mudas: ";
			cin >> total_de_mudas;

			cout << "ultima mulda: ";
			cin >> ultima_mulda;

			cout << "autorizacao ibama: ";
			cin >> autorizacao_ibama;
			
			if (veterinario_incluso == 0 &&
				tratador_incluso == 0)
			{
				cin >> nome_veterinario;
				cin >> nome_tratador;
				//verifica se existe
				Veterinario veterinario;
				Tratador tratador(1,"João Alberto","007.404.200-98",45,"AB",'-',"Répteis e Aves",1);


				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, total_de_mudas, ultima_mulda,
				autorizacao_ibama, nascionalidade);

				outfile.open("../Dados/Aves/Aves Exoticas/teste.csv", ios::app);
				outfile << aveExotico << endl;
			}

			else if (veterinario_incluso == 0)
			{
				cin >> nome_veterinario;
				//verifica se existe
				Veterinario veterinario;
				Tratador tratador;


				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, total_de_mudas, ultima_mulda,
				autorizacao_ibama, nascionalidade);
			}

			else if (tratador_incluso == 0)
			{	
				cin >> nome_tratador;
				//verifica se existe
				Veterinario veterinario;
				Tratador tratador;

				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, total_de_mudas, ultima_mulda,
				autorizacao_ibama, nascionalidade);

			}
			
		}
	}
}

/*
Amphibia (anfíbio), 
Reptilia (réptil), 
Aves (ave),
Mammalia (mamífero)
*/

/*
Nome do funcionário
CPF do funcionário
Idade do funcionário
Tipo sanguíneo
Fator RH
Tipo de dado
Inteiro

1,Tratador,João Alberto,007.404.200-98,45,AB,-,Répteis e Aves,1
2,Veterinario,Daniel Oscar,123.456.789-10,30,O,+,Felinos,CRMV-GO 0406,,
*/
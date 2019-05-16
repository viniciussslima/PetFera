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

/*verificao_funcionario(int id)
{
	ifstream infile.open("../Dados/funcionarios.csv");
	while(infile, data)
	{

	}

}*/
 
void Cadastro_animal()
{
	int id;
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	char veterinario_incluso;
	char tratador_incluso;
	string nome_batismo;
	string nacionalidade;
	ofstream outfile;

	cout << "Id: ";
	cin >> id;

	cout << "Classe: ";
	cin >> classe;

	cout << "Nome cientifico: ";
	cin.ignore();
	getline(cin, nome_cientifico);

	cout << "Sexo(M/F): ";
	cin >> sexo;
	sexo = toupper(sexo);

	cout << "Tamanho(em centímetros): ";
	cin >> tamanho;

	cout << "Dieta: ";
	cin.ignore();
	getline(cin, dieta);

	cout << "Veterinario incluso(S/N): ";
	cin >> veterinario_incluso;
	veterinario_incluso = toupper(veterinario_incluso);

	cout << "Tratador incluso(S/N): ";
	cin >> tratador_incluso;
	tratador_incluso = toupper(tratador_incluso);

	cout << "Nome batismo: ";
	cin.ignore();
	getline(cin, nome_batismo);

	cout << "Nacionalidade: ";
	cin.ignore();
	getline(cin, nacionalidade);

	if(nacionalidade.compare("Brasileiro") == 0)
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
			double tamanho_do_bico;
			double envergadura_das_asas;
			string autorizacao_ibama;
			int id_veterinario;
			int id_tratador;

			cout << "Tamanho do bico: ";
			cin >> tamanho_do_bico;

			cout << "Envergadura das asas: ";
			cin >> envergadura_das_asas;

			cout << "Autorizacao ibama: ";
			cin >> autorizacao_ibama;
			
			if (veterinario_incluso == 0 &&
				tratador_incluso == 0)
			{
				cin >> id_veterinario;
				cin >> id_tratador;
				//verificao_funcionario(id_veterinario);
				Veterinario veterinario;
				Tratador tratador(1,"João Alberto","007.404.200-98",45,"AB",'-',"Répteis e Aves",1);


				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, tamanho_do_bico, envergadura_das_asas,
				autorizacao_ibama, nacionalidade);

				outfile.open("../Dados/animais.csv", ios::app);
				outfile << aveExotico << endl;
			}

			else if (veterinario_incluso == 0)
			{
				cin >> id_veterinario;
				//verifica se existe
				Veterinario veterinario;
				Tratador tratador;


				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, tamanho_do_bico, envergadura_das_asas,
				autorizacao_ibama, nacionalidade);
			}

			else if (tratador_incluso == 0)
			{	
				cin >> id_tratador;
				//verifica se existe
				Veterinario veterinario;
				Tratador tratador;

				AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, tamanho_do_bico, envergadura_das_asas,
				autorizacao_ibama, nacionalidade);

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
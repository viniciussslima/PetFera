#include <iostream>
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

using namespace std;
 
void Cadastro_animal()
{
	int id;
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	bool veterinario;
	bool tratador;
	string nome_batismo
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
	cin >> veterinario;

	cout << "" << endl;
	cin >> tratador;

	cout << "" << endl;
	cin >> nome_batismo;

	cout << "" << endl;
	cin >> nascionalidade;

	if(nascionalidade.compare("Brasileiro"))
	{
		if (classe.compare("Amphibia"))
		{
			AnfibioNativo anfibioNativo();
		}
	}
	else
	{

	}
}

/*
Identificador do animal
Classe do animal
Nome científico do animal
Sexo do animal
Tamanho médio em metros
Dieta predominante
Veterinário associado
Tratador responsável
Nome de batismo
Nascionalidade
*/

/*
Amphibia (anfíbio), 
Reptilia (réptil), 
Aves (ave),
Mammalia (mamífero)
*/
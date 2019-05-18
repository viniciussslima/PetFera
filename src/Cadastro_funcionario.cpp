#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Cadastro_funcionario.h"
#include "Veterinario.h"
#include "Tratador.h"

using namespace std;
 
void Cadastro_funcionario()
{
	int id;
	string funcao;
	string nome_do_funcionario;
	string CPF;
	int idade;
	string tipo_sanguineo
	char RH;
	string especialidade;
	string CRMV;
	int nivel_de_segurança;
	ofstream outfile;

	cout << "Id: ";
	cin >> id;

	cout << "Função: ";
	cin >> funcao;
	funcao = toupper(funcao);

	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome_do_funcionario);

	cout << "CPF: ";
	cin >> CPF;

	cout << "Idade: ";
	cin >> idade;

	cout << "Tipo Sanguineo: ";
	cin >> tipo_sanguineo;

	cout << "RH: ";
	cin >> RH;

	cout << "Especialidade: ";
	cin.ignore();
	getline(cin, especialidade);

	if(funcao == "TRATADOR")
	{
		cout << "Nivel de Segurança: ";
		cin >> nivel_de_segurança;

		Tratador tratador(id, nome_do_funcionario, CPF, idade, tipo_sanguineo, RH, especialidade, nivel_de_segurança);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << tratador << endl;
	}
	if(funcao == "VETERINÁRIO")
	{
		cout << "CRMV: ";
		cin >> CRMV;

		Veterinario veterinario(id, nome, CPF, idade, tipo_sanguineo, RH, especialidade, CRMV);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << veterinario << endl;
	}
}
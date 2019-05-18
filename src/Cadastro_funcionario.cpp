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
	string cpf;
	short idade;
	string tipo_sanguineo;
	char rh;
	string especialidade;
	string crmv;
	int nivel_de_seguranca;
	ofstream outfile;

	cout << "Id: ";
	cin >> id;

	cout << "Função: ";
	cin >> funcao;
	for (unsigned int i = 0; i < funcao.length(); i++) 
		funcao[i] = toupper(funcao[i]);

	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome_do_funcionario);

	cout << "cpf: ";
	cin >> cpf;

	cout << "Idade: ";
	cin >> idade;

	cout << "Tipo Sanguineo: ";
	cin >> tipo_sanguineo;

	cout << "rh: ";
	cin >> rh;

	cout << "Especialidade: ";
	cin.ignore();
	getline(cin, especialidade);

	if(funcao.compare("TRATADOR") == 0)
	{
		cout << "Nivel de Segurança: ";
		cin >> nivel_de_seguranca;

		Tratador tratador(id, nome_do_funcionario, cpf, idade, tipo_sanguineo, rh, especialidade, nivel_de_seguranca);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << tratador << endl;
	}
	if(funcao.compare("VETERINARIO") == 0)
	{
		cout << "crmv: ";
		cin >> crmv;

		Veterinario veterinario(id, nome_do_funcionario, cpf, idade, tipo_sanguineo, rh, especialidade, crmv);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << veterinario << endl;
	}
}
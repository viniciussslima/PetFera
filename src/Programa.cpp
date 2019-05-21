#include "Programa.h"

Programa::Programa()
{
	loop = true;
}

void Programa::Run()
{
	Carregar();

	while(loop)
	{
		cout << "Digite um numero comrespondente: " << endl  
			<< "[1] Cadastro de um animal" << endl //Vinicius
			<< "[2] Remoção de um animal" << endl //Hudson
			<< "[3] Cadastro de um funcionario" << endl //Hudson
			<< "[4] Remoção de um funcionario" << endl //Kobata
			<< "[5] Consulta de dados de um animal" << endl //Vinicius
			<< "[6] Consulta de dados de funcionario" << endl //Kobata
			<< "[7] Sair" << endl;
		cin >> escolha;
	
		switch(escolha)
		{
			case '1':
				Cadastro_animal();
				break;
			case '2':
				Remocao_animal();
				break;
			case '3':
				Cadastro_funcionario();
				break;
			case '4':
				Remocao_funcionario();
				break;
			case '5':
				Consultar_animal();
				break;
			case '6':
				Consultar_funcionario();
				break;
			case '7':
				loop = false;
				break;
			default:
				cout << "Opção invalida\n" << endl;
				break;
		}
	}
}

void Programa::Carregar()
{
	
}

void Programa::Cadastro_animal()
{
	
}

void Programa::Remocao_animal()
{
	int id;
	cin >> id;

}

void Programa::Cadastro_funcionario()
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

void Programa::Remocao_funcionario()
{
	
}

void Programa::Consultar_animal()
{
	
}

void Programa::Consultar_funcionario()
{
	
}

void Programa::Separador(string data, vector<string> &dados)
{
	dados.clear();
	int i = 0;
	string palavras = "";
	for (string::iterator it = data.begin(); it != data.end(); it++)
	{
		if (*it != ';')
		{
			palavras += *it;
		}
		else
		{
			i++;
			dados.push_back(palavras);
			palavras = "";
		}
	}
}
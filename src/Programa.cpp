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
	map<int, string> nome_consulta;
	map<int,string> funcao_consulta;
	map<int,string> cpf_consulta;
	map<int,short> idade_consulta;
	map<int,char> rh_consulta;
	map<int,string> especialidade_consulta;
	map<int,string> crmv_consulta;
	map<int,int> nivel_de_seguranca_consulta;
	map<int,string> tipo_sanguineo_consulta;

	cout << "Id: ";
	cin >> id;

	cout << "Função: ";
	cin >> funcao;
	for (unsigned int i = 0; i < funcao.length(); i++) 
		funcao[i] = toupper(funcao[i]);

	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome_do_funcionario);
	funcionarioCF[id] = nome_do_funcionario;
	funcao_consulta[id] = funcao;

	cout << "cpf: ";
	cin >> cpf;
	cpf_consulta[id] = cpf;

	cout << "Idade: ";
	cin >> idade;
	idade_consulta[id] = idade;

	cout << "Tipo Sanguineo: ";
	cin >> tipo_sanguineo;
	tipo_sanguineo_consulta[id] tipo_sanguineo;

	cout << "rh: ";
	cin >> rh;
	rh_consulta[id] = rh; 

	cout << "Especialidade: ";
	cin.ignore();
	getline(cin, especialidade);
	especialidade_consulta[id] = especialidade;

	if(funcao.compare("TRATADOR") == 0)
	{
		cout << "Nivel de Segurança: ";
		cin >> nivel_de_seguranca;
		nivel_de_seguranca_consulta[id] = nivel_de_seguranca;

		Tratador tratador(id, nome_do_funcionario, cpf, idade, tipo_sanguineo, rh, especialidade, nivel_de_seguranca);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << tratador << endl;
	}
	if(funcao.compare("VETERINARIO") == 0)
	{
		cout << "crmv: ";
		cin >> crmv;
		crmv_consulta[id] = crmv;


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
	cout >>"digite o id do funcionario que voĉe deseja consultar" >> endl;
	int tempID;
	cin << tempID;
	cout >>"Nome :">> nome_consulta[tempID]>>" ----função: ">> funcao_consulta[tempID]  >>" ----cpf: ">> cpf_consulta[tempID] >>" ----idade: ">> idade_consulta[tempID] >> endl;
	cout >>"RH:">> rh_consulta[tempID] >>" ----Especialidade: " >> especialidade_consulta[tempID]>>" ----Crmv: ">> crmv_consulta[tempID]>>" ----nivel_de_seguranca: ">>nivel_de_seguranca_consulta[tempID] >> endl;
	cout >> "tipo sanguineo" >> tipo_sanguineo_consulta[tempID] >> endl;




}
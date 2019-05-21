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
	int id;
	string nome;
	string cpf;
	short idade;
	string tipo_sanguineo;
	char fator_rh;
	string especialidade;
	int nivel_de_seguranca
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	int veterinario_id;
	bool veterinario_incluso = false;
	int tratador_id;
	bool tratador_incluso = false;
	string nome_batismo;
	string nascionalidade;
	ifstream infile;
	string linha;
	vector <string> dados;
	
	string files[] = {"funcionarios", "animais"};
	for (int i = 0; i < 2; i++)
	{
		infile.open("../Dados/" + files[i] + ".csv");
		while(getline(infile, linha))
		{
			separador(linha, dados);

			if (files[i].compare("funcionarios") == 0 && !dados.empty())
			{
				for (unsigned int i = 0; i < funcao.length(); i++)
				{
					funcao[i] = toupper(funcao[i]);
				}		

				if (funcao.compare("TRATADOR") == 0)
				{
					id = stoi(dados[0]);
					funcao = dados[1];
					nome = dados[2];
					cpf = dados[3];
					idade = stoi(dados[4]);
					tipo_sanguineo = dados[5];
					fator_rh = dados[6][0];
					especialidade = dados[7];
					nivel_de_seguranca = stoi(dados[8]);

					Tratador tratador(id, nome, cpf,
						idade, tipo_sanguineo, fator_rh,
						especialidade, nivel_de_seguranca);
					tratadores.insert(pair<int, Tratador>(id, tratador));
				}		

				if (funcao.compare("VETERINARIO") == 0)
				{
					id = stoi(dados[0]);
					funcao = dados[1];
					nome = dados[2];
					cpf = dados[3];
					idade = stoi(dados[4]);
					tipo_sanguineo = dados[5];
					fator_rh = dados[6][0];
					especialidade = dados[7];
					crmv = dados[8];
					Veterinario veterinario(id, nome, cpf,
						idade, tipo_sanguineo, fator_rh,
						especialidade, crmv);
					veterinarios.insert(pair<int, Veterinario>(id, veterinario));
				}		
				
			}
			
			else if (files[i].compare("animais") == 0 && !dados.empty())
			{
				id = stoi(dados[0]);
				classe = dados[1];
				for (unsigned int i = 0; i < classe.length(); i++)
				{
					classe[i] = toupper(classe[i]);
				}		
				nome_cientifico = dados[2];
				sexo = dados[3][0];
				tamanho = stod(dados[4]);
				dieta = dados[5];

				if (!dados[6].empty())
				{
					veterinario_id = stoi(dados[6]);
					veterinario_incluso = true;
				}

				if (!dados[7].empty())
				{
					tratador_id = stoi(dados[7]);
					tratador_incluso = true;
				}

				nome_batismo = dados[8];

				if(veterinario_incluso)
				{
					auto it_veterinario = veterinarios.find(veterinario_id);
				}
				
				if (tratador_incluso)
				{
					auto it_tratador = tratadores.find(tratador_id);
				}

				if (classe.compare("AnfibioExotico") == 0)
				{

				}

				/*Animal animal(id, classe, nome_cientifico,
					sexo, tamanho, dieta, it_veterinario,
					tratador, nome_batismo);
				Animais.insert(pair<int, Animal>(id, animal));*/
			}
		}
		infile.close();
	}
	
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
	cout >> "digite o id do funcionario que deseja remover" >> endl;
	int tempIDD;
	cin << tempIDD;
	nome_consulta.erase(tempIDD);
	funcao_consulta.erase(tempIDD);
	cpf_consulta.erase(tempIDD);
	idade_consulta.erase(tempIDD);
	rh_consulta.erase(tempIDD);
	especialidade_consulta.erase(tempIDD);
	crmv_consulta.erase(tempIDD);
	nivel_de_seguranca_consulta.erase(tempIDD);	
	tipo_sanguineo_consulta.erase(tempIDD);
	tempIDD = 0;

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
	cout >> "tipo sanguineo" >> tipo_sanguineo_consulta[tempID]>> endl;
	tempID = 0;




}
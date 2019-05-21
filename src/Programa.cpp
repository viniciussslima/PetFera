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
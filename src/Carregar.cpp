#include "Carregar.h"

using namespace std;

void carregar (vector<Animal> &Animais, 
	vector<Funcionario> &Funcionarios)
{
	int id;
	string nome;
	string cpf;
	short idade;
	string tipo_sanguineo;
	char fator_rh;
	string especialidade;
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	int veterinario_id;
	int tratador_id;
	string nome_batismo;
	string nascionalidade;
	ifstream infile;
	
	string files[] = {"funcionarios", "animais"};
	string data;
	vector <string> dados;
	for (int i = 0; i < 2; i++)
	{
		infile.open("../Dados/" + files[i] + ".csv");
		while(getline(infile, data))
		{
			separador(data, dados);

			if (files[i].compare("funcionarios") == 0 && !dados.empty())
			{
				id = stoi(dados[0]);
				nome = dados[1];
				cpf = dados[2];
				idade = stoi(dados[3]);
				tipo_sanguineo = dados[4];
				fator_rh = dados[5][0];//
				especialidade = dados[6];

				Funcionario funcionario(id, nome, cpf,
					idade, tipo_sanguineo, fator_rh,
					especialidade);
				Funcionarios.push_back(funcionario);
			}
			
			else if (files[i].compare("animais") == 0 && !dados.empty())
			{
				id = stoi(dados[0]);
				classe = dados[1];
				nome_cientifico = dados[2];
				sexo = dados[3][0];//
				tamanho = stod(dados[4]);
				dieta = dados[5];
				veterinario_id = stoi(dados[6]);
				tratador_id = stoi(dados[7]);
				nome_batismo = dados[8];

				int p1 = -1, p2 = -1;
				for (unsigned int j = 0; j < Funcionarios.size(); j++)
				{
					if (Funcionarios[j].getId() == veterinario_id)
					{
						p1 = j;
						
					}
					else if (Funcionarios[j].getId() == tratador_id)
					{
						p2 = j;
					}
					if (p1 != -1 && p2 != -1)
					{
						break;
					}
				}
				ifstream arq_funcionarios;
				arq_funcionarios.open("../Dados/funcionarios.csv");
				int contador_linhas = 0;
				vector<string> dados_veterinario;
				vector<string> dados_tratador;
				while(getline(arq_funcionarios, data))
				{
					if (contador_linhas == p1)
					{
						separador(data, dados_veterinario);
					}
					else if (contador_linhas == p2)
					{
						separador(data, dados_tratador);	
					}
					contador_linhas++;
				}
				
				arq_funcionarios.close();

				Veterinario veterinario(stoi(dados_veterinario[0]),dados_veterinario[1],dados_veterinario[2],
					stoi(dados_veterinario[3]),dados_veterinario[4],dados_veterinario[5][0],
					dados_veterinario[6], dados_veterinario[7]);

				Tratador tratador(stoi(dados_tratador[0]),dados_tratador[1],dados_tratador[2],
					stoi(dados_tratador[3]),dados_tratador[4],dados_tratador[5][0],
					dados_tratador[6],stoi(dados_tratador[7]));

				Animal animal(id, classe, nome_cientifico,
					sexo, tamanho, dieta, veterinario,
					tratador, nome_batismo);
				Animais.push_back(animal);
			}
		}
		infile.close();
	}
}
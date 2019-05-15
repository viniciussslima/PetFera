#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Animal.h"
#include "Veterinario.h"
#include "Tratador.h"
#include "separador.h"

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
	Veterinario veterinario;
	Tratador tratador;
	string nome_batismo;
	string nascionalidade;
	ifstream infile;
	
	string files[] = {"funcionarios", "animais"}
	string data;
	vector <string> dados;
	for (int i = 0; i < 2; i++)
	{
		infile.open("../Dados/" + file[i] + ".csv")
		while(getline(infile, data))
		{
			separador(data, dados);

			if (file[i].compare("funcionarios"))
			{
				id = stoi(dados[0]);
				nome = dados[1];
				cpf = dados[2];
				idade = stoi(dados[3]);
				tipo_sanguineo = dados[4];
				fator_rh = dados[5];//
				especialidade = dados[6];

				Funcionario funcionario(id, nome, cpf,
					idade, tipo_sanguineo, fator_rh
					especialidade);
				funcionarios.push_back(funcionario);
			}
			
			else if (file[i].compare("animais"))
			{
				id = stoi(dados[0]);
				classe = dados[1];
				nome_cientifico = dados[2];
				sexo = dados[3];//
				tamanho = stod(dados[4]);
				dieta = dados[5];
				veterinario = dados[6];//
				tratador = dados[7];//
				nome_batismo = dados[8]

				Animal animal(id, classe, nome_cientifico,
					sexo, tamanho, dieta, veterinario,
					tratador, nome_batismo);
				Animais.push_back(animal);
			}
			dados.clear();
		}
		infile.close();
	}
}
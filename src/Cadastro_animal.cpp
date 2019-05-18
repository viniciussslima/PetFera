#include "Cadastro_animal.h"

using namespace std;

bool verificao_id (int id, vector<Animal> &Animais)
{
	for (auto it : Animais)
	{
		if (it.getId() == id)
		{
			return false;
		}
	}
	return true;
}

int verificao_funcionario(int id, vector<Funcionario> &Funcionarios)
{
	if (id == 0)
	{
		return -1;
	}

	for (unsigned int i = 0; i < Funcionarios.size(); ++i)
	{
		if (Funcionarios[i].getId() == id)
		{
			return i;
		}
	}
	return -1;
}
 
void Cadastro_animal(vector<Animal> &Animais, 
	vector<Funcionario> &Funcionarios)
{
	int id;
	bool teste_id;
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

	do{
		cout << "Id: ";
		cin >> id;
		teste_id = verificao_id(id, Animais);
		if (!teste_id)
		{
			cout << "Id já em uso" << endl;
		}
	}while(!teste_id);

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
			int id_veterinario = 0;
			int pos_veterinario;
			int id_tratador = 0;
			int pos_tratador;

			cout << "Tamanho do bico: ";
			cin >> tamanho_do_bico;

			cout << "Envergadura das asas: ";
			cin >> envergadura_das_asas;

			cout << "Autorizacao ibama: ";
			cin >> autorizacao_ibama;
			
			if (veterinario_incluso == 'S' &&
				tratador_incluso == 'S')
			{
				cout << "Id do veterinario: ";
				cin >> id_veterinario;
				cout << "Id do tratador: ";
				cin >> id_tratador;

				pos_veterinario = verificao_funcionario(id_veterinario, Funcionarios);
				pos_tratador = verificao_funcionario(id_tratador, Funcionarios);
				if (pos_veterinario == -1 || pos_tratador == -1)
				{
					cout << "id do veterinario e/ou tratador invalido"
						<< endl;
				}
			}

			else if (veterinario_incluso == 'S')
			{
				cout << "Id do veterinario: ";
				cin >> id_veterinario;
				pos_veterinario = verificao_funcionario(id_veterinario, Funcionarios);
				if (pos_veterinario == -1)
				{
					cout << "id do veterinario invalido"
						<< endl;
				}
			}

			else if (tratador_incluso == 'S')
			{	
				cout << "Id do tratador: ";
				cin >> id_tratador;
				pos_tratador = verificao_funcionario(id_tratador, Funcionarios);
				if (pos_tratador == -1)
				{
					cout << "id do tratador invalido"
						<< endl;
				}
			}

			ifstream arq_funcionarios;
			string linha;
			arq_funcionarios.open("../Dados/funcionarios.csv");
			int contador_linhas = 0;
			vector<string> dados_veterinario;
			vector<string> dados_tratador;
			while(getline(arq_funcionarios, linha))
			{
				if (contador_linhas == pos_veterinario)
				{
					separador(linha, dados_veterinario);
				}
				else if (contador_linhas == pos_tratador)
				{
					separador(linha, dados_tratador);	
				}
				contador_linhas++;
			}
			
			arq_funcionarios.close();

			Veterinario veterinario(stoi(dados_veterinario[0]),dados_veterinario[1],dados_veterinario[2],
				stoi(dados_veterinario[3]),dados_veterinario[4],dados_veterinario[5][0],
				dados_veterinario[6],stoi(dados_veterinario[7]));

			Tratador tratador(stoi(dados_tratador[0]),dados_tratador[1],dados_tratador[2],
				stoi(dados_tratador[3]),dados_tratador[4],dados_tratador[5][0],
				dados_tratador[6],stoi(dados_tratador[7]));

			AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, tamanho_do_bico, envergadura_das_asas,
				autorizacao_ibama, nacionalidade);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << aveExotico << endl;

			Animais.push_back(aveExotico);
		}
	}
}

/*
Amphibia (anfíbio), 
Reptilia (réptil), 
Aves (ave),
Mammalia (mamífero)
*/
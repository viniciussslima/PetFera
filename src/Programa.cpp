#include "Programa.h"
#include <string>
#include <fstream>
#include <algorithm>

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
	/*
	int id;
	string funcao;
	string nome;
	string cpf;
	short idade;
	string tipo_sanguineo;
	char fator_rh;
	string especialidade;

	int nivel_de_seguranca;
	string crmv;

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
	string autorizacao_ibama;

	string origem;

	int total_de_mudas;
	//date ultima_muda;

	double tamanho_do_bico;
	double evergadura_das_asas;

	string m_cor_pelo;

	bool venenoso; 
	string tipo_veneno;

	ifstream infile;
	string linha;
	vector <string> dados;
	
	string files[] = {"funcionarios", "animais"};
	for (int i = 0; i < 2; i++)
	{
		infile.open("../Dados/" + files[i] + ".csv");
		while(getline(infile, linha))
		{
			Separador(linha, ';', dados);

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

				map<int, Veterinario>::iterator it_veterinario;
				map<int, Tratador>::iterator it_tratador

				if(veterinario_incluso)
				{
					it_veterinario = veterinarios.find(veterinario_id);
				}
				
				if (tratador_incluso)
				{
					it_tratador = tratadores.find(tratador_id);
				}

				if (classe.compare("Anfibio") == 0)
				{
					total_de_mudas = stoi(dados[9]);
					autorizacao_ibama = dados[11];
					origem = dados[12];
					Separador(dados[10], ' ', dados);
					date ultima_muda(dados[0], dados[1], dados[2]);
					if (origem.length() == 2)
					{
						AnfibioNativo anfibioNativo(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario,
							tratador, nome_batismo, total_de_mudas,
							ultima_muda, autorizacao_ibama, origem);
						anfibios_nativos.insert(pair<int, AnfibioNativo>(id, anfibioNativo));

					}
					else
					{
						AnfibioExotico anfibioExotico(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario,
							tratador, nome_batismo, total_de_mudas,
							ultima_muda, autorizacao_ibama, origem);
						anfibios_exotico.insert(pair<int, AnfibioExotico>(id, anfibioExotico));
					}
				}

				Animal animal(id, classe, nome_cientifico,
					sexo, tamanho, dieta, it_veterinario,
					tratador, nome_batismo);
				Animais.insert(pair<int, Animal>(id, animal));

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
				string autorizacao_ibama;

				string pais_origem;
				string uf_origem;

				int total_de_mudas;
				date ultima_muda;
			}
		}
		infile.close();
	}
	*/
}

void Programa::Cadastro_animal()
{
	/*int id;
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
					separador(linha, ';', dados_veterinario);
				}
				else if (contador_linhas == pos_tratador)
				{
					separador(linha, ';', dados_tratador);	
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

			AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, veterinario, tratador,
				nome_batismo, tamanho_do_bico, envergadura_das_asas,
				autorizacao_ibama, nacionalidade);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << aveExotico << endl;

			Animais.push_back(aveExotico);
		}
	}*/
}

void Programa::Remocao_animal()
{
	int id;
	string linha;
	vector<string> palavras;
	vector<string> animal_para_excluir;
	ifstream arquivo_animais("../Dados/animais.csv");
	ofstream temp("../Dados/temp.txt");

	cin >> id;
    while (getline(arquivo_animais, linha))
    {
    	Separador(linha, ';', palavras);
        if (stoi(palavras[0]) != id)
            temp << linha << endl;
        else
        	Separador(linha, ';', animal_para_excluir);
    }
    temp.close();
    arquivo_animais.close();
    remove("../Dados/animais.csv");
    rename("../Dados/temp.txt","../Dados/animais.csv");
    if(animal_para_excluir[1].compare("Anfibio") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    {
	    	map<int, AnfibioNativo>::iterator it = anfibios_nativos.find(id);
	    	anfibios_nativos.erase(it);
	    }
	    else
	    {
	    	map<int, AnfibioExotico>::iterator it = anfibios_exoticos.find(id);
	    	anfibios_exoticos.erase(it);
	    }
    }
    if(animal_para_excluir[1].compare("Ave") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    {
	    	map<int, AveNativo>::iterator it = aves_nativos.find(id);
	    	aves_nativos.erase(it);
	    }
	    else
	    {
	    	map<int, AveExotico>::iterator it = aves_exoticos.find(id);
	    	aves_exoticos.erase(it);
	    }
    }
    if(animal_para_excluir[1].compare("Mamifero") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    {
	    	map<int, MamiferoNativo>::iterator it = mamiferos_nativos.find(id);
	    	mamiferos_nativos.erase(it);
	    }
	    else
	    {
	    	map<int, MamiferoExotico>::iterator it = mamiferos_exoticos.find(id);
	    	mamiferos_exoticos.erase(it);
	    }
    }
    if(animal_para_excluir[1].compare("Reptil") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    {
	    	map<int, ReptilNativo>::iterator it = repteis_nativos.find(id);
	    	repteis_nativos.erase(it);
	    }
	    else
	    {
	    	map<int, ReptilExotico>::iterator it = repteis_exoticos.find(id);
	    	repteis_exoticos.erase(it);
	    }
    }
}

void Programa::Cadastro_funcionario()
{
	/*int id;
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
	nome_consulta[id] = nome_do_funcionario;
	funcao_consulta[id] = funcao;

	cout << "cpf: ";
	cin >> cpf;
	cpf_consulta[id] = cpf;

	cout << "Idade: ";
	cin >> idade;
	idade_consulta[id] = idade;

	cout << "Tipo Sanguineo: ";
	cin >> tipo_sanguineo;
	tipo_sanguineo_consulta[id] = tipo_sanguineo;

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
	}*/
	
}

void Programa::Remocao_funcionario()
{
	/*cout << "digite o id do funcionario que deseja remover" << endl;
	int tempIDD;
	cin >> tempIDD;
	nome_consulta.erase(tempIDD);
	funcao_consulta.erase(tempIDD);
	cpf_consulta.erase(tempIDD);
	idade_consulta.erase(tempIDD);
	rh_consulta.erase(tempIDD);
	especialidade_consulta.erase(tempIDD);
	crmv_consulta.erase(tempIDD);
	nivel_de_seguranca_consulta.erase(tempIDD);	
	tipo_sanguineo_consulta.erase(tempIDD);
	tempIDD = 0;*/

}

void Programa::Consultar_animal()
{
	
}

void Programa::Consultar_funcionario()
{
	/*cout << "digite o id do funcionario que voĉe deseja consultar" << endl;
	int tempID;
	cin >> tempID;
	cout << "Nome :" << nome_consulta[tempID] << endl
		<< " ----função: " << funcao_consulta[tempID] << endl
		<< " ----cpf: " << cpf_consulta[tempID] << endl
		<< " ----idade: " << idade_consulta[tempID] << endl
		<< "RH:" << rh_consulta[tempID] << endl
		<< " ----Especialidade: " << especialidade_consulta[tempID] << endl
		<< " ----Crmv: " << crmv_consulta[tempID] << endl
		<< " ----nivel_de_seguranca: " << nivel_de_seguranca_consulta[tempID] << endl
		<< "tipo sanguineo" >> tipo_sanguineo_consulta[tempID] << endl;
	tempID = 0;*/
}

void Programa::Separador(string data, char separador, vector<string> &dados)
{
    dados.clear();
    int i = 0;
    string palavras = "";
    for (string::iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it != separador)
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
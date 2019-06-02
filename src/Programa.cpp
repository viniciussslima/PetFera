/**
* @file Programa.cpp
*/

#include "Programa.h"

using namespace std;

/**
* @brief Construtor padrão da classe Programa.
*/

Programa::Programa()
{
	loop = true;
}

/**
* @brief Método que inicia o programa e mostra o menu.
*/

void Programa::Run()
{
	Carregar();

	while(loop)
	{
		cout << "Digite um numero comrespondente: " << endl  
			<< "[1] Cadastro de um animal" << endl
			<< "[2] Remoção de um animal" << endl
			<< "[3] Cadastro de um funcionário" << endl
			<< "[4] Remoção de um funcionário" << endl
			<< "[5] Consulta de dados de um animal" << endl
			<< "[6] Consulta de dados de funcionário" << endl
			<< "[7] Modificar dados" << endl
			<< "[8] Sair" << endl;
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
				Modificar_informacoes();
				break;
			case '8':
				loop = false;
				break;
			default:
				cout << "Opção invalida\n" << endl;
				break;
		}
	}
}

/**
* @brief Método que tranfere todas as informções nos arquivos csv para a maps.
*/

void Programa::Carregar()
{
	
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
	double envergadura_das_asas;

	string cor_pelo;

	bool venenoso; 
	string tipo_veneno;

	ifstream infile;
	string linha;
	vector <string> dados;

	Veterinario veterinario0;
	veterinarios.insert(pair<int, Veterinario>(0, veterinario0));

	Tratador tratador0;
	tratadores.insert(pair<int, Tratador>(0, tratador0));
	
	string files[] = {"funcionarios", "animais"};
	for (int i = 0; i < 2; i++)
	{
		infile.open("../Dados/" + files[i] + ".csv");
		while(getline(infile, linha))
		{
			Separador_csv(linha, dados);
			if (files[i].compare("funcionarios") == 0 && !dados.empty())
			{
				id = stoi(dados[0]);
				funcao = dados[1];
				nome = dados[2];
				cpf = dados[3];
				idade = stoi(dados[4]);
				tipo_sanguineo = dados[5];
				fator_rh = dados[6][0];
				especialidade = dados[7];	

				if (funcao.compare("TRATADOR") == 0)
				{
					nivel_de_seguranca = stoi(dados[8]);

					Tratador tratador(id, nome, cpf,
						idade, tipo_sanguineo, fator_rh,
						especialidade, nivel_de_seguranca);
					tratadores.insert(pair<int, Tratador>(id, tratador));
				}		

				if (funcao.compare("VETERINARIO") == 0)
				{
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

				if (stoi(dados[6]) != 0)
				{
					veterinario_id = stoi(dados[6]);
					veterinario_incluso = true;
				}

				if (stoi(dados[7]) != 0)
				{
					tratador_id = stoi(dados[7]);
					tratador_incluso = true;
				}

				nome_batismo = dados[8];

				map<int, Veterinario>::iterator it_veterinario;
				map<int, Tratador>::iterator it_tratador;

				if(veterinario_incluso)
				{
					it_veterinario = veterinarios.find(veterinario_id);
				}
				else
				{
					it_veterinario = veterinarios.find(0);
				}
				
				if (tratador_incluso)
				{
					it_tratador = tratadores.find(tratador_id);
				}
				else
				{
					it_tratador = tratadores.find(0);
				}

				if (classe.compare("AMPHIBIA") == 0)
				{
					total_de_mudas = stoi(dados[9]);
					autorizacao_ibama = dados[11];
					origem = dados[12];
					Separador_data(dados[10], dados);
					date ultima_muda(stoi(dados[0]), stoi(dados[1]), stoi(dados[2]));
					if (origem.length() == 2)
					{
						AnfibioNativo anfibioNativo(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo, total_de_mudas,
							ultima_muda, autorizacao_ibama, origem);
						anfibios_nativos.insert(pair<int, AnfibioNativo>(id, anfibioNativo));

					}
					else
					{
						AnfibioExotico anfibioExotico(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo, total_de_mudas,
							ultima_muda, autorizacao_ibama, origem);
						anfibios_exoticos.insert(pair<int, AnfibioExotico>(id, anfibioExotico));
					}
				}
				else if (classe.compare("AVES") == 0)
				{
					tamanho_do_bico = stod(dados[9]);
					envergadura_das_asas = stod(dados[10]);
					autorizacao_ibama = dados[11];
					origem = dados[12];
					if (origem.length() == 2)
					{
						AveNativo aveNativo(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo, tamanho_do_bico,
							envergadura_das_asas, autorizacao_ibama, origem);
						aves_nativas.insert(pair<int, AveNativo>(id, aveNativo));

					}
					else
					{
						AveExotico aveExotico(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo, tamanho_do_bico,
							envergadura_das_asas, autorizacao_ibama, origem);
						aves_exoticas.insert(pair<int, AveExotico>(id, aveExotico));
					}
				}
				else if (classe.compare("MAMMALIA") == 0)
				{
					cor_pelo = dados[9];
					autorizacao_ibama = dados[10];
					origem = dados[11];
					if (origem.length() == 2)
					{
						MamiferoNativo mamiferoNativo(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo,
							cor_pelo, autorizacao_ibama, origem);
						mamiferos_nativos.insert(pair<int, MamiferoNativo>(id, mamiferoNativo));

					}
					else
					{
						MamiferoExotico mamiferoExotico(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo,
							cor_pelo, autorizacao_ibama, origem);
						mamiferos_exoticos.insert(pair<int, MamiferoExotico>(id, mamiferoExotico));
					}
				}
				else if (classe.compare("REPTILIA") == 0)
				{
					venenoso = stoi(dados[9]);
					tipo_veneno = dados[10];
					autorizacao_ibama = dados[11];
					origem = dados[12];
					if (origem.length() == 2)
					{
						ReptilNativo reptilNativo(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo, venenoso,
							tipo_veneno, autorizacao_ibama, origem);
						repteis_nativos.insert(pair<int, ReptilNativo>(id, reptilNativo));

					}
					else
					{
						ReptilExotico reptilExotico(id, classe, nome_cientifico,
							sexo, tamanho, dieta, it_veterinario->second,
							it_tratador->second, nome_batismo, venenoso,
							tipo_veneno, autorizacao_ibama, origem);
						repteis_exoticos.insert(pair<int, ReptilExotico>(id, reptilExotico));
					}
				}
			}
		}
		infile.close();
	}
}

/**
* @brief Método que cadatra animais.
* @param id Numero que representa o ID do animal que vai ser cadastrado, por padrão o ID é igual a zero.
*/

void Programa::Cadastro_animal(int id)
{
	string teste_id = "N/A";
	string classe;
	string nome_cientifico;
	char sexo;
	float tamanho;
	string dieta;
	char veterinario_incluso;
	int id_veterinario;
	map<int, Veterinario>::iterator it_veterinario;
	char tratador_incluso;
	int id_tratador;
	map<int, Tratador>::iterator it_tratador;
	string autorizacao_ibama;
	string nome_batismo;
	string nacionalidade;
	vector<string> dados;
	ofstream outfile;

	do{
		if (id == 0 || teste_id.compare("N/A") != 0)
		{
			cout << "Id: ";
			cin >> id;
			teste_id = Verificar_id_animal(id);
		}

		if (teste_id.compare("N/A") != 0)
		{
			cout << "Id já em uso" << endl;
		}
	}while(teste_id.compare("N/A") != 0);

	cout << "Classe: ";
	cin >> classe;
	for (unsigned int i = 0; i < classe.length(); i++)
	{
		classe[i] = toupper(classe[i]);
	}

	cout << "Nome cientifico: ";
	cin.ignore();
	getline(cin, nome_cientifico);
	for (unsigned int i = 0; i < nome_cientifico.length(); i++)
	{
		nome_cientifico[i] = toupper(nome_cientifico[i]);
	}

	cout << "Sexo(M/F): ";
	cin >> sexo;
	sexo = toupper(sexo);

	cout << "Tamanho(em centímetros): ";
	cin >> tamanho;

	cout << "Dieta: ";
	cin.ignore();
	getline(cin, dieta);
	for (unsigned int i = 0; i < dieta.length(); i++)
	{
		dieta[i] = toupper(dieta[i]);
	}

	cout << "Nome batismo: ";
	cin.ignore();
	getline(cin, nome_batismo);
	for (unsigned int i = 0; i < nome_batismo.length(); i++)
	{
		nome_batismo[i] = toupper(nome_batismo[i]);
	}

	cout << "Autorizacao ibama: ";
	cin >> autorizacao_ibama;
	for (unsigned int i = 0; i < autorizacao_ibama.length(); i++)
	{
		autorizacao_ibama[i] = toupper(autorizacao_ibama[i]);
	}

	cout << "Veterinario incluso(S/N): ";
	cin >> veterinario_incluso;
	veterinario_incluso = toupper(veterinario_incluso);

	if (veterinario_incluso == 'S')
	{
		do{
			cout << "Id do veterinario: ";
			cin >> id_veterinario;
			it_veterinario = veterinarios.find(id_veterinario);
			if (it_veterinario == veterinarios.end())
			{
				cout << "Id invalido" << endl;
			}
		}while(it_veterinario == veterinarios.end());
	}
	else
	{
		it_veterinario = veterinarios.find(0);
	}

	cout << "Tratador incluso(S/N): ";
	cin >> tratador_incluso;
	tratador_incluso = toupper(tratador_incluso);

	if (tratador_incluso == 'S')
	{	
		do{
			cout << "Id do tratador: ";
			cin >> id_tratador;
			it_tratador = tratadores.find(id_tratador);
			if (it_tratador == tratadores.end())
			{
				cout << "Id invalido" << endl;
			}
		}while(it_tratador == tratadores.end());
	}
	else
	{
		it_tratador = tratadores.find(0);	
	}

	cout << "Nacionalidade: ";
	cin.ignore();
	getline(cin, nacionalidade);
	for (unsigned int i = 0; i < nacionalidade.length(); i++)
	{
		nacionalidade[i] = toupper(nacionalidade[i]);
	}

	if(nacionalidade.compare("BRASILEIRO") == 0)
	{
		string UF;
		cout << "UF: ";
		cin >> UF;
		for (unsigned int i = 0; i < UF.length(); i++)
		{
			UF[i] = toupper(UF[i]);
		}


		if (classe.compare("AMPHIBIA") == 0)
		{
			int total_de_mudas;
			string data;

			cout << "Total de mudas: ";
			cin >> total_de_mudas;
			
			cout << "Data da ultima muda: ";
			cin >> data;
			Separador_data(data, dados);
			date ultima_muda(stoi(dados[0]), stoi(dados[1]), stoi(dados[2]));


			AnfibioNativo anfibioNativo(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, total_de_mudas, 
				ultima_muda, autorizacao_ibama, UF);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << anfibioNativo << endl;

			anfibios_nativos.insert(pair<int, AnfibioNativo>(id, anfibioNativo));
		}
		else if (classe.compare("AVES") == 0)
		{
			double tamanho_do_bico;
			double envergadura_das_asas;

			cout << "Tamanho do bico: ";
			cin >> tamanho_do_bico;

			cout << "Envergadura das asas: ";
			cin >> envergadura_das_asas;

			AveNativo aveNativo(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, tamanho_do_bico, 
				envergadura_das_asas, autorizacao_ibama, UF);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << aveNativo << endl;

			aves_nativas.insert(pair<int, AveNativo>(id, aveNativo));
		}
		else if (classe.compare("MAMMALIA") == 0)
		{
			string cor_pelo;

			cout << "Cor do pelo: ";
			cin.ignore();
			getline(cin, cor_pelo);
			for (unsigned int i = 0; i < cor_pelo.length(); i++)
			{
				cor_pelo[i] = toupper(cor_pelo[i]);
			}


			MamiferoNativo mamiferoNativo(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, cor_pelo, 
				autorizacao_ibama, UF);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << mamiferoNativo << endl;

			mamiferos_nativos.insert(pair<int, MamiferoNativo>(id, mamiferoNativo));
		}
		else if (classe.compare("REPTILIA") == 0)
		{
			char venenoso_r;
			bool venenoso;
			string tipo_veneno = "";

			cout << "venenoso(S/N): ";
			cin >> venenoso_r;
			venenoso_r = toupper(venenoso_r);
			if (venenoso_r == 'S')
			{
				venenoso = true;
				cout << "Tipo de veneno: ";
				cin.ignore();
				getline(cin, tipo_veneno);
				for (unsigned int i = 0; i < tipo_veneno.length(); i++)
				{
					tipo_veneno[i] = toupper(tipo_veneno[i]);
				}
			}
			else
			{
				venenoso = false;
			}


			ReptilNativo reptilNativo(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, venenoso, 
				tipo_veneno, autorizacao_ibama, UF);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << reptilNativo << endl;

			repteis_nativos.insert(pair<int, ReptilNativo>(id, reptilNativo));
		}
	}
	else
	{
		if (classe.compare("AMPHIBIA") == 0)
		{
			int total_de_mudas;
			string data;

			cout << "Total de mudas: ";
			cin >> total_de_mudas;
			
			cout << "Data da ultima muda: ";
			cin >> data;
			Separador_data(data, dados);
			date ultima_muda(stoi(dados[0]), stoi(dados[1]), stoi(dados[2]));

			AnfibioExotico anfibioExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, total_de_mudas, 
				ultima_muda, autorizacao_ibama, nacionalidade);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << anfibioExotico << endl;

			anfibios_exoticos.insert(pair<int, AnfibioExotico>(id, anfibioExotico));
		}
		else if (classe.compare("AVES") == 0)
		{
			double tamanho_do_bico;
			double envergadura_das_asas;

			cout << "Tamanho do bico: ";
			cin >> tamanho_do_bico;

			cout << "Envergadura das asas: ";
			cin >> envergadura_das_asas;

			AveExotico aveExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, tamanho_do_bico, 
				envergadura_das_asas, autorizacao_ibama, nacionalidade);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << aveExotico << endl;

			aves_exoticas.insert(pair<int, AveExotico>(id, aveExotico));
		}
		else if (classe.compare("MAMMALIA") == 0)
		{
			string cor_pelo;

			cout << "Cor do pelo: ";
			cin.ignore();
			getline(cin, cor_pelo);
			for (unsigned int i = 0; i < cor_pelo.length(); i++)
			{
				cor_pelo[i] = toupper(cor_pelo[i]);
			}


			MamiferoExotico mamiferoExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, cor_pelo, 
				autorizacao_ibama, nacionalidade);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << mamiferoExotico << endl;

			mamiferos_exoticos.insert(pair<int, MamiferoExotico>(id, mamiferoExotico));
		}
		else if (classe.compare("REPTILIA") == 0)
		{
			char venenoso_r;
			bool venenoso;
			string tipo_veneno = "";

			cout << "venenoso(S/N): ";
			cin >> venenoso_r;
			venenoso_r = toupper(venenoso_r);
			if (venenoso_r == 'S')
			{
				venenoso = true;
				cout << "Tipo de veneno: ";
				cin.ignore();
				getline(cin, tipo_veneno);
				for (unsigned int i = 0; i < tipo_veneno.length(); i++)
				{
					tipo_veneno[i] = toupper(tipo_veneno[i]);
				}
			}
			else
			{
				venenoso = false;
			}


			ReptilExotico reptilExotico(id, classe, nome_cientifico,
				sexo, tamanho, dieta, it_veterinario->second, 
				it_tratador->second, nome_batismo, venenoso, 
				tipo_veneno, autorizacao_ibama, nacionalidade);

			outfile.open("../Dados/animais.csv", ios::app);
			outfile << reptilExotico << endl;

			repteis_exoticos.insert(pair<int, ReptilExotico>(id, reptilExotico));
		}
	}
}

/**
* @brief Método que remove animais.
* @param id Numero que representa o ID do animal que vai ser removido, por padrão o ID é igual a zero.
*/

void Programa::Remocao_animal(int id)
{
	string linha;
	vector<string> palavras;
	vector<string> animal_para_excluir;
	ifstream arquivo_animais("../Dados/animais.csv");
	ofstream temp("../Dados/temp.txt");

	if (id == 0)
	{
		cout << "Digite o id do animal que quer remover" << endl;
	 	cin >> id;
	}
    while (getline(arquivo_animais, linha))
    {
    	Separador_csv(linha, palavras);
        if (stoi(palavras[0]) != id)
            temp << linha << endl;
        else
        	Separador_csv(linha, animal_para_excluir);
    }
    temp.close();
    arquivo_animais.close();
    remove("../Dados/animais.csv");
    rename("../Dados/temp.txt","../Dados/animais.csv");
    if(animal_para_excluir[1].compare("AMPHIBIA") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    	anfibios_nativos.erase(id);
	    else
	    	anfibios_exoticos.erase(id);
    }
    if(animal_para_excluir[1].compare("AVES") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    	aves_nativas.erase(id);
	    else
	    	aves_exoticas.erase(id);
    }
    if(animal_para_excluir[1].compare("MAMMALIA") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    	mamiferos_nativos.erase(id);
	    else
	    	mamiferos_exoticos.erase(id);
    }
    if(animal_para_excluir[1].compare("REPTILIA") == 0)
    {
		if(animal_para_excluir[animal_para_excluir.size() - 1].length() == 2)
	    	repteis_nativos.erase(id);
	    else
	    	repteis_exoticos.erase(id);
    }
}

/**
* @brief Método que cadastra funcionários.
* @param id Numero que representa o ID do funcionário que vai ser cadastrado, por padrão o ID é igual a zero.
*/

void Programa::Cadastro_funcionario(int id)
{
	string funcao;
	string nome_do_funcionario;
	string cpf;
	short idade;
	string tipo_sanguineo;
	char rh;
	string especialidade;
	string crmv;
	int nivel_de_seguranca;
	string teste_id = "N/A";
	ofstream outfile;

	do{
		if (id == 0 || teste_id.compare("N/A") != 0)
		{
			cout << "Id: ";
			cin >> id;
			teste_id = Verificar_id_funcionario(id);
		}

		if (teste_id.compare("N/A") != 0)
		{
			cout << "Id já em uso" << endl;
		}
	}while(teste_id.compare("N/A") != 0);

	cout << "(Veterinario/Tratador) Função: ";
	cin >> funcao;
	for (unsigned int i = 0; i < funcao.length(); i++) 
		funcao[i] = toupper(funcao[i]);

	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome_do_funcionario);

	cout << "(xxx.xxx.xxx-xx)cpf: ";
	cin >> cpf;

	cout << "Idade: ";
	cin >> idade;

	cout << "(A,B,O,AB)Tipo Sanguineo: ";
	cin >> tipo_sanguineo;

	cout << "(+ ou -)rh: ";
	cin >> rh;

	cout << "Especialidade: ";
	cin.ignore();
	getline(cin, especialidade);

	if(funcao.compare("TRATADOR") == 0)
	{
		cout << "(0,1,2,3)Nivel de Segurança: ";
		cin >> nivel_de_seguranca;

		Tratador tratador(id, nome_do_funcionario, cpf, idade, tipo_sanguineo, rh, especialidade, nivel_de_seguranca);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << tratador << endl;
		tratadores.insert(pair<int, Tratador>(id, tratador));
	}
	if(funcao.compare("VETERINARIO") == 0)
	{
		cout << "crmv: ";
		cin >> crmv;

		Veterinario veterinario(id, nome_do_funcionario, cpf, idade, tipo_sanguineo, rh, especialidade, crmv);
		outfile.open("../Dados/funcionarios.csv", ios::app);
		outfile << veterinario << endl;
		veterinarios.insert(pair<int, Veterinario>(id, veterinario));
	}
}

/**
* @brief Método que remove funcionários.
* @param id Numero que representa o ID do funcionário que vai ser removido, por padrão o ID é igual a zero.
*/

void Programa::Remocao_funcionario(int id)
{
	
	string linha;
	int ID_Do_Funcionario_R;
	vector<string> palavras;
	ofstream arquivoTemp("../Dados/TempFuncionario.csv");


	cout << "digite o id do funcionario que deseja remover" << endl;
	cin >> ID_Do_Funcionario_R;
	ifstream Edit_A("../Dados/funcionarios.csv");

	veterinarios.erase(ID_Do_Funcionario_R);
	tratadores.erase(ID_Do_Funcionario_R);


	if(Edit_A.is_open())
	{
		while(getline(Edit_A,linha))
		{
			Separador_csv(linha,palavras);
			if(stoi(palavras[0]) != ID_Do_Funcionario_R)
			{
				arquivoTemp << linha << endl;
			}
		}
		remove("../Dados/funcionarios.csv");
		rename("../Dados/TempFuncionario.csv","../Dados/funcionarios.csv");
		arquivoTemp.close();
	}
	else
	{
		cout<< "não foi possivel abrir o arquivo" << endl;
	}
}

/**
* @brief Método que procura e imprime as informações de um animal já cadatrado aparti de sua ID.
*/

void Programa::Consultar_animal()
{
	int id;
	string teste_id;
	bool loop = true;
	do{
		cout << "Id: ";
		cin >> id;

		teste_id = Verificar_id_animal(id);

		if(teste_id.compare("AnfibioExotico") == 0)
		{
			anfibios_exoticos[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("AnfibioNativo") == 0)
		{
			anfibios_nativos[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("AveExotica") == 0)
		{
			aves_exoticas[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("AveNativa") == 0)
		{
			aves_nativas[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("MamiferoExotico") == 0)
		{	
			mamiferos_exoticos[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("MamiferoNativo") == 0)
		{
			mamiferos_nativos[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("ReptilExotico") == 0)
		{
			repteis_exoticos[id].Exibir_informacoes();
			loop = false;
		}
		else if(teste_id.compare("ReptilNativo") == 0)
		{
			repteis_nativos[id].Exibir_informacoes();
			loop = false;
		}
		else
		{
			cout << "Id invalido" << endl;
		}
	}while(loop); 
}

/**
* @brief Método que procura e imprime as informações de um animal já cadatrado aparti de sua ID.
*/

void Programa::Consultar_funcionario()
{
	int ID_Do_Funcionario;
	bool id_test = false;
	int i;
	string linha;
	ifstream Ler_B;
	vector<string> palavra;

	cout <<"(1) ver um funcionario especifico" <<"-- (2) ver todos os funcionarios" << endl;

	cin >> i;
	switch(i)
	{
		case 1:
		do{
				cout <<"digite o id do funcionario" << endl;
				cin >> ID_Do_Funcionario; 

				map<int, Veterinario>::iterator iterator_V = veterinarios.find(ID_Do_Funcionario);
				map<int, Tratador>::iterator iterator_T = tratadores.find(ID_Do_Funcionario);

				if(iterator_V != veterinarios.end()){
							id_test = true;
							iterator_V->second.Exibir_Veterinario();
							break;
				}
				if(iterator_T != tratadores.end()){
							id_test = true;
							iterator_T->second.Exibir_tratador();
				}
				else{
					id_test = false;
				}
				if(!id_test){
					cout <<"Erro no id" << endl;
				}
			}while(!id_test);
			break;


		case 2:
			Ler_B.open("../Dados/funcionarios.csv");
			if(Ler_B.is_open()){
				while(getline(Ler_B,linha)){
					Separador_csv(linha,palavra);
					if(palavra[1].compare("VETERINARIO") == 0){

					cout << "Nome:(" << palavra[2] <<")"<< endl
					 <<"ID: "<<palavra [0]<< " / função: " << palavra[1]<<endl 
					 <<"CPF: " <<palavra[3] <<" / idade: " << palavra[4]<<endl
					 <<"Tipo sanguineo: " <<palavra[5] <<" / RH: " <<palavra[6]<< endl
					 <<"especialidade: " << palavra[7] <<" / crmv: " <<palavra[8]<<endl;
					 cout <<"-----------------------------" <<endl;
					}
					if(palavra[1].compare("TRATADOR") == 0)
					{
						cout << "Nome:(" << palavra[2] <<")"<< endl
					 <<"ID: "<<palavra [0]<< " / função: " << palavra[1]<<endl 
					 <<"CPF: " <<palavra[3] <<" / idade: " << palavra[4]<<endl
					 <<"Tipo sanguineo: " <<palavra[5] <<" / RH: " <<palavra[6]<< endl
					 <<"especialidade: " << palavra[7] <<" / nivel De Segurança: " <<palavra[8]<<endl;
					 cout <<"-----------------------------" <<endl;
					}
				}
				Ler_B.close();

			}
			else{
				cout << "não foi possivel realizar essa operação" << endl;
			}
			break;
	}
}

/**
* @brief Método que possibilita modificar informações de um animal ou funcionario.
*/

void Programa::Modificar_informacoes()
{
	string tipo;
	int id;
	string teste_id;
	cout << "Qual deseja alterar(Animal/Funcionario): " << endl;
	cin >> tipo;
	for (unsigned int i = 0; i < tipo.length(); ++i)
		tipo[i] = toupper(tipo[i]);
	if (tipo.compare("ANIMAL") == 0)
	{
		do{
			cin >> id;
			teste_id = Verificar_id_animal(id);
			if(teste_id.compare("N/A") != 0)
			{
				Remocao_animal(id);
				Cadastro_animal(id);
			}
			else
			{
				cout << "Id invalido" << endl;
			}
		}while(teste_id.compare("N/A") == 0);
	}
	else if (tipo.compare("FUNCIONARIO") == 0)
	{
		do{
			cin >> id;
			teste_id = Verificar_id_funcionario(id);
			if(teste_id.compare("N/A") != 0)
			{
				Remocao_funcionario(id);
				Cadastro_funcionario(id);
			}
			else
			{
				cout << "Id invalido" << endl;
			}
		}while(teste_id.compare("N/A") == 0);
	}
}

/**
* @brief Método que verifica se a id de um animal existe.
* @param id Numero que representa o ID de um animal.
* @return Rerorna a classe do animal caso ele exista, caso não exista retorna a string N/A.
*/

string Programa::Verificar_id_animal(int id)
{
	map<int, AnfibioExotico>::iterator it1 = anfibios_exoticos.find(id);
	map<int, AnfibioNativo>::iterator it2 = anfibios_nativos.find(id);
	
	map<int, AveExotico>::iterator it3 = aves_exoticas.find(id);
	map<int, AveNativo>::iterator it4 = aves_nativas.find(id);

	map<int, MamiferoExotico>::iterator it5 = mamiferos_exoticos.find(id);
	map<int, MamiferoNativo>::iterator it6 = mamiferos_nativos.find(id);

	map<int, ReptilExotico>::iterator it7 = repteis_exoticos.find(id);
	map<int, ReptilNativo>::iterator it8 = repteis_nativos.find(id);

	if(it1 != anfibios_exoticos.end())
	{
		return "AnfibioExotico";
	}
	else if(it2 != anfibios_nativos.end())
	{
		return "AnfibioNativo";
	}
	else if(it3 != aves_exoticas.end())
	{
		return "AveExotica";
	}
	else if(it4 != aves_nativas.end())
	{
		return "AveNativa";
	}
	else if(it5 != mamiferos_exoticos.end())
	{
		return "MamiferoExotico";
	}
	else if(it6 != mamiferos_nativos.end())
	{
		return "MamiferoNativo";
	}
	else if(it7 != repteis_exoticos.end())
	{
		return "ReptilExotico";
	}
	else if(it8 != repteis_nativos.end())
	{
		return "ReptilNativo";
	}
	
	return "N/A";
}

/**
* @brief Método que verifica se a id de um funcionário existe.
* @param id Numero que representa o ID de um funcionário.
* @return Rerorna a função do funcionário caso ele exista, caso não exista retorna a string N/A.
*/

string Programa::Verificar_id_funcionario(int id)
{
	map<int, Veterinario>::iterator it1 = veterinarios.find(id);
	map<int, Tratador>::iterator it2 = tratadores.find(id);

	if(it1 != veterinarios.end())
	{
		return "Veterinario";
	}
	else if(it2 != tratadores.end())
	{
		return "Tratador";
	}
	return "N/A";
}

/**
* @brief Método que separa as informações de uma linha de um arquivo csv.
* @param data String que representa a linha que vai ter seus dados separados.
* @param dados Vector que recebe as informações da linha.
*/

void Programa::Separador_csv(string data, vector<string> &dados)
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

/**
* @brief Método que separa uma data em dia, mes e ano.
* @param data String que representa a data.
* @param dados Vector que recebe as informações da data.
*/

void Programa::Separador_data(string data, vector<string> &dados)
{
    dados.clear();
    int i = 0;
    string palavras = "";
    for (string::iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it != '/')
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
    dados.push_back(palavras);
}
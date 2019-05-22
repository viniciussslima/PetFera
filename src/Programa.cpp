#include "Programa.h"
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

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
	veterinarios.insert(pair<int, Veterinario>(-1, veterinario0));

	Tratador tratador0;
	tratadores.insert(pair<int, Tratador>(-1, tratador0));
	
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
				map<int, Tratador>::iterator it_tratador;

				if(veterinario_incluso)
				{
					it_veterinario = veterinarios.find(veterinario_id);
				}
				else
				{
					it_veterinario = veterinarios.find(-1);
				}
				
				if (tratador_incluso)
				{
					it_tratador = tratadores.find(tratador_id);
				}
				else
				{
					it_tratador = tratadores.find(-1);
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

void Programa::Cadastro_animal()
{
	int id;
	bool teste_id;
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
	ofstream outfile;

	do{
		cout << "Id: ";
		cin >> id;
		
		map<int, AnfibioExotico>::iterator it1 = anfibios_exoticos.find(id);
		map<int, AnfibioNativo>::iterator it2 = anfibios_nativos.find(id);
		
		map<int, AveExotico>::iterator it3 = aves_exoticas.find(id);
		map<int, AveNativo>::iterator it4 = aves_nativas.find(id);

		map<int, MamiferoExotico>::iterator it5 = mamiferos_exoticos.find(id);
		map<int, MamiferoNativo>::iterator it6 = mamiferos_nativos.find(id);

		map<int, ReptilExotico>::iterator it7 = repteis_exoticos.find(id);
		map<int, ReptilNativo>::iterator it8 = repteis_nativos.find(id);

		it1 != anfibios_exoticos.end() ? teste_id = true : teste_id = false;
		it2 != anfibios_nativos.end() || teste_id == true ? teste_id = true : teste_id = false;
		it3 != aves_exoticas.end() || teste_id == true ? teste_id = true : teste_id = false;
		it4 != aves_nativas.end() || teste_id == true ? teste_id = true : teste_id = false;
		it5 != mamiferos_exoticos.end() || teste_id == true ? teste_id = true : teste_id = false;
		it6 != mamiferos_nativos.end() || teste_id == true ? teste_id = true : teste_id = false;
		it7 != repteis_exoticos.end() || teste_id == true ? teste_id = true : teste_id = false;
		it8 != repteis_nativos.end() || teste_id == true ? teste_id = true : teste_id = false;

		if (teste_id)
		{
			cout << "Id já em uso" << endl;
		}
	}while(teste_id);

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

	cout << "Veterinario incluso(S/N): ";
	cin >> veterinario_incluso;
	veterinario_incluso = toupper(veterinario_incluso);

	cout << "Tratador incluso(S/N): ";
	cin >> tratador_incluso;
	tratador_incluso = toupper(tratador_incluso);

	cout << "Nome batismo: ";
	cin.ignore();
	getline(cin, nome_batismo);
	for (unsigned int i = 0; i < nome_batismo.length(); i++)
	{
		nome_batismo[i] = toupper(nome_batismo[i]);
	}

	cout << "Nacionalidade: ";
	cin.ignore();
	getline(cin, nacionalidade);
	for (unsigned int i = 0; i < nacionalidade.length(); i++)
	{
		nacionalidade[i] = toupper(nacionalidade[i]);
	}

	cout << "Autorizacao ibama: ";
	cin >> autorizacao_ibama;
	for (unsigned int i = 0; i < autorizacao_ibama.length(); i++)
	{
		autorizacao_ibama[i] = toupper(autorizacao_ibama[i]);
	}

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
		it_veterinario = veterinarios.find(-1);
	}

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
		it_tratador = tratadores.find(-1);	
	}

	if(nacionalidade.compare("BRASILEIRO") == 0)
	{
		if (classe.compare("Aves") == 0)
		{
			//AveNativo aveNativo();
		}
	}
	else
	{
		if (classe.compare("AMPHIBIA") == 0)
		{
			int total_de_mudas;
			date ultima_muda;

			cout << "Total de mudas: ";
			cin >> total_de_mudas;

			cout << "Data da ultima muda: ";
			cin >> ultima_muda;

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
	    	map<int, AveNativo>::iterator it = aves_nativas.find(id);
	    	aves_nativas.erase(it);
	    }
	    else
	    {
	    	map<int, AveExotico>::iterator it = aves_exoticas.find(id);
	    	aves_exoticas.erase(it);
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
	int id;
	bool teste_id;
	do{
		cout << "Id: ";
		cin >> id;
		
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
			teste_id = true;
			cout << it1->second << endl;
		}
		else if(it2 != anfibios_nativos.end())
		{
			teste_id = true;
			cout << it2->second << endl;
		}
		else if(it3 != aves_exoticas.end())
		{
			teste_id = true;
			cout << it3->second << endl;
		}
		else if(it4 != aves_nativas.end())
		{
			teste_id = true;
			cout << it4->second << endl;
		}
		else if(it5 != mamiferos_exoticos.end())
		{
			teste_id = true;
			cout << it5->second << endl;
		}
		else if(it6 != mamiferos_nativos.end())
		{
			teste_id = true;
			cout << it6->second << endl;
		}
		else if(it7 != repteis_exoticos.end())
		{
			teste_id = true;
			cout << it7->second << endl;
		}
		else if(it8 != repteis_nativos.end())
		{
			teste_id = true;
			cout << it8->second << endl;
		}
		else
		{
			teste_id = false;
		}

		if (!teste_id)
		{
			cout << "Id invalido" << endl;
		}
	}while(!teste_id); 
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

void Programa::Separador_data(string data, vector<string> &dados)
{
    dados.clear();
    int i = 0;
    string palavras = "";
    for (string::iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it != ' ')
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
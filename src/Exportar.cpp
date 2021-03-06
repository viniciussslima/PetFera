#include "Exportar.h"

using namespace std;

map<int, Animal*> Carregar()
{
	map<int, Funcionario*> funcionarios;
	map<int, Animal*> animais;

	ifstream funcionarios_csv("Dados/funcionarios.csv");
	ifstream animais_csv("Dados/animais.csv");
	//Carregando os dados dos funcionários
	if(funcionarios_csv.is_open())
	{
		string linha;
		vector<string> palavras;

		while(getline(funcionarios_csv, linha))
		{
			palavras = Separador_csv(linha);
			//Carregando algumas das informações do funcionário
			int id = stoi(palavras[0]);
			string funcao = palavras[1];
			string nome = palavras[2];
			string cpf = palavras[3];
			short idade = stoi(palavras[4]);
			string tipo_sanguineo = palavras[5];
			char fator_rh = palavras[6][0];
			string especialidade = palavras[7];
			//Caso for um tratador
			if(funcao.compare("TRATADOR") == 0)
			{
				int nivel_seguranca = stoi(palavras[8]);
				Funcionario *temp = new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, nivel_seguranca);
				funcionarios.insert(pair<int, Funcionario*>(id, temp));
			}
			//Caso for um funcionário
			else
			{
				string crmv = palavras[8];
				Funcionario *temp = new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, crmv);
				funcionarios.insert(pair<int, Funcionario*>(id, temp));
			}
		}
	}
	//Carregando os dados dos animais
	if(animais_csv.is_open())
	{
		string linha;
		vector<string> palavras;

		while(getline(animais_csv, linha))
		{
			palavras = Separador_csv(linha);
			//Carregando algumas das informações do funcionário
			int id = stoi(palavras[0]);
			string classe = palavras[1];
			string nome_cientifico = palavras[2];
			char sexo = palavras[3][0];
			double tamanho = stod(palavras[4]);
			string dieta = palavras[5];
			Veterinario *veterinario = new Veterinario;
			if (stoi(palavras[6]) != 0)
				veterinario = dynamic_cast<Veterinario*>(funcionarios.find(stoi(palavras[6]))->second);
			Tratador *tratador = new Tratador;
			if (stoi(palavras[7]) != 0)
				tratador = dynamic_cast<Tratador*>(funcionarios.find(stoi(palavras[7]))->second);
			string nome_batismo = palavras[8];
			string nacionalidade = palavras[palavras.size() - 1];

			if(classe.compare("AMPHIBIA") == 0)
		    {
		    	int total_mudas = stoi(palavras[9]);
		    	vector<int> data = Separador_data(palavras[10]);
		    	date data_ultima_muda(data[0], data[1], data[2]);
		    	string autorizacao_ibama = palavras[11];
		    	string cidade_de_origem = palavras[12];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new AnfibioNativo(id, classe, nome_cientifico, sexo, tamanho,
									   dieta, *veterinario, *tratador, nome_batismo, 
									   total_mudas, data_ultima_muda, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
			    	Animal *temp = new AnfibioExotico(id, classe, nome_cientifico, sexo, tamanho,
									   dieta, *veterinario, *tratador, nome_batismo, 
									   total_mudas, data_ultima_muda, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		    if(classe.compare("AVES") == 0)
		    {
		    	double tamanho_bico = stod(palavras[9]);
		    	double envergadura_asas = stod(palavras[10]);
		    	string autorizacao_ibama = palavras[11];
		    	string cidade_de_origem = palavras[12];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new AveNativo(id, classe, nome_cientifico, sexo, tamanho,
								   dieta, *veterinario, *tratador, nome_batismo, 
								   tamanho_bico, envergadura_asas, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
					Animal *temp = new AveExotico(id, classe, nome_cientifico, sexo, tamanho,
								    dieta, *veterinario, *tratador, nome_batismo, 
								    tamanho_bico, envergadura_asas, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		    if(classe.compare("MAMMALIA") == 0)
		    {
		    	string cor_pelo = palavras[9];
		    	string autorizacao_ibama = palavras[10];
		    	string cidade_de_origem = palavras[11];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new MamiferoNativo(id, classe, nome_cientifico, sexo, tamanho,
								        dieta, *veterinario, *tratador, nome_batismo, 
								   		cor_pelo, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
			    	Animal *temp = new MamiferoExotico(id, classe, nome_cientifico, sexo, tamanho,
								   		 dieta, *veterinario, *tratador, nome_batismo, 
								   		 cor_pelo, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		    if(classe.compare("REPTILIA") == 0)
		    {
		    	bool venenoso = palavras[9].compare("1") == 0 ? true : false;
		    	string tipo_veneno = palavras[10];
		    	string autorizacao_ibama = palavras[11];
		    	string cidade_de_origem = palavras[12];

				if(nacionalidade.length() == 2)
				{
					Animal *temp = new ReptilNativo(id, classe, nome_cientifico, sexo, tamanho,
								       dieta, *veterinario, *tratador, nome_batismo, 
								       venenoso, tipo_veneno, autorizacao_ibama, nacionalidade);
			    	animais.insert(pair<int, Animal*>(id, temp));
				}
			    else
			    {
			    	Animal *temp = new ReptilExotico(id, classe, nome_cientifico, sexo, tamanho,
								       dieta, *veterinario, *tratador, nome_batismo, 
								       venenoso, tipo_veneno, autorizacao_ibama, nacionalidade, cidade_de_origem);
			    	animais.insert(pair<int, Animal*>(id, temp));
			    }
		    }
		}
	}
	animais_csv.close();
	funcionarios_csv.close();

	return animais;
}

int main(int argc, char const *argv[])
{
	map<int, Animal*> animais_filtrados = Carregar();
	string classe;
	int veterinario_id, tratador_id;
	if (argc == 1)
	{
		cout << "Digite o nome do aquivo para qual vai ser exportatado" << endl;
		return 0;
	}
	for(int i = 1; i < argc - 1; i += 2)
	{
		if(strcmp(argv[i], "-c") == 0)
		{
			if((i+1) >= argc)
			{
				cout << "Digite uma especie após o -c" << endl;
				cout << "Exportação falhou" << endl;
				return 0;
			}
			classe = argv[i + 1];

			for (unsigned int i = 0; i < classe.length(); i++)
				classe[i] = toupper(classe[i]);
			if (classe.compare("AVES") != 0 && classe.compare("MAMMALIA") != 0 &&
				classe.compare("AMPHIBIA") != 0 && classe.compare("REPTILIA") != 0)
			{
				cout << "Digite uma especie após o -c" << endl;
				cout << "Exportação falhou" << endl;
				return 0;
			}

			for(map<int, Animal*>::iterator it = animais_filtrados.begin(); it != animais_filtrados.end(); it++)
			{
				if(it->second->get_classe().compare(classe) != 0)
					animais_filtrados.erase(it);
			}
		}
		else if(strcmp(argv[i], "-v") == 0)
		{
			try
			{
				veterinario_id = stoi(argv[i + 1]);
			}
			catch(exception &ex)
			{
				cerr << "Digite o id de um veterinario após o -v" << endl;
				cerr << "Exportação falhou" << endl;
				return 0;
			}
			for(map<int, Animal*>::iterator it = animais_filtrados.begin(); it != animais_filtrados.end(); it++)
			{
				if(it->second->get_veterinario_id() != veterinario_id)
				{
					animais_filtrados.erase(it);
				}
			}
			if (animais_filtrados.empty())
			{
				cout << "Veterinario não cadastrado" << endl;
				return 0;
			}
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			try
			{
				tratador_id = stoi(argv[i + 1]);
			}
			catch(exception &ex)
			{
				cerr << "Digite o id de um tratador após o -t" << endl;
				cerr << "Exportação falhou" << endl;
				return 0;
			}

			for(map<int, Animal*>::iterator it = animais_filtrados.begin(); it != animais_filtrados.end(); it++)
			{
				if(it->second->get_tratador_id() != tratador_id)
				{
					animais_filtrados.erase(it);
				}
			}

			if (animais_filtrados.empty())
			{
				cout << "Tratador não cadastrado" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Ultilize os parametros:" << endl
				<< "-c para escolher uma classe" << endl
				<< "-v para escolher um veterinario" << endl
				<< "-t para escolher um tratador" << endl;
			return 0;
		}
	}
	if (animais_filtrados.empty())
	{
		cout << "Nenhum animal cadastrado contém as infomações passadas" << endl;
		cout << "Exportação falhou" << endl;
		return 0;
	}
	ofstream output;
	output.open(argv[argc-1]);
	for(map<int, Animal*>::iterator it = animais_filtrados.begin(); it != animais_filtrados.end(); it++)
	{
		output << *(it->second) << endl;
	}
	output.close();
	cout << "A exportação foi bem sucedida" << endl;
	return 0;
}

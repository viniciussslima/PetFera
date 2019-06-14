/**
* @file RemoverFuncionario.cpp
* @brief Função que remove funcionários.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "RemoverFuncionario.h"

using namespace std;

void RemoverFuncionario(JanelaPrincipal &janela_principal, map<int, Funcionario*> &funcionarios, int id)
{

	string linha;
	vector<string> palavras;
	ifstream funcionarios_csv("Dados/funcionarios.csv");
	ofstream funcionarios_temp("Dados/TempFuncionario.csv");
	while(getline(funcionarios_csv, linha))
	{
		palavras = Separador_csv(linha);
		if(stoi(palavras[0]) != id)
			funcionarios_temp << linha << endl;
		else
		{
			if(palavras[1].compare("TRATADOR") == 0)
			{
				funcionarios.erase(id);
				janela_principal.AtualizarLista(0);
			}
			else
			{
				funcionarios.erase(id);
				janela_principal.AtualizarLista(1);
			}
		}
	}
	funcionarios_csv.close();
	remove("Dados/funcionarios.csv");
	rename("Dados/TempFuncionario.csv", "Dados/funcionarios.csv");
	funcionarios_temp.close();
}
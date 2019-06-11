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

void RemoverFuncionario(JanelaPrincipal &janela_principal, map<int, Veterinario> &veterinarios, map<int, 
							Tratador> &tratadores,  int id)
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
				tratadores.erase(id);
				janela_principal.AtualizarLista(0);
			}
			else
			{
				veterinarios.erase(id);
				janela_principal.AtualizarLista(1);
			}
		}
	}
	remove("Dados/funcionarios.csv");
	rename("Dados/TempFuncionario.csv", "Dados/funcionarios.csv");
	funcionarios_temp.close();
}
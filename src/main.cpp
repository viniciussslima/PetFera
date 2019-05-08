#include <iostream>

using namespace std;

void Cadastro_animal(){}
void Remocao_animal(){}
void Cadastro_funcionario(){}
void Remocao_funcionario(){}
void Consultar_animal(){}
void Consultar_funcionario(){}

int main(void)
{
	char escolha;
	bool loop = true;

	while(loop)
	{
		cout << "Digite um numero comrespondente: " << endl  
			<< "[1] Cadastro de um animal" << endl
			<< "[2] Remoção de um animal" << endl
			<< "[3] Cadastro de um funcionario" << endl
			<< "[4] Remoção de um funcionario" << endl
			<< "[5] Consulta de dados de um animal" << endl
			<< "[6] Consulta de dados de funcionario" << endl
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
				cout << "Opção invalida" << endl;
				break;
		}
	}
}
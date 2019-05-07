#include <iostream>

using namespace std;

int main(void)
{
	char escolha;
	bool loop = true;

	cout << "Digite um numero comrespondente: " << endl  
		<< "[1] Cadastro de um animal" << endl
		<< "[2] Remoção de um animal" << endl
		<< "[3] Cadastro de um funcionario" << endl
		<< "[4] Remoção de um funcionario" << endl
		<< "[5] Consulta de dados de um animal" << endl
		<< "[6] Consulta de dados de funcionario"
		<< "[7] Sair" << endl;
	cin >> escolha;
	
	while(loop)
	{
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
				break
			default:
				cout << "Opção invalida" << endl;
				break;
		}
	}
}
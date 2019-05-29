#ifndef _H_PROGRAMA_H_
#define _H_PROGRAMA_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>


#include "Veterinario.h"
#include "Tratador.h"

#include "AnfibioExotico.h"
#include "AnfibioNativo.h"

#include "AveExotico.h"
#include "AveNativo.h"

#include "MamiferoExotico.h"
#include "MamiferoNativo.h"

#include "ReptilExotico.h"
#include "ReptilNativo.h"

#include "date.h"

using namespace std;

class Programa
{
	private:
		map<int, Veterinario> veterinarios;
		map<int, Tratador> tratadores;

		map<int, AnfibioExotico> anfibios_exoticos;
		map<int, AnfibioNativo> anfibios_nativos;

		map<int, AveExotico> aves_exoticas;
		map<int, AveNativo> aves_nativas;

		map<int, MamiferoExotico> mamiferos_exoticos;
		map<int, MamiferoNativo> mamiferos_nativos;

		map<int, ReptilExotico> repteis_exoticos;
		map<int, ReptilNativo> repteis_nativos;

		char escolha;
		bool loop;
	public:
		Programa();
		void Run();
		void Carregar();
		void Cadastro_animal(int id = 0);
		void Remocao_animal(int id = 0);
		void Cadastro_funcionario(int id = 0);
		void Remocao_funcionario(int id = 0);
		void Consultar_animal();
		void Consultar_funcionario();
		void Modificar_informacoes();
		void Separador_csv(string, vector<string>&);
		void Separador_data(string, vector<string> &);
		string Verificar_id_animal(int);
		string Verificar_id_funcionario(int);
};

#endif
#ifndef _H_PROGRAMA_H_
#define _H_PROGRAMA_H_

using namespace std;
#include <map>
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


class Programa:
{
	private:
		map<int, Veterinario> veterinarios;
		map<int, Tratador> tratadores;

		map<int, AnfibioExotico> anfibios_exoticos;
		map<int, AnfibioNativo> anfibios_nativos;

		map<int, AveExotico> aves_exoticos;
		map<int, AveNativo> aves_nativos;

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
		void Cadastro_animal();
		void Remocao_animal();
		void Cadastro_funcionario();
		void Remocao_funcionario();
		void Consultar_animal();
		void Consultar_funcionario();
		void Separador(string, vector<string>&);
};

#endif
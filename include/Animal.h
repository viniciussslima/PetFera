#ifndef  _H_ANIMAL_H_
#define _H_ANIMAL_H_

#include <string>

#include "Veterinario.h"
#include "Tratador.h"

using namespace std;

class Animal
{
	protected:
		int m_id;
		string m_classe;
		string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		string m_dieta;
		Veterinario m_veterinario;
		Tratador m_tratador;
		string m_nome_batismo;
	public:
		Animal();
		Animal(int, string, string, char,
			double, string, Veterinario,
			Tratador, string);
		~Animal();
		int getId();
};

#endif
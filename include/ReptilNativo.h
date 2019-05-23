#ifndef _H_REPTILNATIVO_H_
#define _H_REPTILNATIVO_H_

#include "Reptil.h"
#include "AnimalNativo.h"

using namespace std;

class ReptilNativo : public Reptil, public AnimalNativo
{
	public:
		ReptilNativo();
		ReptilNativo(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, bool, string, string, string);
		~ReptilNativo();
		void Exibir_informacoes();
		friend ostream& operator<<(ostream &, ReptilNativo);
};

#endif
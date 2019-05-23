#ifndef _H_REPTILEXOTICO_H_
#define _H_REPTILEXOTICO_H_

#include "Reptil.h"
#include "AnimalExotico.h"

using namespace std;

class ReptilExotico : public Reptil, public AnimalExotico
{
	public:
		ReptilExotico();
		ReptilExotico(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, bool, string, string, string);
		~ReptilExotico();
		void Exibir_informacoes();
		friend ostream& operator<<(ostream &, ReptilExotico);
};

#endif
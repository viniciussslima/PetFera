#ifndef _H_AVENATIVO_H
#define _H_AVENATIVO_H

#include "Ave.h"
#include "AnimalNativo.h"

using namespace std;

class AveNativo : public Ave, public AnimalNativo
{
	public:
		AveNativo();
		AveNativo(int, string,	string,	char,
			double, string, Veterinario, Tratador ,
			string, double,	double, string, string );
		~AveNativo();
		void Exibir_informacoes();
		friend ostream& operator<<(ostream &, AveNativo);
};

#endif
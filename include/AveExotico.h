#ifndef _H_AVEEXOTICO_H
#define _H_AVEEXOTICO_H

#include "Ave.h"
#include "AnimalExotico.h"

using namespace std;

class AveExotico : public Ave, public AnimalExotico
{
	public:
		AveExotico();
		AveExotico(int, string,	string, char, double,
			string, Veterinario, Tratador, string, int, 
			date, string, string);
		~AveExotico();
		friend ostream& operator<<(ostream &, AveExotico);
};

#endif
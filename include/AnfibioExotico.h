#ifndef _H_ANFIBIOEXOTICO_H_
#define _H_ANFIBIOEXOTICO_H_

#include "Anfibio.h"
#include "AnimalExotico.h"

using namespace std;

class AnfibioExotico : public Anfibio, public AnimalExotico
{
	public:
		AnfibioExotico();
		AnfibioExotico(int, date, string, string);
		~AnfibioExotico();
};

#endif
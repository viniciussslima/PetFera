#ifndef _H_MAMIFERONATIVO_H_
#define _H_MAMIFERONATIVO_H_

#include "Mamifero.h"
#include "AnimalNativo.h"

using namespace std;

class MamiferoNativo : public Mamifero, public AnimalNativo
{
	public:
		MamiferoNativo();
		~MamiferoNativo();
};

#endif
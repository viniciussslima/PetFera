#ifndef _H_ANIMAL_NATIVO_H_
#define _H_ANIMAL_NATIVO_H_

#include "AnimalSilvestre.h"

using namespace std;

class AnimalNativo : public AnimalSilvestre
{
protected:
	string m_uf_origem;
public:
	AnimalNativo();
	AnimalNativo(string, string);
	~AnimalNativo();
	
};

#endif
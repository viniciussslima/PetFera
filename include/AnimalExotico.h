#ifndef _H_ANIMAL_EXOTICO_H_
#define _H_ANIMAL_EXOTICO_H_

#include "AnimalSilvestre.h"

using namespace std;

class AnimalExotico : public AnimalSilvestre
{
	protected:
		string m_pais_origem;
	public:
		AnimalExotico();
		AnimalExotico(string, string);
		~AnimalExotico();
};

#endif
#ifndef _H_ANFIBIO_H_
#define _H_ANFIBIO_H_

#include "date.h"
#include "Animal.h" 

using namespace std;

class Anfibio: public Animal
{
protected:
	int m_total_de_mudas;
	date m_ultima_muda;

public:
	Anfibio();
	~Anfibio();

};

#endif
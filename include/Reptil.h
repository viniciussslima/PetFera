#ifndef _H_REPTIL_H_
#define _H_REPTIL_H_

#include "Animal.h"
#include <string>

using namespace std;

class Reptil: public Animal
{
protected:
	bool m_venenoso;
	string m_tipo_veneno;

public:
	Reptil();
	~Reptil();






}
#endif
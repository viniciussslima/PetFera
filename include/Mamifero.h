#ifndef _H_MAMIFERO_H
#define _H_MAMIFERO_H

#include "Animal.h"
#include <string>

using namespace std;

class Mamifero: public Animal
{
protected:
	string m_cor_pelo;

public:
	Mamifero();
	~Mamifero();






}
#endif
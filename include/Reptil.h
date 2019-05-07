#ifdef REPTIL_H
#define REPTIL_H
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
#ifdef
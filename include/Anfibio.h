#ifdef ANFIBIO_H
#define ANFIBIO_H
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

}
#ifdef
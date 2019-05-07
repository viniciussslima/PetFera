#ifdef AVE_H
#define AVE_H
#include "Animal.h"
using namespace std;

class Ave : public Animal
{
protected:
	int m_total_de_mudas;
	date m_ultima_muda;

public:
	Ave();
	~Ave();
}
#ifdef
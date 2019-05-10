#ifndef _H_AVE_H
#define _H_AVE_H

#include "Animal.h"
#include "date.h"

using namespace std;

class Ave : public Animal
{
	protected:
		int m_total_de_mudas;
		date m_ultima_muda;

	public:
		Ave();
		Ave(int , string, string, char,	double, string,
			Veterinario, Tratador, string, int, date);
		
		~Ave();
};

#endif
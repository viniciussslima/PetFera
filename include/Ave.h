#ifndef _H_AVE_H
#define _H_AVE_H

#include "Animal.h"
#include "date.h"

using namespace std;

class Ave : public Animal
{
	protected:
		double m_tamanho_do_bico;
		double m_evergadura_das_asas;

	public:
		Ave();
		Ave(int , string, string, char,	double, string,
			Veterinario, Tratador, string, double, double);
		
		~Ave();
};

#endif
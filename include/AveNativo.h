/**
* @file AveNativo.h
* @brief Classe que representa aves nativas.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_AVENATIVO_H
#define _H_AVENATIVO_H

#include "Ave.h"
#include "AnimalNativo.h"

using namespace std;

class AveNativo : public Ave, public AnimalNativo
{
	public:
		AveNativo();
		AveNativo(int, string,	string,	char,
			double, string, Veterinario, Tratador ,
			string, double,	double, string, string );
		~AveNativo();
		friend ostream& operator<<(ostream &, AveNativo);
};

#endif
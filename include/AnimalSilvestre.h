#ifndef _H_ANIMAL_SILVESTRE_H_
#define _H_ANIMAL_SILVESTRE_H_

#include <string>

using namespace std;

class AnimalSilvestre
{
	protected:
		string m_autorizacao_ibama;
	public:
		AnimalSilvestre();
		AnimalSilvestre(string);
		~AnimalSilvestre();
};

#endif
#ifndef _H_REPTILNATIVO_H_
#define _H_REPTILNATIVO_H_

#include "Reptil.h"
#include "AnimalNativo.h"

using namespace std;

class ReptilNativo : public Reptil, public AnimalNativo
{
	public:
		ReptilNativo();
		~ReptilNativo();
};

#endif
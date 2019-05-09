#ifndef _H_REPTILEXOTICO_H_
#define _H_REPTILEXOTICO_H_

#include "Reptil.h"
#include "AnimalExotico.h"

using namespace std;

class ReptilExotico : public Reptil, public AnimalExotico
{
	public:
		ReptilExotico();
		~ReptilExotico();
};

#endif
#ifndef _H_AVEEXOTICO_H
#define _H_AVEEXOTICO_H

#include "Ave.h"
#include "AnimalExotico.h"

using namespace std;

class AveExotico : public Ave, public AnimalExotico
{
	public:
		AveExotico();
		~AveExotico();
};

#endif
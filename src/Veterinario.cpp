#include "Funcionario.h"
#include "Veterinario.h"

using namespace std;

class Veterinario : public Funcionario
{
	private:
		string m_cmv;
	public:
		Veterinario();
		~Veterinario();
	
};

#include "Funcionario.h"
#include "Tratador.h"

using namespace std;

class Tratador : public Funcionario
{
	private:
		int m_nivel_de_seguranca;
	public:
		Tratador();
		~Tratador();
	
};
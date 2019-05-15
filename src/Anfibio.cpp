#include "Anfibio.h"

using namespace std;

Anfibio::Anfibio(){}

Anfibio::Anfibio(int new_total_de_mudas, date new_ultima_muda)
{
	m_total_de_mudas = new_total_de_mudas;
	m_ultima_muda = new_ultima_muda;
}

Anfibio::~Anfibio(){}
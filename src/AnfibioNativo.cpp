#include "AnfibioNativo.h"

AnfibioNativo::AnfibioNativo(){}

AnfibioNativo::AnfibioNativo(int new_total_de_mudas,
	date new_ultima_muda, string new_autorizacao_ibama,
	string new_uf_origem):
	Anfibio(new_total_de_mudas, new_ultima_muda),
	AnimalNativo(new_autorizacao_ibama,
	new_uf_origem){}

AnfibioNativo::~AnfibioNativo()
{
	
}
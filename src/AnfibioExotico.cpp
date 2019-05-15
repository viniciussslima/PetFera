#include "AnfibioExotico.h"

AnfibioExotico::AnfibioExotico(){}

AnfibioExotico::AnfibioExotico(int new_total_de_mudas,
	date new_ultima_muda, string new_autorizacao_ibama, 
	string new_pais_origem):
		Anfibio(new_total_de_mudas, new_ultima_muda),
		AnimalExotico(new_autorizacao_ibama, 
			new_pais_origem){}

AnfibioExotico::~AnfibioExotico(){}
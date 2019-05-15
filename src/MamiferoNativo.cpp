#include "MamiferoNativo.h"

MamiferoNativo::MamiferoNativo(){}

MamiferoNativo::MamiferoNativo(int new_id, string new_classe,
	string new_nome_cientifico,	char new_sexo,
	double new_tamanho,	string new_dieta,
	Veterinario new_veterinario, Tratador new_tratador,
	string new_nome_batismo, string new_cor_pelo,
	string new_autorizacao_ibama, string new_uf_origem):
		Mamifero(new_id, new_classe, new_nome_cientifico,
			new_sexo, new_tamanho, new_dieta,
			new_veterinario, new_tratador,
			new_nome_batismo, new_cor_pelo),
		AnimalNativo(new_autorizacao_ibama,
			new_uf_origem){}

MamiferoNativo::~MamiferoNativo(){}
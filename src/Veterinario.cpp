#include "Funcionario.h"
#include "Veterinario.h"

using namespace std;

Veterinario::Veterinario(){}

Veterinario::Veterinario(int new_id, string new_nome, string new_cpf,
	short new_idade, short new_tipo_sanguineo, char new_fator_rh,
	string new_especialidade, int new_cmv):
	Funcionario(new_id, new_nome, new_cpf,
		new_idade, new_tipo_sanguineo, new_fator_rh, m_especialidade)
{
	m_cmv = new_cmv;
}

Veterinario::~Veterinario(){}

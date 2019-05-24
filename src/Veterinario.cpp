#include "Funcionario.h"
#include "Veterinario.h"

using namespace std;

Veterinario::Veterinario(){}

Veterinario::Veterinario(int new_id, string new_nome, string new_cpf,
	short new_idade, string new_tipo_sanguineo, char new_fator_rh,
	string new_especialidade, string new_crmv):
	Funcionario(new_id, new_nome, new_cpf,
		new_idade, new_tipo_sanguineo,
		new_fator_rh, new_especialidade)
{
	m_cmv = new_crmv;
}

Veterinario::~Veterinario(){}

void Veterinario::Exibir_Veterinario(){
	cout << endl
		<< "Id: " << m_id << endl
		<< "Função: Veterinario" << endl
		<< "Nome: " << m_nome << endl
		<< "CPF: " << m_cpf << endl
		<< "Idade: " << m_idade << endl
		<< "Tipo Sanguineo: " << m_tipo_sanguineo << endl
		<< "RH: " << m_fator_rh << endl
		<<"Especialidade: " << m_especialidade << endl
		<<"CRMV: " << m_cmv << endl;

}

ostream& operator<<(ostream &o, Veterinario A)
{
	o << A.m_id << ";"
		<< "VETERINARIO" << ";"
		<< A.m_nome << ";"
		<< A.m_cpf << ";"
		<< A.m_idade << ";"
		<< A.m_tipo_sanguineo << ";"
		<< A.m_fator_rh << ";"
		<< A.m_especialidade << ";"
		<< A.m_cmv << ";";
	return o;
}

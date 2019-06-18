/**
* @file Tratador.h
* @brief Classe que representa tratadores.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_TRATADOR_H_
#define _H_TRATADOR_H_

#include <string>

#include "Funcionario.h"

using namespace std;

class Tratador : public Funcionario
{
	private:
		int m_nivel_de_seguranca;
		ostream& print(ostream& os) const 
		{
			return os << m_id << ";"
						<< "TRATADOR" << ";"
						<< m_nome << ";"
						<< m_cpf << ";"
						<< m_idade << ";"
						<< m_tipo_sanguineo << ";"
						<< m_fator_rh << ";"
						<< m_especialidade << ";"
						<< m_nivel_de_seguranca << ";";
		}
	public:
		Tratador(int, string, string,
	short, string, char,	string, int);
		Tratador();
		~Tratador();
		int get_nivel_de_seguranca();
		friend ostream& operator<<(ostream &, Tratador);
};

#endif
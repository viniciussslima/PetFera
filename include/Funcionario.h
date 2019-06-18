
/**
* @file Funcionario.h
* @brief Classe que representa funcionários.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_FUNCIONARIO_H
#define _H_FUNCIONARIO_H

#include <iostream>
#include <string>

using namespace std;

class Funcionario
{
	private:
		virtual ostream& print(ostream&) const = 0;
	protected:
		int m_id;
		string m_nome;
		string m_cpf;
		short m_idade;
		string m_tipo_sanguineo;
		char m_fator_rh;
		string m_especialidade;
	public:
		Funcionario();
		Funcionario(int, string, string,
			short, string, char, string);
		virtual ~Funcionario() = 0;
		int get_id() const;
		string get_nome();
		string get_cpf();
		short get_idade();
		string get_tipo_sanguineo();
		char get_rh();
		string get_especialidade();
		friend ostream& operator << (ostream& os, const Funcionario& b) {return b.print(os);}
};

#endif
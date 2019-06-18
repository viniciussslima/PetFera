/**
* @file AveNativo.h
* @brief Classe que representa aves nativas.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lim
*/

#ifndef _H_AVENATIVO_H
#define _H_AVENATIVO_H

#include "Ave.h"
#include "AnimalNativo.h"

using namespace std;

class AveNativo : public Ave, public AnimalNativo
{
	private:
		ostream& print(ostream& os) const 
		{
			return os << m_id << ";"
						<< m_classe << ";"
						<< m_nome_cientifico << ";"
						<< m_sexo << ";"
						<< m_tamanho << ";"
						<< m_dieta << ";"
						<< m_veterinario.get_id() << ";"
						<< m_tratador.get_id() << ";"
						<< m_nome_batismo << ";"
						<< m_tamanho_do_bico << ";"
						<< m_evergadura_das_asas << ";"
						<< m_autorizacao_ibama << ";"
						<< m_uf_origem << ";";
		}
	public:
		AveNativo();
		AveNativo(int, string,	string,	char,
			double, string, Veterinario, Tratador ,
			string, double,	double, string, string );
		~AveNativo();
};

#endif
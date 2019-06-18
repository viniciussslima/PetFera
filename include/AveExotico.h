/**
* @file AveExotico.h
* @brief Classe que representa aves exóticas.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lim
*/

#ifndef _H_AVEEXOTICO_H
#define _H_AVEEXOTICO_H

#include "Ave.h"
#include "AnimalExotico.h"

using namespace std;

class AveExotico : public Ave, public AnimalExotico
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
						<< m_cidade_origem << ";"
						<< m_pais_origem << ";";
		}
	public:
		AveExotico();
		AveExotico(int, string,	string, char, double,
			string, Veterinario, Tratador, string, double, 
			double, string, string, string);
		~AveExotico();
};

#endif
/**
* @file AnfibioNativo.h
* @brief Classe que representa anfibíos nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lim
*/

#ifndef _H_ANFIBIONATIVO_H_
#define _H_ANFIBIONATIVO_H_

#include "Anfibio.h"
#include "AnimalNativo.h"

using namespace std;

class AnfibioNativo : public Anfibio, public AnimalNativo
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
						<< m_total_de_mudas << ";"
						<< m_ultima_muda << ";"
						<< m_autorizacao_ibama << ";"
						<< m_uf_origem << ";";
		}
	public:
		AnfibioNativo();
		AnfibioNativo(int, string, string, char,
			double, string,	Veterinario, Tratador,
			string, int, date, string, string);
		~AnfibioNativo();
};

#endif
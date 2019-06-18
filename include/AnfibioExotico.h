/**
* @file AnfibioExotico.h
* @brief Classe que representa anfibíos exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lim
*/

#ifndef _H_ANFIBIOEXOTICO_H_
#define _H_ANFIBIOEXOTICO_H_

#include "Anfibio.h"
#include "AnimalExotico.h"

using namespace std;

class AnfibioExotico : public Anfibio, public AnimalExotico
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
						<< m_cidade_origem << ";"
						<< m_pais_origem << ";";
		}
	public:
		AnfibioExotico();
		AnfibioExotico(int, string, string, char,
			double, string, Veterinario,
			Tratador, string, int,
			date, string, string, string);
		~AnfibioExotico();
};

#endif
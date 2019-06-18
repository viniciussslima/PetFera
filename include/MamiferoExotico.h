/**
* @file MamiferoExotico.h
* @brief Classe que representa mamíferos exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_MAMIFEROEXOTICO_H_
#define _H_MAMIFEROEXOTICO_H_

#include "Mamifero.h"
#include "AnimalExotico.h"

using namespace std;

class MamiferoExotico : public Mamifero, public AnimalExotico
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
						<< m_cor_pelo << ";"
						<< m_autorizacao_ibama << ";"
						<< m_cidade_origem << ";"
						<< m_pais_origem << ";";
		}
	public:
		MamiferoExotico();
		MamiferoExotico(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, string, string, string, string);
		~MamiferoExotico();
};

#endif
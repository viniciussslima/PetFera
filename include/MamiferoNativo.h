/**
* @file MamiferoNativo.h
* @brief Classe que representa mamíferos nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_MAMIFERONATIVO_H_
#define _H_MAMIFERONATIVO_H_

#include "Mamifero.h"
#include "AnimalNativo.h"

using namespace std;

class MamiferoNativo : public Mamifero, public AnimalNativo
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
						<< m_uf_origem << ";";
		}
	public:
		MamiferoNativo();
		MamiferoNativo(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, string, string, string);
		~MamiferoNativo();
};

#endif
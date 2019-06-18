/**
* @file ReptilNativo.h
* @brief Classe que representa répteis nativos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_REPTILNATIVO_H_
#define _H_REPTILNATIVO_H_

#include "Reptil.h"
#include "AnimalNativo.h"

using namespace std;

class ReptilNativo : public Reptil, public AnimalNativo
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
						<< m_venenoso << ";"
						<< m_tipo_veneno << ";"
						<< m_autorizacao_ibama << ";"
						<< m_uf_origem << ";";
		}
	public:
		ReptilNativo();
		ReptilNativo(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, bool, string, string, string);
		~ReptilNativo();
};

#endif
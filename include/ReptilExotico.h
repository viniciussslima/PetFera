/**
* @file ReptilExotico.h
* @brief Classe que representa répeteis exóticos.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#ifndef _H_REPTILEXOTICO_H_
#define _H_REPTILEXOTICO_H_

#include "Reptil.h"
#include "AnimalExotico.h"

using namespace std;

class ReptilExotico : public Reptil, public AnimalExotico
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
						<< m_cidade_origem << ";"
						<< m_pais_origem << ";";
		}
	public:
		ReptilExotico();
		ReptilExotico(int, string, string, char,
			double, string, Veterinario, Tratador,
			string, bool, string, string, string, string);
		~ReptilExotico();
};

#endif
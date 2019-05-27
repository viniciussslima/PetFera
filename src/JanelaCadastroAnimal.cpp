#include <fstream>
#include <string>
#include "JanelaCadastroAnimal.h"

using namespace Gtk;
using namespace std;

JanelaCadastroAnimal::JanelaCadastroAnimal(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp, map<int, AnfibioExotico> &anetemp, 
										   map<int, AnfibioNativo> &anntemp, map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp,
										   map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, 
										   map<int, ReptilExotico> &retemp, map<int, ReptilNativo> &rntemp)
{
	valid_id = false;

	janela_principal = &jptemp;

	veterinarios = &vtemp;
	tratadores = &ttemp;

	anfibios_exoticos = &anetemp;
	anfibios_nativos = &anntemp;

	aves_exoticas = &avetemp;
	aves_nativas = &avntemp;

	mamiferos_exoticos = &metemp;
	mamiferos_nativos = &mntemp;

	repteis_exoticos = &retemp;
	repteis_nativos = &rntemp;

	Veterinario veterinario;
	Tratador tratador;

	//Inicialização
	window = new Window;

	button_cadastrar = new Button("Cadastrar");

	entry_id = new Entry;
	entry_nome_cientifico = new Entry;
	entry_tamanho = new Entry;
	entry_dieta = new Entry;
	entry_nome_batismo = new Entry;
	entry_nacionalidade = new Entry;
	entry_uf = new Entry;
	entry_veterinario_id = new Entry;
	entry_tratador_id = new Entry;
	entry_autorizacao_ibama = new Entry;

	combo_box_classe = new ComboBoxText;
	combo_box_sexo = new ComboBoxText;
	combo_box_regiao = new ComboBoxText;

	check_button_veterinario_incluso = new CheckButton;
	check_button_tratador_incluso = new CheckButton;

	entry_total_de_mudas = new Entry;
	entry_data_da_ultima_muda = new Entry;
	entry_tamanho_do_bico = new Entry;
	entry_envergadura_das_asas = new Entry;
	entry_cor_dos_pelos = new Entry;
	check_button_venenoso = new CheckButton;
	entry_tipo_de_veneno = new Entry;

	box_principal = new VBox;
	box_dados = new HBox;
	box_esquerda = new VBox(true);
	box_direita = new VBox(true);

	label_id = new Label("ID: ");
	label_classe = new Label("Classe: ");
	label_nome_cientifico = new Label("Nome Científico: ");
	label_sexo = new Label("Sexo: ");
	label_tamanho = new Label("Tamanho: ");
	label_dieta = new Label("Dieta: ");
	label_veterinario_incluso = new Label("Veterinário Incluso?");
	label_veterinario_id = new Label("ID do Veterinário: ");
	label_tratador_incluso = new Label("Tratador Incluso?");
	label_tratador_id = new Label("ID do Tratador: ");
	label_nome_batismo = new Label("Nome de Batismo: ");
	label_total_de_mudas = new Label("Total de Mudas: ");
	label_data_da_ultima_muda = new Label("Data da Ultima Muda: ");
	label_tamanho_do_bico = new Label("Tamanho do Bico: ");
	label_envergadura_das_asas = new Label("Envergadura das Asas: ");
	label_cor_dos_pelos = new Label("Cor dos Pelos: ");
	label_venenoso = new Label("Venenoso?");
	label_tipo_de_veneno = new Label("Tipo de Veneno: ");
	label_autorizacao_do_ibama = new Label("Autorização do Ibama: ");
	label_regiao = new Label("Região: ");
	label_nacionalidade = new Label("Nacionalidade: ");
	label_uf = new Label("Estado: ");

	//Configuração
	window->set_title("Cadastrar Animal");
	window->add(*box_principal);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);

	combo_box_classe->append("Amphibia");
	combo_box_classe->append("Aves");
	combo_box_classe->append("Mammalia");
	combo_box_classe->append("Reptilia");
	combo_box_classe->set_active(0);

	combo_box_sexo->append("Masculino");
	combo_box_sexo->append("Feminino");
	combo_box_sexo->set_active(0);

	combo_box_regiao->append("Brasileiro");
	combo_box_regiao->append("Outra Nacionalidade");
	combo_box_regiao->set_active(0);

	box_principal->add(*box_dados);
	box_principal->pack_start(*button_cadastrar, PACK_SHRINK);
	box_dados->add(*box_esquerda);
	box_dados->add(*box_direita);

	box_esquerda->add(*label_id);
	box_esquerda->add(*label_classe);
	box_esquerda->add(*label_nome_cientifico);
	box_esquerda->add(*label_sexo);
	box_esquerda->add(*label_tamanho);
	box_esquerda->add(*label_dieta);
	box_esquerda->add(*label_veterinario_incluso);
	box_esquerda->add(*label_veterinario_id);
	box_esquerda->add(*label_tratador_incluso);
	box_esquerda->add(*label_tratador_id);
	box_esquerda->add(*label_nome_batismo);
	box_esquerda->add(*label_total_de_mudas);
	box_esquerda->add(*label_data_da_ultima_muda);
	box_esquerda->add(*label_tamanho_do_bico);
	box_esquerda->add(*label_envergadura_das_asas);
	box_esquerda->add(*label_cor_dos_pelos);
	box_esquerda->add(*label_venenoso);
	box_esquerda->add(*label_tipo_de_veneno);

	box_esquerda->add(*label_autorizacao_do_ibama);
	box_esquerda->add(*label_regiao);
	box_esquerda->add(*label_nacionalidade);
	box_esquerda->add(*label_uf);
	
	box_direita->add(*entry_id);
	box_direita->add(*combo_box_classe);
	box_direita->add(*entry_nome_cientifico);
	box_direita->add(*combo_box_sexo);
	box_direita->add(*entry_tamanho);
	box_direita->add(*entry_dieta);
	box_direita->add(*check_button_veterinario_incluso);
	box_direita->add(*entry_veterinario_id);
	box_direita->add(*check_button_tratador_incluso);
	box_direita->add(*entry_tratador_id);
	box_direita->add(*entry_nome_batismo);
	box_direita->add(*entry_total_de_mudas);
	box_direita->add(*entry_data_da_ultima_muda);
	box_direita->add(*entry_tamanho_do_bico);
	box_direita->add(*entry_envergadura_das_asas);
	box_direita->add(*entry_cor_dos_pelos);
	box_direita->add(*check_button_venenoso);
	box_direita->add(*entry_tipo_de_veneno);

	box_direita->add(*entry_autorizacao_ibama);
	box_direita->add(*combo_box_regiao);
	box_direita->add(*entry_nacionalidade);
	box_direita->add(*entry_uf);

	//Conexão
	button_cadastrar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::Cadastrar));
	combo_box_classe->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MudarClasse));
	combo_box_regiao->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MudarRegiao));
	check_button_veterinario_incluso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MostrarVeterinario));
	check_button_tratador_incluso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MostrarTratador));
	check_button_venenoso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MostrarVenenoso));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeId));
	entry_tratador_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeTratadorId));
	entry_veterinario_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeVeterinarioId));
}

JanelaCadastroAnimal::~JanelaCadastroAnimal()
{
	delete window;
	delete entry_id;
	delete entry_nome_cientifico;
	delete entry_tamanho;
	delete entry_dieta;
	delete entry_nome_batismo;
	delete combo_box_regiao;
	delete combo_box_classe;
	delete check_button_veterinario_incluso;
	delete check_button_tratador_incluso;
	delete button_cadastrar;
	delete box_principal;
	delete box_dados;
	delete box_esquerda;
	delete box_direita;
	delete label_id;
	delete label_classe;
	delete label_nome_cientifico;
	delete label_sexo;
	delete label_tamanho;
	delete label_dieta;
	delete label_veterinario_incluso;
	delete label_tratador_incluso;
	delete label_nome_batismo;
	delete label_regiao;
}

void JanelaCadastroAnimal::Run()
{
	window->show_all();
	entry_veterinario_id->hide();
	label_veterinario_id->hide();
	entry_tratador_id->hide();
	label_tratador_id->hide();
	entry_nacionalidade->hide();
	label_nacionalidade->hide();
	entry_tamanho_do_bico->hide();
	label_tamanho_do_bico->hide();
	entry_envergadura_das_asas->hide();
	label_envergadura_das_asas->hide();
	entry_cor_dos_pelos->hide();
	label_cor_dos_pelos->hide();
	check_button_venenoso->hide();
	label_venenoso->hide();
	entry_tipo_de_veneno->hide();
	label_tipo_de_veneno->hide();
	Main::run(*window);
}

void JanelaCadastroAnimal::Cadastrar()
{
	bool valid_dados = false;

	if(!check_button_tratador_incluso->get_active())
		valid_tratador_id = true;
	if(!check_button_veterinario_incluso->get_active())
		valid_veterinario_id = true;

	if(!entry_id->get_text().empty() && !entry_tamanho->get_text().empty() &&
	   !entry_dieta->get_text().empty() && !entry_nome_batismo->get_text().empty() &&
	   !entry_autorizacao_ibama->get_text().empty())
	{
		switch(combo_box_classe->get_active_row_number())
		{
			case 0:
			{
				//anfibio
				if(!entry_total_de_mudas->get_text().empty() && !entry_data_da_ultima_muda->get_text().empty())
				{
					switch(combo_box_regiao->get_active_row_number())
					{
						case 0:
						{
							if(!entry_uf->get_text().empty())
								valid_dados = true;
							break;
						}
						case 1:
						{
							if(!entry_nacionalidade->get_text().empty())
								valid_dados = true;
							break;
						}
					}
				}
				break;
			}
			case 1:
			{
				//aves
				if(!entry_tamanho_do_bico->get_text().empty() && !entry_envergadura_das_asas->get_text().empty())
				{
					switch(combo_box_regiao->get_active_row_number())
					{
						case 0:
						{
							if(!entry_uf->get_text().empty())
								valid_dados = true;
							break;
						}
						case 1:
						{
							if(!entry_nacionalidade->get_text().empty())
								valid_dados = true;
							break;
						}
					}
				}
				break;
			}
			case 2:
			{
				//mamifero
				if(!entry_cor_dos_pelos->get_text().empty())
				{
					switch(combo_box_regiao->get_active_row_number())
					{
						case 0:
						{
							if(!entry_uf->get_text().empty())
								valid_dados = true;
							break;
						}
						case 1:
						{
							if(!entry_nacionalidade->get_text().empty())
								valid_dados = true;
							break;
						}
					}
				}
				break;
			}
			case 3:
			{
				//reptil
				if(check_button_venenoso->get_active() ? !entry_tipo_de_veneno->get_text().empty() : true)
				{
					switch(combo_box_regiao->get_active_row_number())
					{
						case 0:
						{
							if(!entry_uf->get_text().empty())
								valid_dados = true;
							break;
						}
						case 1:
						{
							if(!entry_nacionalidade->get_text().empty())
								valid_dados = true;
							break;
						}
					}
				}
				break;
			}
		}
	}

	

	if(valid_id && valid_tratador_id && valid_veterinario_id && valid_dados)
	{
		ofstream outfile;
		outfile.open("Dados/animais.csv", ios::app);
		int id = stoi(entry_id->get_text());
		string classe = combo_box_classe->get_active_text(); 
		for(unsigned int i = 0; i < classe.length(); i++)
			classe[i] = toupper(classe[i]);
		string nome_cientifico = entry_nome_cientifico->get_text();
		char sexo = combo_box_sexo->get_active_text()[0];
		double tamanho = stod(entry_tamanho->get_text());
		string dieta = entry_dieta->get_text();
		Veterinario veterinario = check_button_veterinario_incluso->get_active() ? (veterinarios->find(id))->second : veterinarios->begin()->second;
		Tratador tratador = check_button_tratador_incluso->get_active() ? (tratadores->find(id))->second : tratadores->begin()->second;
		string nome_batismo = entry_nome_batismo->get_text();
		string autorizacao_ibama = entry_autorizacao_ibama->get_text();
		string nacionalidade = combo_box_regiao->get_active_row_number() == 0 ? entry_uf->get_text() : entry_nacionalidade->get_text();

		switch(combo_box_classe->get_active_row_number())
		{
			case 0:
			{
				//anfibio
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						vector<int> data;
						string data_string = entry_data_da_ultima_muda->get_text();
						data = Separador_data(data_string);
						date data_date(data[0], data[1], data[2]);

						AnfibioNativo temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, stoi(entry_total_de_mudas->get_text()), 
							data_date, autorizacao_ibama, nacionalidade);

						outfile << temp << endl;
						anfibios_nativos->insert(pair<int, AnfibioNativo>(id, temp));
						//janela_principal->AtualizarLista(2);
						break;
					}
					case 1:
					{
						vector<int> data;
						string data_string = entry_data_da_ultima_muda->get_text();
						data = Separador_data(data_string);
						date data_date(data[0], data[1], data[2]);

						AnfibioExotico temp(id, classe, nome_cientifico, sexo,
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, stoi(entry_total_de_mudas->get_text()),
							data_date, autorizacao_ibama, nacionalidade);

						outfile << temp << endl;
						anfibios_exoticos->insert(pair<int, AnfibioExotico>(id, temp));
						//janela_principal->AtualizarLista(3);
						break;
					}
				}
				break;
			}
			case 1:
			{
				//aves
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						AveNativo temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, stod(entry_tamanho_do_bico->get_text()), 
							stod(entry_envergadura_das_asas->get_text()), 
							autorizacao_ibama, nacionalidade);

						outfile << temp << endl;
						aves_nativas->insert(pair<int, AveNativo>(id, temp));
						//janela_principal->AtualizarLista(4);
						break;
					}
					case 1:
					{
						AveExotico temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, stod(entry_tamanho_do_bico->get_text()), 
							stod(entry_envergadura_das_asas->get_text()), 
							autorizacao_ibama, nacionalidade);

						outfile << temp << endl;
						aves_exoticas->insert(pair<int, AveExotico>(id, temp));
						//janela_principal->AtualizarLista(5);
						break;
					}
				}
				break;
			}
			case 2:
			{
				//mamifero
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						MamiferoNativo temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, entry_cor_dos_pelos->get_text(), 
							autorizacao_ibama, nacionalidade);

						outfile << temp << endl;
						mamiferos_nativos->insert(pair<int, MamiferoNativo>(id, temp));
						//janela_principal->AtualizarLista(6);
						break;
					}
					case 1:
					{
						MamiferoExotico temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, entry_cor_dos_pelos->get_text(), 
							autorizacao_ibama, nacionalidade);

						outfile << temp << endl;
						mamiferos_exoticos->insert(pair<int, MamiferoExotico>(id, temp));
						//janela_principal->AtualizarLista(7);
						break;
					}
				}
				break;
			}
			case 3:
			{
				//reptil
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						ReptilNativo temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, 
							nome_batismo, check_button_venenoso->get_active(), 
							entry_tipo_de_veneno->get_text(), autorizacao_ibama, 
							nacionalidade);

						outfile << temp << endl;
						repteis_nativos->insert(pair<int, ReptilNativo>(id, temp));
						//janela_principal->AtualizarLista(8);
						break;
					}
					case 1:
					{
						ReptilExotico temp(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, veterinario, tratador, nome_batismo, 
							check_button_venenoso->get_active(), 
							entry_tipo_de_veneno->get_text(), autorizacao_ibama, 
							nacionalidade);

						outfile << temp << endl;
						repteis_exoticos->insert(pair<int, ReptilExotico>(id, temp));
						//janela_principal->AtualizarLista(9);
						break;
					}
				}
				break;
			}
		}
	}

	if(!valid_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi encontrado um animal com o ID apresentado, animais não podem ter IDs iguais.");
  		dialog.run();
	}	
	if(!valid_tratador_id)
	{
		MessageDialog dialog(*window, "ID do tratador inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou não foi encontrado um tratador com o ID apresentado");
  		dialog.run();
	}
	if(!valid_veterinario_id)
	{
		MessageDialog dialog(*window, "ID do veterinário inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou não foi encontrado um veterinário com o ID apresentado");
  		dialog.run();
	}
	if(!valid_dados)
	{
		MessageDialog dialog(*window, "Dado(s) inválido(s).");
		dialog.set_secondary_text("Falta preencher um ou mais dados.");
  		dialog.run();
	}
	
	window->close();
}

/*
	entry_total_de_mudas = new Entry;
	entry_data_da_ultima_muda = new Entry;
	entry_tamanho_do_bico = new Entry;
	entry_envergadura_das_asas = new Entry;
	entry_cor_dos_pelos = new Entry;
	check_button_venenoso new CheckButton;
	entry_tipo_de_veneno = new Entry;
	*/

void JanelaCadastroAnimal::MudarClasse()
{
	switch(combo_box_classe->get_active_row_number())
	{
		case 0:
			entry_total_de_mudas->show();
			label_total_de_mudas->show();
			entry_data_da_ultima_muda->show();
			label_data_da_ultima_muda->show();
			entry_tamanho_do_bico->hide();
			label_tamanho_do_bico->hide();
			entry_envergadura_das_asas->hide();
			label_envergadura_das_asas->hide();
			entry_cor_dos_pelos->hide();
			label_cor_dos_pelos->hide();
			check_button_venenoso->hide();
			label_venenoso->hide();
			entry_tipo_de_veneno->hide();
			label_tipo_de_veneno->hide();
			AtualizarIconeId();
			break;
		case 1:
			entry_total_de_mudas->hide();
			label_total_de_mudas->hide();
			entry_data_da_ultima_muda->hide();
			label_data_da_ultima_muda->hide();
			entry_tamanho_do_bico->show();
			label_tamanho_do_bico->show();
			entry_envergadura_das_asas->show();
			label_envergadura_das_asas->show();
			label_cor_dos_pelos->hide();
			check_button_venenoso->hide();
			label_venenoso->hide();
			entry_tipo_de_veneno->hide();
			label_tipo_de_veneno->hide();
			AtualizarIconeId();
			break;
		case 2:
			entry_total_de_mudas->hide();
			label_total_de_mudas->hide();
			entry_data_da_ultima_muda->hide();
			label_data_da_ultima_muda->hide();
			entry_tamanho_do_bico->hide();
			label_tamanho_do_bico->hide();
			entry_envergadura_das_asas->hide();
			label_envergadura_das_asas->hide();
			entry_cor_dos_pelos->show();
			label_cor_dos_pelos->show();
			check_button_venenoso->hide();
			label_venenoso->hide();
			entry_tipo_de_veneno->hide();
			label_tipo_de_veneno->hide();
			AtualizarIconeId();
			break;
		case 3:
			entry_total_de_mudas->hide();
			label_total_de_mudas->hide();
			entry_data_da_ultima_muda->hide();
			label_data_da_ultima_muda->hide();
			entry_tamanho_do_bico->hide();
			label_tamanho_do_bico->hide();
			entry_envergadura_das_asas->hide();
			label_envergadura_das_asas->hide();
			entry_cor_dos_pelos->hide();
			label_cor_dos_pelos->hide();
			check_button_venenoso->show();
			label_venenoso->show();
			entry_tipo_de_veneno->hide();
			label_tipo_de_veneno->hide();
			AtualizarIconeId();
			break;
	}
}

void JanelaCadastroAnimal::MudarRegiao()
{
	switch(combo_box_regiao->get_active_row_number())
	{
		case 0:
			entry_uf->show();
			label_uf->show();
			entry_nacionalidade->hide();
			label_nacionalidade->hide();
			AtualizarIconeId();
			break;
		case 1:
			entry_uf->hide();
			label_uf->hide();
			entry_nacionalidade->show();
			label_nacionalidade->show();
			AtualizarIconeId();
			break;
	}
}

void JanelaCadastroAnimal::MostrarVeterinario()
{
	if(!check_button_veterinario_incluso->get_active())
	{
		entry_veterinario_id->hide();
		label_veterinario_id->hide();
	}
	else
	{
		entry_veterinario_id->show();
		label_veterinario_id->show();
	}
}

void JanelaCadastroAnimal::MostrarTratador()
{
	if(!check_button_tratador_incluso->get_active())
	{
		entry_tratador_id->hide();
		label_tratador_id->hide();
	}
	else
	{
		entry_tratador_id->show();
		label_tratador_id->show();
	}
}

void JanelaCadastroAnimal::MostrarVenenoso()
{
	if(!check_button_venenoso->get_active())
	{
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
	}
	else
	{
		entry_tipo_de_veneno->show();
		label_tipo_de_veneno->show();
	}
}

void JanelaCadastroAnimal::AtualizarIconeId()
{
	string temp = entry_id->get_text();
	bool is_numeric = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false;
			break;
		}
	}
	if(is_numeric && !temp.empty())
	{
		int id = stoi(temp);

		map<int, AnfibioNativo>::iterator it_an_n = anfibios_nativos->find(id);
		map<int, AnfibioExotico>::iterator it_an_e = anfibios_exoticos->find(id);
		map<int, AveNativo>::iterator it_av_n = aves_nativas->find(id);
		map<int, AveExotico>::iterator it_av_e = aves_exoticas->find(id);
		map<int, MamiferoNativo>::iterator it_m_n = mamiferos_nativos->find(id);
		map<int, MamiferoExotico>::iterator it_m_e = mamiferos_exoticos->find(id);
		map<int, ReptilNativo>::iterator it_r_n = repteis_nativos->find(id);
		map<int, ReptilExotico>::iterator it_r_e = repteis_exoticos->find(id);

		if(it_an_n != anfibios_nativos->end() || it_an_e != anfibios_exoticos->end() ||
		   it_av_n != aves_nativas->end() || it_av_e != aves_exoticas->end() ||
		   it_m_n != mamiferos_nativos->end() || it_m_e != mamiferos_exoticos->end() ||
		   it_r_n != repteis_nativos->end() || it_r_e != repteis_exoticos->end())
		{
			valid_id = false;
			entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		}
		else
		{
			valid_id = true;
			entry_id->set_icon_from_pixbuf(pixbuf_check);
		}
	}
	else
	{
		valid_id = false;
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	}
}

void JanelaCadastroAnimal::AtualizarIconeTratadorId()
{
	string temp = entry_tratador_id->get_text();
	bool is_numeric = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false;
			break;
		}
	}
	if(is_numeric && !temp.empty())
	{
		int id = stoi(temp);
		map<int, Tratador>::iterator it_t = tratadores->find(id);

		if(it_t != tratadores->end())
		{
			valid_tratador_id = true;
			entry_tratador_id->set_icon_from_pixbuf(pixbuf_check);
		}
		else
		{
			valid_tratador_id = false;
			entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
		}
	}
	else
	{
		valid_tratador_id = false;
		entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
	}
}

void JanelaCadastroAnimal::AtualizarIconeVeterinarioId()
{
	string temp = entry_veterinario_id->get_text();
	bool is_numeric = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false;
			break;
		}
	}
	if(is_numeric && !temp.empty())
	{
		int id = stoi(temp);
		map<int, Veterinario>::iterator it_t = veterinarios->find(id);

		if(it_t != veterinarios->end())
		{
			valid_veterinario_id = true;
			entry_veterinario_id->set_icon_from_pixbuf(pixbuf_check);
		}
		else
		{
			valid_veterinario_id = false;
			entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
		}
	}
	else
	{
		valid_veterinario_id = false;
		entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
	}
}
#include <fstream>
#include <string>
#include <exception> 
#include "JanelaCadastroAnimal.h"

using namespace Gtk;
using namespace std;

JanelaCadastroAnimal::JanelaCadastroAnimal(JanelaPrincipal &jptemp, map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp, map<int, AnfibioExotico> &anetemp, 
										   map<int, AnfibioNativo> &anntemp, map<int, AveExotico> &avetemp, map<int, AveNativo> &avntemp,
										   map<int, MamiferoExotico> &metemp, map<int, MamiferoNativo> &mntemp, 
										   map<int, ReptilExotico> &retemp, map<int, ReptilNativo> &rntemp)
{
	valid_id = false;
	valid_nome_cientifico = false;
	valid_tamanho = false;
	valid_dieta = false;
	valid_tratador_id = true;
	valid_veterinario_id = true;
	valid_nome_batismo = false;
	valid_autorizacao_ibama = false;
	valid_nacionalidade = true;
	valid_total_de_mudas = false;
	valid_data_da_ultima_muda = false;
	valid_tamanho_do_bico = true;
	valid_envergadura_das_asas = true;
	valid_cor_dos_pelos = true;
	valid_tipo_veneno = true;

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
	entry_veterinario_id = new Entry;
	entry_tratador_id = new Entry;
	entry_autorizacao_ibama = new Entry;

	combo_box_uf = new ComboBoxText;
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
	window->set_resizable(false);
	window->add(*box_principal);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_id->set_icon_tooltip_text("ID inválido");
	entry_nome_cientifico->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_tamanho->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_dieta->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_veterinario_id->set_icon_tooltip_text("ID inválido");
	entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_tratador_id->set_icon_tooltip_text("ID inválido");
	entry_nome_batismo->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_autorizacao_ibama->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_nacionalidade->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_uncheck);
	entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_uncheck);

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

	combo_box_uf->set_wrap_width(27);

	combo_box_uf->append("AC");
	combo_box_uf->append("AL");
	combo_box_uf->append("AP");
	combo_box_uf->append("AM");
	combo_box_uf->append("BA");
	combo_box_uf->append("CE");
	combo_box_uf->append("DF");
	combo_box_uf->append("ES");
	combo_box_uf->append("GO");
	combo_box_uf->append("MA");
	combo_box_uf->append("MT");
	combo_box_uf->append("MS");
	combo_box_uf->append("MG");
	combo_box_uf->append("PA");
	combo_box_uf->append("PB");
	combo_box_uf->append("PR");
	combo_box_uf->append("PE");
	combo_box_uf->append("PI");
	combo_box_uf->append("RJ");
	combo_box_uf->append("RN");
	combo_box_uf->append("RS");
	combo_box_uf->append("RO");
	combo_box_uf->append("RR");
	combo_box_uf->append("SC");
	combo_box_uf->append("SP");
	combo_box_uf->append("SE");
	combo_box_uf->append("TO");
	combo_box_uf->set_active(0);



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
	
	box_direita->pack_start(*entry_id, PACK_SHRINK);
	box_direita->pack_start(*combo_box_classe, PACK_SHRINK);
	box_direita->pack_start(*entry_nome_cientifico, PACK_SHRINK);
	box_direita->pack_start(*combo_box_sexo, PACK_SHRINK);
	box_direita->pack_start(*entry_tamanho, PACK_SHRINK);
	box_direita->pack_start(*entry_dieta, PACK_SHRINK);
	box_direita->pack_start(*check_button_veterinario_incluso, PACK_SHRINK);
	box_direita->pack_start(*entry_veterinario_id, PACK_SHRINK);
	box_direita->pack_start(*check_button_tratador_incluso, PACK_SHRINK);
	box_direita->pack_start(*entry_tratador_id, PACK_SHRINK);
	box_direita->pack_start(*entry_nome_batismo, PACK_SHRINK);
	box_direita->pack_start(*entry_total_de_mudas, PACK_SHRINK);
	box_direita->pack_start(*entry_data_da_ultima_muda, PACK_SHRINK);
	box_direita->pack_start(*entry_tamanho_do_bico, PACK_SHRINK);
	box_direita->pack_start(*entry_envergadura_das_asas, PACK_SHRINK);
	box_direita->pack_start(*entry_cor_dos_pelos, PACK_SHRINK);
	box_direita->pack_start(*check_button_venenoso, PACK_SHRINK);
	box_direita->pack_start(*entry_tipo_de_veneno, PACK_SHRINK);

	box_direita->pack_start(*entry_autorizacao_ibama, PACK_SHRINK);
	box_direita->pack_start(*combo_box_regiao, PACK_SHRINK);
	box_direita->pack_start(*entry_nacionalidade, PACK_SHRINK);
	box_direita->pack_start(*combo_box_uf, PACK_SHRINK);

	//Conexão
	button_cadastrar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::Cadastrar));
	combo_box_classe->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MudarClasse));
	combo_box_regiao->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MudarRegiao));
	check_button_veterinario_incluso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MostrarVeterinario));
	check_button_tratador_incluso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MostrarTratador));
	check_button_venenoso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::MostrarVenenoso));
	entry_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeId));
	entry_nome_cientifico->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeNomeCientifico));
	entry_tamanho->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeTamanho));
	entry_dieta->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeDieta));
	entry_tratador_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeTratadorId));
	entry_veterinario_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeVeterinarioId));
	entry_nome_batismo->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeNomeBatismo));
	entry_autorizacao_ibama->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeAutorizacaoIbama));
	entry_nacionalidade->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeNacionalidade));
	entry_total_de_mudas->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeTotalDeMudas));
	entry_data_da_ultima_muda->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeDataDaUltimaMuda));
	entry_tamanho_do_bico->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeTamanhoDoBico));
	entry_envergadura_das_asas->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeEnvergaduraDasAsas));
	entry_cor_dos_pelos->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeCorDosPelos));
	entry_tipo_de_veneno->signal_changed().connect(sigc::mem_fun(*this, &JanelaCadastroAnimal::AtualizarIconeTipoDeVeneno));
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
	if (!valid_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi encontrado um animal com o ID apresentado, animais não podem ter IDs iguais.");
  		dialog.run();
	}
	else if (!valid_nome_cientifico)
	{
		MessageDialog dialog(*window, "Nome inválido.");
		dialog.set_secondary_text("Falta preencher o nome científico do animal.");
  		dialog.run();
	}
	else if (!valid_tamanho)
	{
		MessageDialog dialog(*window, "Tamanho inválida.");
		dialog.set_secondary_text("Falta preencher ou o tamanho é menor ou igual a 0.");
  		dialog.run();
	}
	else if (!valid_dieta)
	{
		MessageDialog dialog(*window, "Dieta inválido.");
		dialog.set_secondary_text("Falta preencher a dieta do animal.");
  		dialog.run();
	}
	else if (!valid_tratador_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi encontrado um funcionário com o ID apresentado, funcionários não podem ter IDs iguais.");
  		dialog.run();
	}
	else if (!valid_veterinario_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi encontrado um funcionário com o ID apresentado, funcionários não podem ter IDs iguais.");
  		dialog.run();
	}
	else if (!valid_nome_batismo)
	{
		MessageDialog dialog(*window, "Nome inválido.");
		dialog.set_secondary_text("Falta preencher o nome de batismo do animal.");
  		dialog.run();
	}
	else if (!valid_total_de_mudas)
	{
		MessageDialog dialog(*window, "Total de mudas inválida.");
		dialog.set_secondary_text("Falta preencher ou o valor digitado é menor que 0.");
  		dialog.run();
	}
	else if (!valid_data_da_ultima_muda)
	{
		MessageDialog dialog(*window, "Data inválida.");
		dialog.set_secondary_text("Falta preencher ou a data é inexistente.");
  		dialog.run();
	}
	else if (!valid_tamanho_do_bico)
	{
		MessageDialog dialog(*window, "Tamanho do bico inválido.");
		dialog.set_secondary_text("Falta preencher ou o tamanho do bico é menor ou igual a 0.");
  		dialog.run();
	}
	else if (!valid_envergadura_das_asas)
	{
		MessageDialog dialog(*window, "Envergadura das asas inválida.");
		dialog.set_secondary_text("Falta preencher ou a envergadura das asas é menor ou igual a 0.");
  		dialog.run();
	}
	else if (!valid_cor_dos_pelos)
	{
		MessageDialog dialog(*window, "Cor dos pelos inválido.");
		dialog.set_secondary_text("Falta preencher a cor dos pelos do animal.");
  		dialog.run();
	}
	else if (!valid_tipo_veneno)
	{
		MessageDialog dialog(*window, "Tipo de veneno inválido.");
		dialog.set_secondary_text("Falta preencher o tipo de veneno do animal.");
  		dialog.run();
	}
	else if (!valid_autorizacao_ibama)
	{
		MessageDialog dialog(*window, "Autorização do ibama inválida.");
		dialog.set_secondary_text("Falta preencher a autorização do ibama do animal.");
  		dialog.run();
	}
	else if	(!valid_nacionalidade)
	{
		MessageDialog dialog(*window, "Nacionalidade inválida.");
		dialog.set_secondary_text("Falta preencher a nacionalidade do animal.");
  		dialog.run();
	}
	
	else
	{
		int id = stoi(entry_id->get_text());
		string classe = combo_box_classe->get_active_text(); 
		for(unsigned int i = 0; i < classe.length(); i++)
			classe[i] = toupper(classe[i]);
		string nome_cientifico = entry_nome_cientifico->get_text();
		char sexo = combo_box_sexo->get_active_text()[0];
		double tamanho = stod(entry_tamanho->get_text());
		string dieta = entry_dieta->get_text();
		Veterinario veterinario = check_button_veterinario_incluso->get_active() ? (veterinarios->find(stoi(entry_veterinario_id->get_text())))->second : Veterinario();
		Tratador tratador = check_button_tratador_incluso->get_active() ? (tratadores->find(stoi(entry_tratador_id->get_text())))->second : Tratador();
		string nome_batismo = entry_nome_batismo->get_text();
		string autorizacao_ibama = entry_autorizacao_ibama->get_text();
		string nacionalidade = combo_box_regiao->get_active_row_number() == 0 ? combo_box_uf->get_active_text() : entry_nacionalidade->get_text();

		ofstream outfile;
		outfile.open("Dados/animais.csv", ios::app);

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
						janela_principal->AtualizarLista(2);
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
						janela_principal->AtualizarLista(3);
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
						janela_principal->AtualizarLista(4);
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
						janela_principal->AtualizarLista(5);
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
						janela_principal->AtualizarLista(6);
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
						janela_principal->AtualizarLista(7);
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
						janela_principal->AtualizarLista(8);
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
						janela_principal->AtualizarLista(9);
						break;
					}
				}
				break;
			}
		}
	window->close();
	}
}

void JanelaCadastroAnimal::MudarClasse()
{
	switch(combo_box_classe->get_active_row_number())
	{
		case 0:
			valid_total_de_mudas = false;
			valid_data_da_ultima_muda = false;
			valid_tamanho_do_bico = true;
			valid_envergadura_das_asas = true;
			valid_cor_dos_pelos = true;
			valid_tipo_veneno = true;

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
			valid_tamanho_do_bico = false;
			valid_envergadura_das_asas = false;
			valid_total_de_mudas = true;
			valid_data_da_ultima_muda = true;
			valid_cor_dos_pelos = true;
			valid_tipo_veneno = true;

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
			valid_cor_dos_pelos = false;
			valid_total_de_mudas = true;
			valid_data_da_ultima_muda = true;
			valid_tamanho_do_bico = true;
			valid_envergadura_das_asas = true;
			valid_tipo_veneno = true;

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
			valid_tipo_veneno = false;
			valid_total_de_mudas = true;
			valid_data_da_ultima_muda = true;
			valid_tamanho_do_bico = true;
			valid_envergadura_das_asas = true;
			valid_cor_dos_pelos = true;

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
			valid_nacionalidade = true;
			combo_box_uf->show();
			label_uf->show();
			entry_nacionalidade->hide();
			label_nacionalidade->hide();
			AtualizarIconeId();
			break;
		case 1:
			valid_nacionalidade = false;
			combo_box_uf->hide();
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
		valid_veterinario_id = true;
		entry_veterinario_id->hide();
		label_veterinario_id->hide();
	}
	else
	{
		valid_veterinario_id = false;
		entry_veterinario_id->show();
		label_veterinario_id->show();
	}
}

void JanelaCadastroAnimal::MostrarTratador()
{
	if(!check_button_tratador_incluso->get_active())
	{
		valid_tratador_id = true;
		entry_tratador_id->hide();
		label_tratador_id->hide();
	}
	else
	{
		valid_tratador_id = false;
		entry_tratador_id->show();
		label_tratador_id->show();
	}
}

void JanelaCadastroAnimal::MostrarVenenoso()
{
	if(!check_button_venenoso->get_active())
	{
		valid_tipo_veneno = true;
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
	}
	else
	{
		valid_tipo_veneno = false;
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
			entry_id->set_icon_tooltip_text("Algum outro animal já possui esse ID");
		}
		else
		{
			valid_id = true;
			entry_id->set_icon_from_pixbuf(pixbuf_check);
			entry_id->set_icon_tooltip_text("ID válido");
		}
	}
	else
	{
		valid_id = false;
		entry_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_id->set_icon_tooltip_text("ID inválido");
	}
}

void JanelaCadastroAnimal::AtualizarIconeNomeCientifico()
{
	string temp = entry_nome_cientifico->get_text();
	if(temp.empty())
	{
		valid_nome_cientifico = false;
		entry_nome_cientifico->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_nome_cientifico = true;
		entry_nome_cientifico->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeTamanho()
{
	string entry_text = entry_tamanho->get_text();
	double temp;
	bool is_numeric = true;

	for(unsigned int i = 0; i < entry_text.length(); i++)
	{
		if(!isdigit(entry_text[i]))
		{
			is_numeric = false;
			break;
		}
	}

	try
	{
		temp = stod(entry_text);
	}
	catch(exception &ex)
	{
		valid_tamanho = false;
		entry_tamanho->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tamanho->set_icon_tooltip_text("Tamanho inválido");
		return;
	}	
	if(temp > 0 && is_numeric)
	{
		valid_tamanho = true;
		entry_tamanho->set_icon_from_pixbuf(pixbuf_check);
	}
	else
	{
		valid_tamanho = false;
		entry_tamanho->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tamanho->set_icon_tooltip_text("O tamanho tem que ser maior que 0 e ter somente numeros");
	}
}

void JanelaCadastroAnimal::AtualizarIconeDieta()
{
	string temp = entry_dieta->get_text();
	if(temp.empty())
	{
			valid_dieta = false;
			entry_dieta->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_dieta = true;
		entry_dieta->set_icon_from_pixbuf(pixbuf_check);
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
			entry_tratador_id->set_icon_tooltip_text("ID válido");
		}
		else
		{
			valid_tratador_id = false;
			entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_tratador_id->set_icon_tooltip_text("Nenhum tratador possui esse ID");
		}
	}
	else
	{
		valid_tratador_id = false;
		entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tratador_id->set_icon_tooltip_text("ID inválido");
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
			entry_veterinario_id->set_icon_tooltip_text("ID válido");
		}
		else
		{
			valid_veterinario_id = false;
			entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_veterinario_id->set_icon_tooltip_text("Nenhum veterinário possui esse ID");
		}
	}
	else
	{
		valid_veterinario_id = false;
		entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_veterinario_id->set_icon_tooltip_text("ID inválido");
	}
}

void JanelaCadastroAnimal::AtualizarIconeNomeBatismo()
{
	string temp = entry_nome_batismo->get_text();
	if(temp.empty())
	{
			valid_nome_batismo = false;
			entry_nome_batismo->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_nome_batismo = true;
		entry_nome_batismo->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeAutorizacaoIbama()
{
	string temp = entry_autorizacao_ibama->get_text();
	if(temp.empty())
	{
			valid_autorizacao_ibama = false;
			entry_autorizacao_ibama->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_autorizacao_ibama = true;
		entry_autorizacao_ibama->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeNacionalidade()
{
	string temp = entry_nacionalidade->get_text();
	if(temp.empty())
	{
			valid_nacionalidade = false;
			entry_nacionalidade->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_nacionalidade = true;
		entry_nacionalidade->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeTotalDeMudas()
{
	int temp;
	try
	{
		temp = stoi(entry_total_de_mudas->get_text());
	}
	catch(exception &ex)
	{
		valid_total_de_mudas = false;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_total_de_mudas->set_icon_tooltip_text("Quantidade Inválida");
		return;
	}
	if (temp < 0)
	{
		valid_total_de_mudas = false;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_total_de_mudas->set_icon_tooltip_text("Quantidade Inválida");
	}
	else
	{
		valid_total_de_mudas = true;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeDataDaUltimaMuda()
{
	string temp1;
	vector <int> data;
	date data_da_ultima_muda;
	try
	{
		temp1 = entry_data_da_ultima_muda->get_text();
		data = Separador_data(temp1);
		date temp2(data[0], data[1], data[2]);
		data_da_ultima_muda = temp2;
	}
	catch(exception &ex)
	{
		valid_data_da_ultima_muda = false;
		entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_data_da_ultima_muda->set_icon_tooltip_text("Data Inválida");
		return;
	}
	if (data_da_ultima_muda.valid())
	{
		valid_data_da_ultima_muda = true;
		entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_check);
	}
	else
	{
		valid_data_da_ultima_muda = false;
		entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_data_da_ultima_muda->set_icon_tooltip_text("Data Inválida");
	}
}

void JanelaCadastroAnimal::AtualizarIconeTamanhoDoBico()
{
	double temp;
	try
	{
		temp = stod(entry_tamanho_do_bico->get_text());
	}
	catch(exception &ex)
	{
		valid_tamanho_do_bico = false;
		entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tamanho_do_bico->set_icon_tooltip_text("Tamanho inválido");
		return;
	}	
	if(temp <= 0)
	{
			valid_tamanho_do_bico = false;
			entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_tamanho_do_bico->set_icon_tooltip_text("O tamanho tem que ser maior que 0");
	}
	else
	{
		valid_tamanho_do_bico = true;
		entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeEnvergaduraDasAsas()
{
	double temp;
	try
	{
		temp = stod(entry_envergadura_das_asas->get_text());
	}
	catch(exception &ex)
	{
		valid_envergadura_das_asas = false;
		entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_envergadura_das_asas->set_icon_tooltip_text("Tamanho inválido");
		return;
	}	
	if(temp <= 0)
	{
			valid_envergadura_das_asas = false;
			entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_envergadura_das_asas->set_icon_tooltip_text("O tamanho tem que ser maior que 0");
	}
	else
	{
		valid_envergadura_das_asas = true;
		entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeCorDosPelos()
{
	string temp = entry_cor_dos_pelos->get_text();
	if(temp.empty())
	{
			valid_cor_dos_pelos = false;
			entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_cor_dos_pelos = true;
		entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_check);
	}
}

void JanelaCadastroAnimal::AtualizarIconeTipoDeVeneno()
{
	string temp = entry_tipo_de_veneno->get_text();
	if(temp.empty())
	{
			valid_tipo_veneno = false;
			entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else
	{
		valid_tipo_veneno = true;
		entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_check);
	}
}
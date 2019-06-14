/**
* @file JanelaEditarAnimal.cpp
* @brief Implementação da classe JanelaEditarAnimal. 
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include "JanelaEditarAnimal.h"

using namespace Gtk;
using namespace std;

/**
* @brief Construtor padrão da classe JanelaEditarAnimal.
*/

JanelaEditarAnimal::JanelaEditarAnimal(){}

/**
* @brief construtor parametrizado da classe JanelaEditarAnimal.
* @param jptemp Janela principal do programa.
* @param funtemp  Map que contém todos os funcinários cadastrados.
* @param anitemp Map que contém todos os animais cadastrados.
*/

JanelaEditarAnimal::JanelaEditarAnimal(JanelaPrincipal &jptemp, map<int, Funcionario*> &funtemp, map<int, Animal*> &anitemp, int pagtemp, int idtemp)
{
	// Atribuição de true para todas as variáveis boleanas que representão 
	// se as informações digitados sobre o funcionário são validas ou não.
	valid_nome_cientifico = true;
	valid_tamanho = true;
	valid_dieta = true;
	valid_tratador_id = true;
	valid_veterinario_id = true;
	valid_nome_batismo = true;
	valid_autorizacao_ibama = true;
	valid_nacionalidade = true;
	valid_cidade = true;
	valid_total_de_mudas = true;
	valid_data_da_ultima_muda = true;
	valid_tamanho_do_bico = true;
	valid_envergadura_das_asas = true;
	valid_cor_dos_pelos = true;
	valid_tipo_veneno = true;

	// Atribui os endereços de memória dos maps recebidos como parâmetros para os maps da classe JanelaEditarAnimal.
	janela_principal = &jptemp;

	funcionarios = &funtemp;
	animais = &anitemp;

	// Atribui os valores de pagtemp e idtemp para os atributos pagina e id da classe JanelaBuscaAnimais.
	pagina = pagtemp;
	id = idtemp;

	// Inicialização dos atributos da classe GTK.
	window = new Window;

	button_editar = new Button("Editar");

	entry_nome_cientifico = new Entry;
	entry_tamanho = new Entry;
	entry_dieta = new Entry;
	entry_nome_batismo = new Entry;
	entry_nacionalidade = new Entry;
	entry_veterinario_id = new Entry;
	entry_tratador_id = new Entry;
	entry_autorizacao_ibama = new Entry;
	entry_cidade = new Entry;

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
	label_id_numero = new Label(to_string(id));
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
	label_cidade = new Label("Cidade: ");

	// Configuração dos atributos da classe GTK.
	window->set_title("Editar Animal");
	window->set_resizable(false);
	window->add(*box_principal);
	window->set_transient_for(*janela_principal->window);

	pixbuf_check = Gdk::Pixbuf::create_from_file("icons/check.ico");
	pixbuf_uncheck = Gdk::Pixbuf::create_from_file("icons/uncheck.ico");

	entry_nome_cientifico->set_icon_from_pixbuf(pixbuf_check);
	entry_tamanho->set_icon_from_pixbuf(pixbuf_check);
	entry_dieta->set_icon_from_pixbuf(pixbuf_check);
	entry_veterinario_id->set_icon_from_pixbuf(pixbuf_check);
	entry_veterinario_id->set_icon_tooltip_text("ID válido");
	entry_tratador_id->set_icon_from_pixbuf(pixbuf_check);
	entry_tratador_id->set_icon_tooltip_text("ID válido");
	entry_nome_batismo->set_icon_from_pixbuf(pixbuf_check);
	entry_autorizacao_ibama->set_icon_from_pixbuf(pixbuf_check);
	entry_nacionalidade->set_icon_from_pixbuf(pixbuf_check);
	entry_cidade->set_icon_from_pixbuf(pixbuf_check);
	entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_check);
	entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_check);
	entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_check);
	entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_check);
	entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_check);
	entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_check);

	combo_box_classe->append("Amphibia");
	combo_box_classe->append("Aves");
	combo_box_classe->append("Mammalia");
	combo_box_classe->append("Reptilia");

	combo_box_sexo->append("Masculino");
	combo_box_sexo->append("Feminino");

	combo_box_regiao->append("Brasileiro");
	combo_box_regiao->append("Outra Nacionalidade");

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
	box_principal->pack_start(*button_editar, PACK_SHRINK);
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
	box_esquerda->add(*label_cidade);
	
	box_direita->pack_start(*label_id_numero, PACK_SHRINK);
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
	box_direita->pack_start(*entry_cidade, PACK_SHRINK);

	SetInformacooes();

	// Conexões dos atributos da classe GTK.
	button_editar->signal_clicked().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::Editar));
	combo_box_classe->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::MudarClasse));
	combo_box_regiao->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::MudarRegiao));
	check_button_veterinario_incluso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::MostrarVeterinario));
	check_button_tratador_incluso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::MostrarTratador));
	check_button_venenoso->signal_clicked().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::MostrarVenenoso));
	entry_nome_cientifico->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeNomeCientifico));
	entry_tamanho->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeTamanho));
	entry_dieta->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeDieta));
	entry_tratador_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeTratadorId));
	entry_veterinario_id->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeVeterinarioId));
	entry_nome_batismo->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeNomeBatismo));
	entry_autorizacao_ibama->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeAutorizacaoIbama));
	entry_nacionalidade->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeNacionalidade));
	entry_cidade->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeCidade));
	entry_total_de_mudas->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeTotalDeMudas));
	entry_data_da_ultima_muda->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeDataDaUltimaMuda));
	entry_tamanho_do_bico->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeTamanhoDoBico));
	entry_envergadura_das_asas->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeEnvergaduraDasAsas));
	entry_cor_dos_pelos->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeCorDosPelos));
	entry_tipo_de_veneno->signal_changed().connect(sigc::mem_fun(*this, &JanelaEditarAnimal::AtualizarIconeTipoDeVeneno));
}

/**
* @brief Destrutor da classe JanelaEditarAnimal.
*/

JanelaEditarAnimal::~JanelaEditarAnimal()
{
	delete window;
	delete entry_nome_cientifico;
	delete entry_tamanho;
	delete entry_dieta;
	delete entry_nome_batismo;
	delete entry_nacionalidade;
	delete entry_veterinario_id;
	delete entry_tratador_id;
	delete entry_autorizacao_ibama;
	delete entry_total_de_mudas;
	delete entry_data_da_ultima_muda;
	delete entry_tamanho_do_bico;
	delete entry_envergadura_das_asas;
	delete entry_cor_dos_pelos;
	delete entry_tipo_de_veneno;
	delete combo_box_uf;
	delete combo_box_classe;
	delete combo_box_sexo;
	delete combo_box_regiao;
	delete check_button_veterinario_incluso;
	delete check_button_tratador_incluso;
	delete button_editar;
	delete box_principal;
	delete box_dados;
	delete box_esquerda;
	delete box_direita;
	delete label_id;
	delete label_id_numero;
	delete label_classe;
	delete label_nome_cientifico;
	delete label_sexo;
	delete label_tamanho;
	delete label_dieta;
	delete label_veterinario_incluso;
	delete label_veterinario_id;
	delete label_tratador_incluso;
	delete label_tratador_id;
	delete label_nome_batismo;
	delete label_total_de_mudas;
	delete label_data_da_ultima_muda;
	delete label_tamanho_do_bico;
	delete label_envergadura_das_asas;
	delete label_cor_dos_pelos;
	delete label_venenoso;
	delete label_tipo_de_veneno;
	delete label_autorizacao_do_ibama;
	delete label_regiao;
	delete label_nacionalidade;
	delete label_uf;
}

/**
* @brief Método que inicia a janela de edição de animais.
*/

void JanelaEditarAnimal::Run()
{
	Main::run(*window);
}

/**
* @brief Método que escolhe os widgets que vão aparece e escreve as informações do animal nesse widgets 
* de acordo com o tipo de animal escolhido.
*/

void JanelaEditarAnimal::SetInformacooes()
{
	window->show_all();

	string data_da_ultima_muda;
	string uf;
	bool venenoso;

	map <int, Animal*>::iterator it = animais->find(id);

	entry_nome_cientifico->set_text((it->second).get_nome_cientifico());
	
	if ((it->second).get_sexo() == 'M')
		combo_box_sexo->set_active(0);
	else
		combo_box_sexo->set_active(1);

	entry_tamanho->set_text(to_string((it->second).get_tamanho()));

	entry_dieta->set_text((it->second).get_dieta());

	int id_veterinario = (it->second).get_veterinario_id(); 
	if (id_veterinario != 0)
	{
		check_button_veterinario_incluso->set_active(true);
		entry_veterinario_id->set_text(to_string(id_veterinario));
		MostrarVeterinario();
		valid_veterinario_id = true;
	}
	else
	{
		MostrarVeterinario();
		entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);

	}

	int id_tratador = (it->second).get_tratador_id();
	if (id_tratador != 0)
	{
		check_button_tratador_incluso->set_active(true);
		entry_tratador_id->set_text(to_string(id_tratador));
		MostrarTratador();
		valid_tratador_id = true;
	}
	else
	{
		entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
		MostrarTratador();
	}

	entry_nome_batismo->set_text((it->second).get_nome_de_batismo());

	entry_autorizacao_ibama->set_text((it->second).get_autorizacao_ibama());

	if (pagina % 2 == 0)
	{
		combo_box_regiao->set_active(0);
		MudarRegiao();

		uf = (it->second).get_uf_de_origem();
		if (uf.compare("AC") == 0)
			combo_box_uf->set_active(0);
		else if (uf.compare("AL") == 0)
			combo_box_uf->set_active(1);
		else if (uf.compare("AP") == 0)
			combo_box_uf->set_active(2);
		else if (uf.compare("AM") == 0)
			combo_box_uf->set_active(3);
		else if (uf.compare("BA") == 0)
			combo_box_uf->set_active(4);
		else if (uf.compare("CE") == 0)
			combo_box_uf->set_active(5);
		else if (uf.compare("DF") == 0)
			combo_box_uf->set_active(6);
		else if (uf.compare("ES") == 0)
			combo_box_uf->set_active(7);
		else if (uf.compare("GO") == 0)
			combo_box_uf->set_active(8);
		else if (uf.compare("MA") == 0)
			combo_box_uf->set_active(9);
		else if (uf.compare("MT") == 0)
			combo_box_uf->set_active(10);
		else if (uf.compare("MS") == 0)
			combo_box_uf->set_active(11);
		else if (uf.compare("MG") == 0)
			combo_box_uf->set_active(12);
		else if (uf.compare("PA") == 0)
			combo_box_uf->set_active(13);
		else if (uf.compare("PB") == 0)
			combo_box_uf->set_active(14);
		else if (uf.compare("PR") == 0)
			combo_box_uf->set_active(15);
		else if (uf.compare("PE") == 0)
			combo_box_uf->set_active(16);
		else if (uf.compare("PI") == 0)
			combo_box_uf->set_active(17);
		else if (uf.compare("RJ") == 0)
			combo_box_uf->set_active(18);
		else if (uf.compare("RN") == 0)
			combo_box_uf->set_active(19);
		else if (uf.compare("RS") == 0)
			combo_box_uf->set_active(20);
		else if (uf.compare("RO") == 0)
			combo_box_uf->set_active(21);
		else if (uf.compare("RR") == 0)
			combo_box_uf->set_active(22);
		else if (uf.compare("SC") == 0)
			combo_box_uf->set_active(23);
		else if (uf.compare("SP") == 0)
			combo_box_uf->set_active(24);
		else if (uf.compare("SE") == 0)
			combo_box_uf->set_active(25);
		else if (uf.compare("TO") == 0)
			combo_box_uf->set_active(26);
	}
	else
	{
		entry_nacionalidade->set_text((it->second).get_pais_de_origem());

		entry_cidade->set_text((it->second).get_cidade_de_origem());
	}

	if (pagina == 2) // Se a pagina é igual a 2, o animal escolhido é um anfíbio nativo.
	{
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
		
		combo_box_classe->set_active(0);

		entry_total_de_mudas->set_text(to_string((it->second).get_total_de_mudas()));

		data_da_ultima_muda = (it->second).get_data_da_ultima_muda();
		
		if (data_da_ultima_muda.compare("Sem data") == 0)
			entry_data_da_ultima_muda->hide();
		else
			entry_data_da_ultima_muda->set_text(data_da_ultima_muda);
	}
	else if (pagina == 3) // Se a pagina é igual a 3, o animal escolhido é um anfibío exótico.
	{
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
				
		combo_box_classe->set_active(0);

		entry_total_de_mudas->set_text(to_string((it->second).get_total_de_mudas()));

		data_da_ultima_muda = (it->second).get_data_da_ultima_muda();
		
		if (data_da_ultima_muda.compare("Sem data") == 0)
			entry_data_da_ultima_muda->hide();
		else
			entry_data_da_ultima_muda->set_text(data_da_ultima_muda);

		combo_box_regiao->set_active(1);
		MudarRegiao();
		valid_nacionalidade = true;
	}
	else if (pagina == 4)  // Se a pagina é igual a 4, o animal escolhido é uma ave nativa.
	{
		entry_nacionalidade->hide();
		label_nacionalidade->hide();
		entry_total_de_mudas->hide();
		label_total_de_mudas->hide();
		entry_data_da_ultima_muda->hide();
		label_data_da_ultima_muda->hide();
		entry_cor_dos_pelos->hide();
		label_cor_dos_pelos->hide();
		check_button_venenoso->hide();
		label_venenoso->hide();
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
		
		combo_box_classe->set_active(1);

		entry_tamanho_do_bico->set_text(to_string((it->second).get_tamanho_do_bico()));

		entry_envergadura_das_asas->set_text(to_string((it->second).get_envergadura_das_asas()));
	}
	else if (pagina == 5) // Se a pagina é igual a 5, o animal escolhido é uma aves exótica.
	{
		entry_total_de_mudas->hide();
		label_total_de_mudas->hide();
		entry_data_da_ultima_muda->hide();
		label_data_da_ultima_muda->hide();
		entry_cor_dos_pelos->hide();
		label_cor_dos_pelos->hide();
		check_button_venenoso->hide();
		label_venenoso->hide();
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
		
		combo_box_classe->set_active(1);


		entry_tamanho_do_bico->set_text(to_string((it->second).get_tamanho_do_bico()));

		entry_envergadura_das_asas->set_text(to_string((it->second).get_envergadura_das_asas()));

		combo_box_regiao->set_active(1);
		MudarRegiao();
		valid_nacionalidade = true;
	}
	else if (pagina == 6)  // Se a pagina é igual a 6, o animal escolhido é um mamífero nativo.
	{
		entry_nacionalidade->hide();
		label_nacionalidade->hide();
		entry_total_de_mudas->hide();
		label_total_de_mudas->hide();
		entry_data_da_ultima_muda->hide();
		label_data_da_ultima_muda->hide();
		entry_tamanho_do_bico->hide();
		label_tamanho_do_bico->hide();
		entry_envergadura_das_asas->hide();
		label_envergadura_das_asas->hide();
		check_button_venenoso->hide();
		label_venenoso->hide();
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
		
		combo_box_classe->set_active(2);

		entry_cor_dos_pelos->set_text((it->second).get_cor_do_pelo());

		combo_box_regiao->set_active(0);
		MudarRegiao();
	}
	else if (pagina == 7)  // Se a pagina é igual a 7, o animal escolhido é um mamífero exótico.
	{
		entry_total_de_mudas->hide();
		label_total_de_mudas->hide();
		entry_data_da_ultima_muda->hide();
		label_data_da_ultima_muda->hide();
		entry_tamanho_do_bico->hide();
		label_tamanho_do_bico->hide();
		entry_envergadura_das_asas->hide();
		label_envergadura_das_asas->hide();
		check_button_venenoso->hide();
		label_venenoso->hide();
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
		
		combo_box_classe->set_active(2);

		entry_cor_dos_pelos->set_text((it->second).get_cor_do_pelo());

		combo_box_regiao->set_active(1);
		MudarRegiao();
		valid_nacionalidade = true;
	}
	else if (pagina == 8) // Se a pagina é igual a 8, o animal escolhido é um reptil exótico.
	{
		entry_nacionalidade->hide();
		label_nacionalidade->hide();
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
		
		combo_box_classe->set_active(3);

		venenoso = (it->second).get_venenoso();
		if (venenoso)
		{
			check_button_venenoso->set_active(true);
			entry_tipo_de_veneno->set_text((it->second).get_tipo_de_veneno());
			MostrarVenenoso();
			valid_tipo_veneno = true;
		}
		else
		{
			entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_uncheck);
			MostrarVenenoso();
		}
	}
	else if (pagina == 9) // Se a pagina é igual a 9, o animal escolhido é um reptil exótico.
	{
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
		
		combo_box_classe->set_active(3);

		venenoso = (it->second).get_venenoso();
		if (venenoso)
		{
			check_button_venenoso->set_active(true);
			entry_tipo_de_veneno->set_text((it->second).get_tipo_de_veneno());
			MostrarVenenoso();
			valid_tipo_veneno = true;
		}
		else
		{
			entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_uncheck);
			MostrarVenenoso();
		}

		combo_box_regiao->set_active(1);
		MudarRegiao();
		valid_nacionalidade = true;
	}	
}

/**
* @brief Método que salva todas as informações escritas se elas forem válidas.
*/

void JanelaEditarAnimal::Editar()
{
	// Verificação se todas as informações são validas, caso uma delas não seja
	// aparecerá uma tela com um aviso informando qual a informação que está incorreta.
	if (!valid_nome_cientifico)
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
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi não foi encontrado um tratador com o ID apresentado.");
  		dialog.run();
	}
	else if (!valid_veterinario_id)
	{
		MessageDialog dialog(*window, "ID inválido.");
		dialog.set_secondary_text("Nenhum ID foi apresentado ou foi não foi encontrado um veterinario com o ID apresentado.");
  		dialog.run();
	}
	else if (!check_button_veterinario_incluso->get_active() &&
				!check_button_tratador_incluso->get_active())
	{
		MessageDialog dialog(*window, "Sem funcionário responsável pelo animal.");
		dialog.set_secondary_text("O animal tem que ter pelo menos um funcionário responsável por ele.");
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
	// Caso todas as informações estiverem corretas as antigas informações do animal são apagadas e
	// as novas são escritas.
	else
	{
		RemoverAnimal(*janela_principal, *animais, id);
		string classe = combo_box_classe->get_active_text(); 
		for(unsigned int i = 0; i < classe.length(); i++)
			classe[i] = toupper(classe[i]);
		string nome_cientifico = entry_nome_cientifico->get_text();
		char sexo = combo_box_sexo->get_active_text()[0];
		double tamanho = stod(entry_tamanho->get_text());
		string dieta = entry_dieta->get_text();
		Veterinario *veterinario = check_button_veterinario_incluso->get_active() ? dynamic_cast<Veterinario*>((veterinarios->find(stoi(entry_veterinario_id->get_text())))->second) : Funcionario();
		Tratador *tratador = check_button_tratador_incluso->get_active() ? dynamic_cast<Tratador*>((tratadores->find(stoi(entry_tratador_id->get_text())))->second) : Funcionario();
		string nome_batismo = entry_nome_batismo->get_text();
		string autorizacao_ibama = entry_autorizacao_ibama->get_text();
		string nacionalidade = combo_box_regiao->get_active_row_number() == 0 ? combo_box_uf->get_active_text() : entry_nacionalidade->get_text();

		ofstream outfile;
		outfile.open("Dados/animais.csv", ios::app);

		// Dependendo da espécie do animal as operações são diferentes, devido as especificidades de cada espécie.
		switch(combo_box_classe->get_active_row_number())
		{
			case 0:
			{
				// Anfíbio
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						vector<int> data;
						string data_string = entry_data_da_ultima_muda->get_text();
						data = Separador_data(data_string);
						date data_date(data[0], data[1], data[2]);

						Animal *temp = new AnfibioNativo(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, stoi(entry_total_de_mudas->get_text()), 
							data_date, autorizacao_ibama, nacionalidade);

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(2);
						break;
					}
					case 1:
					{
						vector<int> data;
						string data_string = entry_data_da_ultima_muda->get_text();
						data = Separador_data(data_string);
						date data_date(data[0], data[1], data[2]);

						Animal *temp = AnfibioExotico(id, classe, nome_cientifico, sexo,
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, stoi(entry_total_de_mudas->get_text()),
							data_date, autorizacao_ibama, nacionalidade, entry_cidade->get_text());

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(3);
						break;
					}
				}
				break;
			}
			case 1:
			{
				// Aves
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						Animal *temp = new AveNativo(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, stod(entry_tamanho_do_bico->get_text()), 
							stod(entry_envergadura_das_asas->get_text()), 
							autorizacao_ibama, nacionalidade);

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(4);
						break;
					}
					case 1:
					{
						Animal *temp = new AveExotico(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, stod(entry_tamanho_do_bico->get_text()), 
							stod(entry_envergadura_das_asas->get_text()), 
							autorizacao_ibama, nacionalidade, entry_cidade->get_text());

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(5);
						break;
					}
				}
				break;
			}
			case 2:
			{
				// Mamífero
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						Animal *temp = new MamiferoNativo(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, entry_cor_dos_pelos->get_text(), 
							autorizacao_ibama, nacionalidade);

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(6);
						break;
					}
					case 1:
					{
						Animal *temp = MamiferoExotico(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, entry_cor_dos_pelos->get_text(), 
							autorizacao_ibama, nacionalidade, entry_cidade->get_text());

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(7);
						break;
					}
				}
				break;
			}
			case 3:
			{
				// Réptil
				switch(combo_box_regiao->get_active_row_number())
				{
					case 0:
					{
						Animal *temp = new ReptilNativo(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, 
							nome_batismo, check_button_venenoso->get_active(), 
							entry_tipo_de_veneno->get_text(), autorizacao_ibama, 
							nacionalidade);

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(8);
						break;
					}
					case 1:
					{
						Animal *temp = new ReptilExotico(id, classe, nome_cientifico, sexo, 
							tamanho, dieta, *veterinario, *tratador, nome_batismo, 
							check_button_venenoso->get_active(), 
							entry_tipo_de_veneno->get_text(), autorizacao_ibama, 
							nacionalidade, entry_cidade->get_text());

						outfile << *temp << endl;
						animais->insert(pair<int, Animal*>(id, temp));
						//janela_principal->AtualizarLista(9);
						break;
					}
				}
				break;
			}
		}
	window->close();
	}
}

/**
* @brief Método que decide os widgets que vão aparecer de acordo com a espécie selecionada.
*/

void JanelaEditarAnimal::MudarClasse()
{
	switch(combo_box_classe->get_active_row_number())
	{
		case 0: // Caso a espécie seja anfíbio.
			valid_total_de_mudas = false;
			entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_uncheck);
			valid_data_da_ultima_muda = false;
			entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_uncheck);
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
			break;
		case 1: // Caso a espécie seja ave.
			valid_tamanho_do_bico = false;
			entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_uncheck);
			valid_envergadura_das_asas = false;
			entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_uncheck);
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
			entry_cor_dos_pelos->hide();
			check_button_venenoso->hide();
			label_venenoso->hide();
			entry_tipo_de_veneno->hide();
			label_tipo_de_veneno->hide();
			break;
		case 2: // Caso a espécie seja mamífero.
			valid_cor_dos_pelos = false;
			entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_uncheck);
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
			break;
		case 3: // Caso a espécie seja réptil.
			valid_tipo_veneno = false;
			entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_uncheck);
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
			break;
	}
}

/**
* @brief Método que decide os widgets que vão aparecer de acordo com a região selecionada.
*/

void JanelaEditarAnimal::MudarRegiao()
{
	switch(combo_box_regiao->get_active_row_number())
	{
		case 0: // Caso o aniaml seja nativo.
			valid_nacionalidade = true;
			valid_cidade = true;
			combo_box_uf->show();
			label_uf->show();
			entry_nacionalidade->hide();
			label_nacionalidade->hide();
			entry_cidade->hide();
			label_cidade->hide();
			break;
		case 1: // Caso o animal seja exótico.
			valid_nacionalidade = false;
			entry_nacionalidade->set_icon_from_pixbuf(pixbuf_uncheck);
			valid_cidade = false;
			entry_cidade->set_icon_from_pixbuf(pixbuf_uncheck);
			combo_box_uf->hide();
			label_uf->hide();
			entry_nacionalidade->show();
			label_nacionalidade->show();
			entry_cidade->show();
			label_cidade->show();
			break;
	}
}

/**
* @brief Método que decide os widgets que vão aparecer se o check button de veterinário incluso estiver selecionado ou não.
*/

void JanelaEditarAnimal::MostrarVeterinario()
{
	if(!check_button_veterinario_incluso->get_active()) // Caso o check button de veterinário incluso estiver selecionado.
	{
		valid_veterinario_id = true;
		entry_veterinario_id->hide();
		label_veterinario_id->hide();
	}
	else // Caso o check button de veterinário incluso não estiver selecionado.
	{
		valid_veterinario_id = false;
		entry_veterinario_id->show();
		label_veterinario_id->show();
	}
}

/**
* @brief Método que decide os widgets que vão aparecer se o check de button tratador incluso estiver selecionado ou não.
*/

void JanelaEditarAnimal::MostrarTratador()
{
	if(!check_button_tratador_incluso->get_active()) // Caso o check button de tratador incluso estiver selecionado.
	{
		valid_tratador_id = true;
		entry_tratador_id->hide();
		label_tratador_id->hide();
	}
	else // Caso o check button de tratador incluso não estiver selecionado.
	{
		valid_tratador_id = false;
		entry_tratador_id->show();
		label_tratador_id->show();
	}
}

/**
* @brief Método que decide os widgets que vão aparecer se o check button venenoso selecionado ou não.
*/

void JanelaEditarAnimal::MostrarVenenoso()
{
	if(!check_button_venenoso->get_active()) // Caso o check button de veneso estiver selecionado.
	{
		valid_tipo_veneno = true;
		entry_tipo_de_veneno->hide();
		label_tipo_de_veneno->hide();
	}
	else // Caso o check button de venenoso não  estiver selecionado.
	{
		valid_tipo_veneno = false;
		entry_tipo_de_veneno->show();
		label_tipo_de_veneno->show();
	}
}

/**
* @brief Método que verifica se o nome cienticio digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeNomeCientifico()
{
	string temp = entry_nome_cientifico->get_text();
	if(temp.empty()) // Caso o nome cienticio digitado for inválido.
	{
		valid_nome_cientifico = false;
		entry_nome_cientifico->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else // Caso o nome cienticio digitado for válido.
	{
		valid_nome_cientifico = true;
		entry_nome_cientifico->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que verifica se o tamanho digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeTamanho()
{
	string entry_text = entry_tamanho->get_text();
	double temp;
	bool has_one_comma = true;
	bool is_numeric = true;
	int commas = 0;
	unsigned int commaPos;
	//Verificado se todos os caracteres são digitos
	for(unsigned int i = 0; i < entry_text.length(); i++)
	{
		if(entry_text[i] == ',')
		{
			commaPos = i;
			commas++;
		}
	}
	if(commas == 0)
	{
		for(unsigned int i = 0; i < entry_text.length(); i++)
		{
			if(i != commaPos && !isdigit(entry_text[i]))
			{
				has_one_comma = false;
				break;
			}
		}
	}
	if(commas == 1)
	{
		for(unsigned int i = 0; i < entry_text.length(); i++)
		{
			if(i != commaPos && !isdigit(entry_text[i]))
			{
				is_numeric = false;
				break;
			}
		}
	}
	else if(commas > 1)
	{
		has_one_comma = false;
	}

	//Tenta fazer o stod, existe a possibilidade de dar erro quando não houver nada digitado
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
	//Se o tamanho for maior que 0 e for numerico implica que é um dado válido
	if(temp > 0 && is_numeric && has_one_comma)
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

/**
* @brief Método que verifica se a dieta digitada é válido.
*/

void JanelaEditarAnimal::AtualizarIconeDieta()
{
	string temp = entry_dieta->get_text();
	if(temp.empty())  // Caso a dieta digitada for inválida.
	{
		valid_dieta = false;
		entry_dieta->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else  // Caso a dieta digitada for inválida.
	{
		valid_dieta = true;
		entry_dieta->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que verifica se o ID do tratador digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeTratadorId()
{
	string temp = entry_tratador_id->get_text();
	bool is_numeric = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false; // Caso o ID do tratador digitado não for um número.
			break;
		}
	}
	if(is_numeric && !temp.empty()) // Caso o ID do tratador digitado for válido.
	{
		int id = stoi(temp);
		map<int, Funcionario*>::iterator it = funcionarios->find(id);

		if(it != funcionarios->end()) // Caso o ID de tratador digitado existir.
		{
			valid_tratador_id = true;
			entry_tratador_id->set_icon_from_pixbuf(pixbuf_check);
			entry_tratador_id->set_icon_tooltip_text("ID válido");
		}
		else // Caso o ID de tratador digitado não existir.
		{
			valid_tratador_id = false;
			entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_tratador_id->set_icon_tooltip_text("Nenhum tratador possui esse ID");
		}
	}
	else // Caso o ID de tratador digitado for inválido.
	{
		valid_tratador_id = false;
		entry_tratador_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tratador_id->set_icon_tooltip_text("ID inválido");
	}
}

/**
* @brief Método que verifica se o ID do veterinário digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeVeterinarioId()
{
	string temp = entry_veterinario_id->get_text();
	bool is_numeric = true;
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false; // Caso o ID do veterinário digitado não for um número.
			break;
		}
	}
	if(is_numeric && !temp.empty()) // Caso o ID do veterinário digitado for inválido.
	{
		int id = stoi(temp);
		map<int, Funcionario*>::iterator it = funcionarios->find(id);

		if(it_t != funcionarios->end()) // Caso o ID do veterinário digitado existir.
		{
			valid_veterinario_id = true;
			entry_veterinario_id->set_icon_from_pixbuf(pixbuf_check);
			entry_veterinario_id->set_icon_tooltip_text("ID válido");
		}
		else // Caso o ID do veterinário digitado não existir.
		{
			valid_veterinario_id = false;
			entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
			entry_veterinario_id->set_icon_tooltip_text("Nenhum veterinário possui esse ID");
		}
	}
	else // Caso o ID do veterinário digitado for inválido.
	{
		valid_veterinario_id = false;
		entry_veterinario_id->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_veterinario_id->set_icon_tooltip_text("ID inválido");
	}
}

/**
* @brief Método que verifica se o nome de batismo digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeNomeBatismo()
{
	string temp = entry_nome_batismo->get_text();
	if(temp.empty()) // Caso o nome de batismo digitado for inválido.
	{
		valid_nome_batismo = false;
		entry_nome_batismo->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else // Caso o nome de batismo digitado for válido.
	{
		valid_nome_batismo = true;
		entry_nome_batismo->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que verifica se a autorização do ibama digitada é válida.
*/

void JanelaEditarAnimal::AtualizarIconeAutorizacaoIbama()
{
	string temp = entry_autorizacao_ibama->get_text();
	if(temp.empty())  // Caso a autorização do ibama digitada for inválida.
	{
		valid_autorizacao_ibama = false;
		entry_autorizacao_ibama->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else // Caso a autorização do ibama digitada for válida.
	{
		valid_autorizacao_ibama = true;
		entry_autorizacao_ibama->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que verifica se a nascionalidade digitada é válida.
*/

void JanelaEditarAnimal::AtualizarIconeNacionalidade()
{
	string temp = entry_nacionalidade->get_text();
	if(temp.empty())  // Caso a nacionalidade digitadoa for inválida.
	{
		valid_nacionalidade = false;
		entry_nacionalidade->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else  // Caso a nacionalidade digitada for válida.
	{
		valid_nacionalidade = true;
		entry_nacionalidade->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que é responsável para atualizar o icone de válido ou inválido da cidade.
*/

void JanelaEditarAnimal::AtualizarIconeCidade()
{
	string temp = entry_cidade->get_text();
	bool is_numeric = true;
	//Verificado se todos os caracteres são digitos
	for(unsigned int i = 0; i < temp.size(); i++)
	{
		if(!isdigit(temp[i]))
		{
			is_numeric = false;
			break;
		}
	}
	//Se for todos numeros e não estiver vazio
	if(!is_numeric && !temp.empty())
	{
		valid_cidade = true;
		entry_cidade->set_icon_from_pixbuf(pixbuf_check);
		entry_cidade->set_icon_tooltip_text("Cidade válida");
	}
	//Se os dados forem inválidos
	else
	{
		valid_cidade = false;
		entry_cidade->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_cidade->set_icon_tooltip_text("Cidade inválida");
	}
}

/**
* @brief Método que verifica se o total de mudas digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeTotalDeMudas()
{
	int temp;
	//Tenta fazer o stoi, existe a possibilidade de dar erro quando não houver nada digitado
	try
	{
		temp = stoi(entry_total_de_mudas->get_text());
	}
	catch(exception &ex)
	{
		valid_total_de_mudas = false;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_total_de_mudas->set_icon_tooltip_text("Quantidade Inválida");
		valid_data_da_ultima_muda = false;
		label_data_da_ultima_muda->hide();
		entry_data_da_ultima_muda->hide();
		return;
	}
	// Verifica se o total de mudas é menor que zero.
	if (temp < 0)
	{
		valid_total_de_mudas = false;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_total_de_mudas->set_icon_tooltip_text("Quantidade Inválida");
		valid_data_da_ultima_muda = false;
		label_data_da_ultima_muda->hide();
		entry_data_da_ultima_muda->hide();
	}
	else if (temp == 0)
	{
		valid_total_de_mudas = true;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_check);
		valid_data_da_ultima_muda = true;
		label_data_da_ultima_muda->hide();
		entry_data_da_ultima_muda->hide();
	}
	else 
	{
		valid_total_de_mudas = true;
		entry_total_de_mudas->set_icon_from_pixbuf(pixbuf_check);
		label_data_da_ultima_muda->show();
		entry_data_da_ultima_muda->show();

	}
}

/**
* @brief Método que verifica se a data digitada é válido.
*/

void JanelaEditarAnimal::AtualizarIconeDataDaUltimaMuda()
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
	catch(exception &ex) // Caso não seja possivel converter a data digitada para o tipo date.
	{
		valid_data_da_ultima_muda = false;
		entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_data_da_ultima_muda->set_icon_tooltip_text("Data Inválida");
		return;
	}
	if (data_da_ultima_muda.valid()) // Caso a data seja válida.
	{
		valid_data_da_ultima_muda = true;
		entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_check);
	}
	else // Caso a data não seja válida (Ex: 01/13/2019).
	{
		valid_data_da_ultima_muda = false;
		entry_data_da_ultima_muda->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_data_da_ultima_muda->set_icon_tooltip_text("Data Inválida");
	}
}

/**
* @brief Método que verifica se o tamanho do bico digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeTamanhoDoBico()
{
	string entry_text = entry_tamanho_do_bico->get_text();
	double temp;
	bool has_one_comma = true;
	bool is_numeric = true;
	int commas = 0;
	unsigned int commaPos;
	//Verificado se todos os caracteres são digitos
	for(unsigned int i = 0; i < entry_text.length(); i++)
	{
		if(entry_text[i] == ',')
		{
			commaPos = i;
			commas++;
		}
	}
	if(commas == 0)
	{
		for(unsigned int i = 0; i < entry_text.length(); i++)
		{
			if(i != commaPos && !isdigit(entry_text[i]))
			{
				has_one_comma = false;
				break;
			}
		}
	}
	if(commas == 1)
	{
		for(unsigned int i = 0; i < entry_text.length(); i++)
		{
			if(i != commaPos && !isdigit(entry_text[i]))
			{
				is_numeric = false;
				break;
			}
		}
	}
	else if(commas > 1)
	{
		has_one_comma = false;
	}

	//Tenta fazer o stod, existe a possibilidade de dar erro quando não houver nada digitado
	try
	{
		temp = stod(entry_text);
	}
	catch(exception &ex)
	{
		valid_tamanho_do_bico = false;
		entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tamanho_do_bico->set_icon_tooltip_text("Tamanho inválido");
		return;
	}
	//Se o tamanho for maior que 0 e for numerico implica que é um dado válido
	if(temp > 0 && is_numeric && has_one_comma)
	{
		valid_tamanho_do_bico = true;
		entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_check);
	}
	else
	{
		valid_tamanho_do_bico = false;
		entry_tamanho_do_bico->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_tamanho_do_bico->set_icon_tooltip_text("O tamanho tem que ser maior que 0 e ter somente numeros");
	}
}

/**
* @brief Método que verifica se a emvergadura das asas digitada é válida.
*/

void JanelaEditarAnimal::AtualizarIconeEnvergaduraDasAsas()
{
	string entry_text = entry_envergadura_das_asas->get_text();
	double temp;
	bool has_one_comma = true;
	bool is_numeric = true;
	int commas = 0;
	unsigned int commaPos;
	//Verificado se todos os caracteres são digitos
	for(unsigned int i = 0; i < entry_text.length(); i++)
	{
		if(entry_text[i] == ',')
		{
			commaPos = i;
			commas++;
		}
	}
	if(commas == 0)
	{
		for(unsigned int i = 0; i < entry_text.length(); i++)
		{
			if(i != commaPos && !isdigit(entry_text[i]))
			{
				has_one_comma = false;
				break;
			}
		}
	}
	if(commas == 1)
	{
		for(unsigned int i = 0; i < entry_text.length(); i++)
		{
			if(i != commaPos && !isdigit(entry_text[i]))
			{
				is_numeric = false;
				break;
			}
		}
	}
	else if(commas > 1)
	{
		has_one_comma = false;
	}

	//Tenta fazer o stod, existe a possibilidade de dar erro quando não houver nada digitado
	try
	{
		temp = stod(entry_text);
	}
	catch(exception &ex)
	{
		valid_envergadura_das_asas = false;
		entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_envergadura_das_asas->set_icon_tooltip_text("Tamanho inválido");
		return;
	}
	//Se o tamanho for maior que 0 e for numerico implica que é um dado válido
	if(temp > 0 && is_numeric && has_one_comma)
	{
		valid_envergadura_das_asas = true;
		entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_check);
	}
	else
	{
		valid_envergadura_das_asas = false;
		entry_envergadura_das_asas->set_icon_from_pixbuf(pixbuf_uncheck);
		entry_envergadura_das_asas->set_icon_tooltip_text("O tamanho tem que ser maior que 0 e ter somente numeros");
	}
}

/**
* @brief Método que verifica se a cor dos pelos digitada é válida.
*/

void JanelaEditarAnimal::AtualizarIconeCorDosPelos()
{
	string temp = entry_cor_dos_pelos->get_text();
	if(temp.empty()) // Caso a cor dos pelos seja inválida.
	{
		valid_cor_dos_pelos = false;
		entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else // Caso a cor dos pelos seja válida.
	{
		valid_cor_dos_pelos = true;
		entry_cor_dos_pelos->set_icon_from_pixbuf(pixbuf_check);
	}
}

/**
* @brief Método que verifica se o tipo de veneno digitado é válido.
*/

void JanelaEditarAnimal::AtualizarIconeTipoDeVeneno()
{
	string temp = entry_tipo_de_veneno->get_text();
	if(temp.empty()) // Caso o tipo de veneno digitado seja inválido.
	{
		valid_tipo_veneno = false;
		entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_uncheck);
	}
	else // Caso o tipo de veneno digitado seja válido.
	{
		valid_tipo_veneno = true;
		entry_tipo_de_veneno->set_icon_from_pixbuf(pixbuf_check);
	}
}
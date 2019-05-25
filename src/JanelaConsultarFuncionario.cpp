#include "JanelaConsultarFuncionario.h"

using namespace Gtk;
using namespace std;

JanelaConsultarFuncionario::JanelaConsultarFuncionario(map<int, Veterinario> &vtemp, map<int, Tratador> &ttemp)
{
	veterinarios = &vtemp;
	tratadores = &ttemp;

	//Inicialização
	window = new Window;

	box_principal = new HBox;

	tree_view_tratadores = new TreeView;
	tree_view_veterinarios = new TreeView;

	scrolled_window_tratadores = new ScrolledWindow;
	scrolled_window_veterinarios = new ScrolledWindow;

	//Configuração
	window->set_default_size(600, 200);
	window->set_title("Consultar Funcionário");
	window->add(*box_principal);

	box_principal->add(*scrolled_window_tratadores);
	//box_principal->add(*scrolled_window_veterinarios);

	scrolled_window_tratadores->add(*tree_view_tratadores);
	//scrolled_window_veterinarios->add(*tree_view_veterinarios);

	//Criando o modelo de arvore
	list_store_tratadores = ListStore::create(model_columns_tratador);
	tree_view_tratadores->set_model(list_store_tratadores);

	//Preenchendo o modelo de arvore tratador
	TreeModel::Row row;

	for(map<int, Tratador>::iterator it = tratadores->begin(); it != tratadores->end(); it++)
	{
		row = *(list_store_tratadores->append());
		row[model_columns_tratador.col_id] = it->second.get_id();
		row[model_columns_tratador.col_nome] = it->second.get_nome();
		row[model_columns_tratador.col_cpf] = it->second.get_cpf();
		row[model_columns_tratador.col_idade] = it->second.get_idade();
		row[model_columns_tratador.col_tipo_sanguineo] = it->second.get_tipo_sanguineo();
		row[model_columns_tratador.col_rh] = it->second.get_rh();
		row[model_columns_tratador.col_especialidade] = it->second.get_especialidade();
		row[model_columns_tratador.col_nivel_seguranca] = it->second.get_nivel_de_seguranca();
	}

	//Adicionado a TreeView suas colunas
	tree_view_tratadores->append_column("Id", model_columns_tratador.col_id);
	tree_view_tratadores->append_column("Nome", model_columns_tratador.col_nome);
	tree_view_tratadores->append_column("CPF", model_columns_tratador.col_cpf);
	tree_view_tratadores->append_column("Idade", model_columns_tratador.col_idade);
	tree_view_tratadores->append_column("Tipo sanguineo", model_columns_tratador.col_tipo_sanguineo);
	tree_view_tratadores->append_column("RH", model_columns_tratador.col_rh);
	tree_view_tratadores->append_column("Especialidade", model_columns_tratador.col_especialidade);
	tree_view_tratadores->append_column("Nivel de segurança", model_columns_tratador.col_nivel_seguranca);
}

JanelaConsultarFuncionario::~JanelaConsultarFuncionario()
{
	delete window;
	delete box_principal;
	delete tree_view_tratadores;
	delete tree_view_veterinarios;
	delete scrolled_window_tratadores;
	delete scrolled_window_veterinarios;
}

void JanelaConsultarFuncionario::Run()
{
	window->show_all();
	Main::run(*window);
}
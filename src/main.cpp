/**
* @file main.cpp
* @brief Função principal.
* @author
* Hudson Bruno Macedo Alves,
* João Vitor Kobata,
* Vinicius Santos Silva de Lima.
*/

#include <iostream>
#include <gtkmm.h>

#include "JanelaPrincipal.h"

using namespace std;
using namespace Gtk;

/**
* @brief Função principal.
* @details inicia a janela principal.
*/

int main(int argc, char* argv[])
{
	Main kit(argc, argv);

	JanelaPrincipal janelaPrincipal;
	janelaPrincipal.Run();
}
#include <iostream>
using namespace std;

#include <gtkmm.h>
using namespace Gtk;

#include "JanelaPrincipal.h"

int main(int argc, char* argv[])
{
	Main kit(argc, argv);

	JanelaPrincipal janelaPrincipal;
	janelaPrincipal.Run();
}
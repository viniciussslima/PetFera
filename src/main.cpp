#include <iostream>
#include <gtkmm.h>

#include "JanelaPrincipal.h"

using namespace std;
using namespace Gtk;

int main(int argc, char* argv[])
{
	Main kit(argc, argv);

	JanelaPrincipal janelaPrincipal;
	janelaPrincipal.Run();
}
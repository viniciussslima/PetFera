INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
CC = g++
PROG = main
CPPFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall -std=c++11 -I$(INCLUDEDIR)
LDFLAGS = `pkg-config --libs gtkmm-3.0` -L/lib
OBJS = main.o JanelaPrincipal.o JanelaCadastroFuncionario.o Funcionario.o Veterinario.o Tratador.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
	mv $(PROG) $(BINDIR)
	mv $(OBJS) $(BUILDDIR)
main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp
JanelaPrincipal.o: include/JanelaPrincipal.h
	$(CC) $(CPPFLAGS) -c src/JanelaPrincipal.cpp
JanelaCadastroFuncionario.o: include/JanelaCadastroFuncionario.h
	$(CC) $(CPPFLAGS) -c src/JanelaCadastroFuncionario.cpp
Funcionario.o : $(INCLUDEDIR)Funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Funcionario.cpp
Veterinario.o : $(INCLUDEDIR)Veterinario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Veterinario.cpp
Tratador.o : $(INCLUDEDIR)Tratador.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Tratador.cpp
clean: clean
	cd $(BUILDIR) && rm -f core $(OBJS)
cleanall:
	cd $(BINDIR) && rm -f core $(PROG)
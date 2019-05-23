INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
CC = g++
PROG = main
CPPFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall -std=c++11 -I$(INCLUDEDIR)
LDFLAGS = `pkg-config --libs gtkmm-3.0` -L/lib
OBJS = main.o JanelaPrincipal.o JanelaCadastroFuncionario.o \
Funcionario.o Veterinario.o Tratador.o

$(PROG): $(OBJS) folder
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
	mv $(PROG) $(BINDIR)
	mv $(OBJS) $(BUILDDIR)
folder :
	mkdir -p $(BINDIR)
	mkdir -p $(BUILDDIR)
	mkdir -p Dados
main.o:
	$(CC) $(CPPFLAGS) -c $(SRCDIR)main.cpp
JanelaPrincipal.o: $(INCLUDEDIR)JanelaPrincipal.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)JanelaPrincipal.cpp
JanelaCadastroFuncionario.o: $(INCLUDEDIR)JanelaCadastroFuncionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)JanelaCadastroFuncionario.cpp
Funcionario.o : $(INCLUDEDIR)Funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Funcionario.cpp
Veterinario.o : $(INCLUDEDIR)Veterinario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Veterinario.cpp
Tratador.o : $(INCLUDEDIR)Tratador.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Tratador.cpp
clean:
	cd $(BUILDIR) && rm -f core $(OBJS)
cleanall: clean
	cd $(BINDIR) && rm -f core $(PROG)
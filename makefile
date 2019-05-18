INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
CC = g++
PROG = main
CPPFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall -std=c++11 -I$(INCLUDEDIR)
LDFLAGS = `pkg-config --libs gtkmm-3.0` -L/lib
OBJS = main.o JanelaPrincipal.o JanelaCadastroFuncionario.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp
JanelaPrincipal.o: include/JanelaPrincipal.h
	$(CC) $(CPPFLAGS) -c src/JanelaPrincipal.cpp
JanelaCadastroFuncionario.o: include/JanelaCadastroFuncionario.h
	$(CC) $(CPPFLAGS) -c src/JanelaCadastroFuncionario.cpp
clean:
	rm -f core $(OBJS) $(PROG)
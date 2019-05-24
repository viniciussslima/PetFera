INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
CC = g++
PROG = main
CPPFLAGSGTK = `pkg-config --cflags gtkmm-3.0` -Wall -std=c++11 -I$(INCLUDEDIR)
CPPFLAGS = -Wall -std=c++11 -I$(INCLUDEDIR)
LDFLAGS = `pkg-config --libs gtkmm-3.0`
OBJS = main.o JanelaPrincipal.o JanelaCadastroFuncionario.o \
JanelaCadastroAnimal.o \
date.o \
Funcionario.o Veterinario.o Tratador.o \
Animal.o \
Anfibio.o AnfibioNativo.o AnfibioExotico.o \
Mamifero.o MamiferoNativo.o MamiferoExotico.o \
Reptil.o ReptilNativo.o ReptilExotico.o \
Ave.o AveNativo.o AveExotico.o \
AnimalSilvestre.o AnimalNativo.o AnimalExotico.o \

$(PROG): $(OBJS) folder
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
	mv $(PROG) $(BINDIR)
	mv $(OBJS) $(BUILDDIR)
folder :
	mkdir -p $(BINDIR)
	mkdir -p $(BUILDDIR)
	mkdir -p Dados
main.o:
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)main.cpp
JanelaPrincipal.o: $(INCLUDEDIR)JanelaPrincipal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaPrincipal.cpp
JanelaCadastroFuncionario.o: $(INCLUDEDIR)JanelaCadastroFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaCadastroFuncionario.cpp
JanelaCadastroAnimal.o: $(INCLUDEDIR)JanelaCadastroAnimal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaCadastroAnimal.cpp
date.o : $(INCLUDEDIR)date.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)date.cpp
Funcionario.o : $(INCLUDEDIR)Funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Funcionario.cpp
Veterinario.o : $(INCLUDEDIR)Veterinario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Veterinario.cpp
Tratador.o : $(INCLUDEDIR)Tratador.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Tratador.cpp
Animal.o : $(INCLUDEDIR)Animal.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Animal.cpp
Anfibio.o : $(INCLUDEDIR)Anfibio.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Anfibio.cpp
AnfibioNativo.o : $(INCLUDEDIR)AnfibioNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnfibioNativo.cpp
AnfibioExotico.o : $(INCLUDEDIR)AnfibioExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnfibioExotico.cpp
Mamifero.o : $(INCLUDEDIR)Mamifero.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Mamifero.cpp
MamiferoNativo.o : $(INCLUDEDIR)MamiferoNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)MamiferoNativo.cpp
MamiferoExotico.o : $(INCLUDEDIR)MamiferoExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)MamiferoExotico.cpp
Reptil.o : $(INCLUDEDIR)Reptil.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Reptil.cpp
ReptilNativo.o : $(INCLUDEDIR)ReptilNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)ReptilNativo.cpp
ReptilExotico.o : $(INCLUDEDIR)ReptilExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)ReptilExotico.cpp
Ave.o : $(INCLUDEDIR)Ave.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Ave.cpp
AveNativo.o : $(INCLUDEDIR)AveNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AveNativo.cpp
AveExotico.o : $(INCLUDEDIR)AveExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AveExotico.cpp
AnimalSilvestre.o : $(INCLUDEDIR)AnimalSilvestre.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnimalSilvestre.cpp
AnimalNativo.o : $(INCLUDEDIR)AnimalNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnimalNativo.cpp
AnimalExotico.o : $(INCLUDEDIR)AnimalExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnimalExotico.cpp
clean:
	cd $(BUILDIR) && rm -f core $(OBJS)
cleanall: clean
	cd $(BINDIR) && rm -f core $(PROG)
run:
	cd $(BINDIR) && ./$(PROG) && cd ..

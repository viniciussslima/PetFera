INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
CC = g++
PROG = $(BINDIR)main
CPPFLAGSGTK = `pkg-config --cflags gtkmm-3.0` -Wall -std=c++11 -I$(INCLUDEDIR)
CPPFLAGS = -Wall -std=c++11 -I$(INCLUDEDIR)
LDFLAGS = `pkg-config --libs gtkmm-3.0`
OBJS = $(BUILDDIR)main.o $(BUILDDIR)JanelaPrincipal.o $(BUILDDIR)JanelaCadastroFuncionario.o \
$(BUILDDIR)JanelaCadastroAnimal.o $(BUILDDIR)JanelaRemocaoFuncionario.o $(BUILDDIR)JanelaRemocaoAnimal.o\
$(BUILDDIR)JanelaEditarFuncionario.o $(BUILDDIR)JanelaBuscaAnimais.o \
$(BUILDDIR)date.o \
$(BUILDDIR)Funcionario.o $(BUILDDIR)Veterinario.o $(BUILDDIR)Tratador.o \
$(BUILDDIR)Animal.o \
$(BUILDDIR)Anfibio.o $(BUILDDIR)AnfibioNativo.o $(BUILDDIR)AnfibioExotico.o \
$(BUILDDIR)Mamifero.o $(BUILDDIR)MamiferoNativo.o $(BUILDDIR)MamiferoExotico.o \
$(BUILDDIR)Reptil.o $(BUILDDIR)ReptilNativo.o $(BUILDDIR)ReptilExotico.o \
$(BUILDDIR)Ave.o $(BUILDDIR)AveNativo.o $(BUILDDIR)AveExotico.o \
$(BUILDDIR)AnimalSilvestre.o $(BUILDDIR)AnimalNativo.o $(BUILDDIR)AnimalExotico.o \
$(BUILDDIR)Separador.o

$(PROG): folder clean $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
folder :
	mkdir -p $(BINDIR)
	mkdir -p $(BUILDDIR)
	mkdir -p Dados
$(BUILDDIR)main.o:
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)main.cpp -o $@
$(BUILDDIR)JanelaPrincipal.o: $(INCLUDEDIR)JanelaPrincipal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaPrincipal.cpp -o $@
$(BUILDDIR)JanelaCadastroFuncionario.o: $(INCLUDEDIR)JanelaCadastroFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaCadastroFuncionario.cpp -o $@
$(BUILDDIR)JanelaCadastroAnimal.o: $(INCLUDEDIR)JanelaCadastroAnimal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaCadastroAnimal.cpp -o $@
$(BUILDDIR)JanelaRemocaoFuncionario.o: $(INCLUDEDIR)JanelaRemocaoFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaRemocaoFuncionario.cpp -o $@
$(BUILDDIR)JanelaRemocaoAnimal.o: $(INCLUDEDIR)JanelaRemocaoAnimal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaRemocaoAnimal.cpp -o $@
$(BUILDDIR)JanelaEditarFuncionario.o: $(INCLUDEDIR)JanelaEditarFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaEditarFuncionario.cpp -o $@
$(BUILDDIR)JanelaBuscaAnimais.o: $(INCLUDEDIR)JanelaBuscaAnimais.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaBuscaAnimais.cpp -o $@
$(BUILDDIR)date.o : $(INCLUDEDIR)date.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)date.cpp -o $@
$(BUILDDIR)Funcionario.o : $(INCLUDEDIR)Funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Funcionario.cpp -o $@
$(BUILDDIR)Veterinario.o : $(INCLUDEDIR)Veterinario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Veterinario.cpp -o $@
$(BUILDDIR)Tratador.o : $(INCLUDEDIR)Tratador.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Tratador.cpp -o $@
$(BUILDDIR)Animal.o : $(INCLUDEDIR)Animal.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Animal.cpp -o $@
$(BUILDDIR)Anfibio.o : $(INCLUDEDIR)Anfibio.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Anfibio.cpp -o $@
$(BUILDDIR)AnfibioNativo.o : $(INCLUDEDIR)AnfibioNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnfibioNativo.cpp -o $@
$(BUILDDIR)AnfibioExotico.o : $(INCLUDEDIR)AnfibioExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnfibioExotico.cpp -o $@
$(BUILDDIR)Mamifero.o : $(INCLUDEDIR)Mamifero.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Mamifero.cpp -o $@
$(BUILDDIR)MamiferoNativo.o : $(INCLUDEDIR)MamiferoNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)MamiferoNativo.cpp -o $@
$(BUILDDIR)MamiferoExotico.o : $(INCLUDEDIR)MamiferoExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)MamiferoExotico.cpp -o $@
$(BUILDDIR)Reptil.o : $(INCLUDEDIR)Reptil.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Reptil.cpp -o $@
$(BUILDDIR)ReptilNativo.o : $(INCLUDEDIR)ReptilNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)ReptilNativo.cpp -o $@
$(BUILDDIR)ReptilExotico.o : $(INCLUDEDIR)ReptilExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)ReptilExotico.cpp -o $@
$(BUILDDIR)Ave.o : $(INCLUDEDIR)Ave.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Ave.cpp -o $@
$(BUILDDIR)AveNativo.o : $(INCLUDEDIR)AveNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AveNativo.cpp -o $@
$(BUILDDIR)AveExotico.o : $(INCLUDEDIR)AveExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AveExotico.cpp -o $@
$(BUILDDIR)AnimalSilvestre.o : $(INCLUDEDIR)AnimalSilvestre.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnimalSilvestre.cpp -o $@
$(BUILDDIR)AnimalNativo.o : $(INCLUDEDIR)AnimalNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnimalNativo.cpp -o $@
$(BUILDDIR)AnimalExotico.o : $(INCLUDEDIR)AnimalExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)AnimalExotico.cpp -o $@
$(BUILDDIR)Separador.o : $(INCLUDEDIR)Separador.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Separador.cpp -o $@
clean :
	rm -f core $(OBJS)
cleanall : clean
	rm -f core $(PROG)
run :
	./$(PROG)
gdb:
	cd $(BINDIR) && gdb $(PROG) && cd ..	

INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
LIBDIR = lib/
CC = g++
PROG_PETFERA = $(BINDIR)PetFera
PROG_EXPORTAR = $(BINDIR)Exportar
PROG_BIBLIOTECA = $(LIBDIR)PetFera.so
CPPFLAGSGTK = `pkg-config --cflags gtkmm-3.0` -g -O0 -Wall -std=c++11 -I$(INCLUDEDIR)
CPPFLAGS = -g -O0 -Wall -std=c++11 -I$(INCLUDEDIR)
LDFLAGS = `pkg-config --libs gtkmm-3.0` $(PROG_BIBLIOTECA)

OBJS = $(BUILDDIR)main.o $(BUILDDIR)JanelaPrincipal.o $(BUILDDIR)JanelaCadastroFuncionario.o \
$(BUILDDIR)JanelaCadastroAnimal.o $(BUILDDIR)RemoverFuncionario.o $(BUILDDIR)RemoverAnimal.o\
$(BUILDDIR)JanelaEditarFuncionario.o $(BUILDDIR)JanelaEditarAnimal.o $(BUILDDIR)JanelaBuscaAnimais.o \
$(BUILDDIR)Responsabilidade.o $(BUILDDIR)date.o \
$(BUILDDIR)Separador.o

OBJS_EXPORTAR = $(BUILDDIR)date.o \
$(BUILDDIR)Funcionario.o $(BUILDDIR)Veterinario.o $(BUILDDIR)Tratador.o \
$(BUILDDIR)Animal.o \
$(BUILDDIR)Anfibio.o $(BUILDDIR)AnfibioNativo.o $(BUILDDIR)AnfibioExotico.o \
$(BUILDDIR)Mamifero.o $(BUILDDIR)MamiferoNativo.o $(BUILDDIR)MamiferoExotico.o \
$(BUILDDIR)Reptil.o $(BUILDDIR)ReptilNativo.o $(BUILDDIR)ReptilExotico.o \
$(BUILDDIR)Ave.o $(BUILDDIR)AveNativo.o $(BUILDDIR)AveExotico.o \
$(BUILDDIR)AnimalSilvestre.o $(BUILDDIR)AnimalNativo.o $(BUILDDIR)AnimalExotico.o \
$(BUILDDIR)Separador.o $(BUILDDIR)Exportar.o

OBJS_BIBLIOTECA = $(BUILDDIR)Funcionario.o $(BUILDDIR)Veterinario.o $(BUILDDIR)Tratador.o \
$(BUILDDIR)Animal.o \
$(BUILDDIR)Anfibio.o $(BUILDDIR)AnfibioNativo.o $(BUILDDIR)AnfibioExotico.o \
$(BUILDDIR)Mamifero.o $(BUILDDIR)MamiferoNativo.o $(BUILDDIR)MamiferoExotico.o \
$(BUILDDIR)Reptil.o $(BUILDDIR)ReptilNativo.o $(BUILDDIR)ReptilExotico.o \
$(BUILDDIR)Ave.o $(BUILDDIR)AveNativo.o $(BUILDDIR)AveExotico.o \
$(BUILDDIR)AnimalSilvestre.o $(BUILDDIR)AnimalNativo.o $(BUILDDIR)AnimalExotico.o \

$(PROG_BIBLIOTECA): folder $(OBJS_BIBLIOTECA)
	$(CC) -shared -o $(PROG_BIBLIOTECA) $(OBJS_BIBLIOTECA)

$(PROG_PETFERA): $(OBJS)
	$(CC) -o $(PROG_PETFERA) $(OBJS) $(LDFLAGS)

$(PROG_EXPORTAR): $(OBJS_EXPORTAR)
	$(CC) -o $(PROG_EXPORTAR) $(OBJS_EXPORTAR) $(PROG_BIBLIOTECA)

folder :
	mkdir -p $(BINDIR)
	mkdir -p $(BUILDDIR)
	mkdir -p $(LIBDIR)
	mkdir -p Dados

$(BUILDDIR)main.o:
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)main.cpp -o $@
$(BUILDDIR)JanelaPrincipal.o: $(INCLUDEDIR)JanelaPrincipal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaPrincipal.cpp -o $@
$(BUILDDIR)JanelaCadastroFuncionario.o: $(INCLUDEDIR)JanelaCadastroFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaCadastroFuncionario.cpp -o $@
$(BUILDDIR)JanelaCadastroAnimal.o: $(INCLUDEDIR)JanelaCadastroAnimal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaCadastroAnimal.cpp -o $@
$(BUILDDIR)RemoverFuncionario.o: $(INCLUDEDIR)RemoverFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)RemoverFuncionario.cpp -o $@
$(BUILDDIR)RemoverAnimal.o: $(INCLUDEDIR)RemoverAnimal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)RemoverAnimal.cpp -o $@
$(BUILDDIR)JanelaEditarFuncionario.o: $(INCLUDEDIR)JanelaEditarFuncionario.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaEditarFuncionario.cpp -o $@
$(BUILDDIR)JanelaEditarAnimal.o: $(INCLUDEDIR)JanelaEditarAnimal.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaEditarAnimal.cpp -o $@
$(BUILDDIR)JanelaBuscaAnimais.o: $(INCLUDEDIR)JanelaBuscaAnimais.h
	$(CC) $(CPPFLAGSGTK) -c $(SRCDIR)JanelaBuscaAnimais.cpp -o $@
$(BUILDDIR)Responsabilidade.o : $(INCLUDEDIR)Responsabilidade.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Responsabilidade.cpp -o $@
$(BUILDDIR)date.o : $(INCLUDEDIR)date.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)date.cpp -o $@
$(BUILDDIR)Funcionario.o : $(INCLUDEDIR)Funcionario.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Funcionario.cpp -o $@
$(BUILDDIR)Veterinario.o : $(INCLUDEDIR)Veterinario.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Veterinario.cpp -o $@
$(BUILDDIR)Tratador.o : $(INCLUDEDIR)Tratador.h 
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Tratador.cpp -o $@
$(BUILDDIR)Animal.o : $(INCLUDEDIR)Animal.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Animal.cpp -o $@
$(BUILDDIR)Anfibio.o : $(INCLUDEDIR)Anfibio.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Anfibio.cpp -o $@
$(BUILDDIR)AnfibioNativo.o : $(INCLUDEDIR)AnfibioNativo.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AnfibioNativo.cpp -o $@
$(BUILDDIR)AnfibioExotico.o : $(INCLUDEDIR)AnfibioExotico.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AnfibioExotico.cpp -o $@
$(BUILDDIR)Mamifero.o : $(INCLUDEDIR)Mamifero.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Mamifero.cpp -o $@
$(BUILDDIR)MamiferoNativo.o : $(INCLUDEDIR)MamiferoNativo.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)MamiferoNativo.cpp -o $@
$(BUILDDIR)MamiferoExotico.o : $(INCLUDEDIR)MamiferoExotico.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)MamiferoExotico.cpp -o $@
$(BUILDDIR)Reptil.o : $(INCLUDEDIR)Reptil.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Reptil.cpp -o $@
$(BUILDDIR)ReptilNativo.o : $(INCLUDEDIR)ReptilNativo.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)ReptilNativo.cpp -o $@
$(BUILDDIR)ReptilExotico.o : $(INCLUDEDIR)ReptilExotico.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)ReptilExotico.cpp -o $@
$(BUILDDIR)Ave.o : $(INCLUDEDIR)Ave.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)Ave.cpp -o $@
$(BUILDDIR)AveNativo.o : $(INCLUDEDIR)AveNativo.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AveNativo.cpp -o $@
$(BUILDDIR)AveExotico.o : $(INCLUDEDIR)AveExotico.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AveExotico.cpp -o $@
$(BUILDDIR)AnimalSilvestre.o : $(INCLUDEDIR)AnimalSilvestre.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AnimalSilvestre.cpp -o $@
$(BUILDDIR)AnimalNativo.o : $(INCLUDEDIR)AnimalNativo.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AnimalNativo.cpp -o $@
$(BUILDDIR)AnimalExotico.o : $(INCLUDEDIR)AnimalExotico.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRCDIR)AnimalExotico.cpp -o $@
$(BUILDDIR)Separador.o : $(INCLUDEDIR)Separador.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Separador.cpp -o $@
$(BUILDDIR)Exportar.o : $(INCLUDEDIR)Exportar.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Exportar.cpp -o $@
clean :
	rm -f core $(OBJS)
	rm -f core $(OBJS_EXPORTAR)
cleanall : clean
	rm -f core $(PROG_PETFERA)
	rm -f core $(PROG_EXPORTAR)
	rm -f core $(PROG_BIBLIOTECA)
run :
	./$(PROG_PETFERA)
gdb:
	gdb $(PROG_PETFERA)	
remake: cleanall $(PROG_PETFERA)
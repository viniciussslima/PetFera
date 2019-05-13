# Autores: 
## Hudson Bruno Macedo Alves
## João Vitor Kobata
## Vinicius Santos Silva de Lima

INCLUDEDIR = include/
SRCDIR = src/
BUILDDIR = build/
BINDIR = bin/
PROG = PetFera
CC = g++
LDFLAGS = -L/lib
CPPFLAGS = -Wall -std=c++11 -I$(INCLUDEDIR)
OBJS = main.o date.o \
Funcionario.o Veterinario.o Tratador.o \
Animal.o \
Anfibio.o AnfibioNativo.o AnfibioExotico.o \
Mamifero.o MamiferoNativo.o MamiferoExotico.o \
Reptil.o ReptilNativo.o ReptilExotico.o \
Ave.o AveNativo.o AveExotico.o \
AnimalSilvestre.o AnimalNativo.o AnimalExotico.o \
Cadastro_animal.o  Remocao_animal.o \
Cadastro_funcionario.o Remocao_funcionario.o \
Consultar_animal.o Consultar_funcionario.o

$(PROG) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
	mv $(PROG) $(BINDIR)
	mv $(OBJS) $(BUILDDIR)
main.o :
	$(CC) $(CPPFLAGS) -c $(SRCDIR)main.cpp
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
Cadastro_animal.o : $(INCLUDEDIR)Cadastro_animal.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Cadastro_animal.cpp
Remocao_animal.o  : $(INCLUDEDIR)Remocao_animal.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Remocao_animal.cpp
Cadastro_funcionario.o : $(INCLUDEDIR)Cadastro_funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Cadastro_funcionario.cpp
Remocao_funcionario.o : $(INCLUDEDIR)Remocao_funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Remocao_funcionario.cpp
Consultar_animal.o : $(INCLUDEDIR)Consultar_animal.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Consultar_animal.cpp
Consultar_funcionario.o : $(INCLUDEDIR)Consultar_funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Consultar_funcionario.cpp
clean:
	rm -f core $(OBJS)
	cd $(BUILDDIR) && rm -f core $(OBJS)
cleanall: clean
	cd $(BINDIR) && rm -f core $(PROG)
run:
	cd $(BINDIR) && ./$(PROG) && cd ..
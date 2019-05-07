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
OBJS = main.o \
Funcionario.o Veterinario.o Tratador.o \
Animal.o \
Anfibio.o AnfibioNativo.o AnfibioExotico.o \
Mamifero.o MamiferoNativo.o MamiferoExotico.o \
Repitil.o RepitilNativo.o RepitilExotico.o \
Ave.o AveNativo.o AveExotico \
AnimalSilvestre.o AnimalNativo.o AnimalExotico.o

$(PROG) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
	mv $(PROG) $(BINDIR)
	mv $(OBJS) $(BUILDDIR)
main.o :
	$(CC) $(CPPFLAGS) -c $(SRCDIR)main.cpp
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
Repitil.o : $(INCLUDEDIR)Repitil.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Repitil.cpp
RepitilNativo.o : $(INCLUDEDIR)RepitilNativo.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)RepitilNativo.cpp
RepitilExotico.o : $(INCLUDEDIR)RepitilExotico.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)RepitilExotico.cpp
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
	cd $(BUILDDIR) && rm -f core $(OBJS)
cleanall: clean
	cd $(SRCDIR) && rm -f core $(PROG)
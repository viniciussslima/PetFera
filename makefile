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
OBJS = main.o Funcionario.o
$(PROG) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
	mv $(PROG) $(BINDIR)
	mv $(OBJS) $(BUILDDIR)
main.o :
	$(CC) $(CPPFLAGS) -c $(SRCDIR)main.cpp
Funcionario.o : $(INCLUDEDIR)Funcionario.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)Funcionario.cpp
clean:
	cd $(BUILDDIR) && rm -f core $(OBJS)
cleanall: clean
	cd $(SRCDIR) && rm -f core $(PROG)
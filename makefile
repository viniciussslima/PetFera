# Autores: 
## Hudson Bruno Macedo Alves
## João Vitor Kobata
## Vinicius Santos Silva de Lima

PROG = PetFera
CC = g++
CPPFLAGS = -Wall -std=c++11
OBJS = main.o
$(PROG) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o :
	$(CC) $(CPPFLAGS) -c main.cpp
clean:
	rm -f core $(OBJS)
cleanall: clean
	rm -f core $(PROG)
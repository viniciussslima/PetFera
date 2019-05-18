CC = g++
PROG = PetFera
CPPFLAGS = `pkg-config --cflags gtkmm-3.0` -std=c++11 -Wall -g -O0
LDFLAGS = `pkg-config --libs gtkmm-3.0`
OBJS = main.o JanelaPrincipal.o
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp
JanelaPrincipal.o: JanelaPrincipal.h
	$(CC) $(CPPFLAGS) -c JanelaPrincipal.cpp

clean:
	rm -f core $(OBJS)
cleanall:
	rm -f core $(OBJS) $(PROG)
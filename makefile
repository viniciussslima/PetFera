CC = g++
PROG = main
CPPFLAGS = `pkg-config --cflags gtkmm-3.0` -std=c++11 -Wall
LDFLAGS = `pkg-config --libs gtkmm-3.0`
OBJS = main.o mainWindow.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp
mainWindow.o: mainWindow.h
	$(CC) $(CPPFLAGS) -c mainWindow.cpp
clean:
	rm -f core $(OBJS) $(PROG)
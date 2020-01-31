
CFLAGS=-Wall -Werror

all: main

main: main.o sudoku.o
	g++ $(CFLAGS) -o main main.o sudoku.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

sudoku.o: sudoku.h sudoku.cpp
	g++ $(CFLAGS) -c sudoku.cpp


clean:
	rm main *.o

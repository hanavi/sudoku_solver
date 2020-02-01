
CFLAGS=-Wall -Werror

all: ssolver

ssolver: main.o sudoku.o
	g++ $(CFLAGS) -o ssolver main.o sudoku.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

sudoku.o: sudoku.h sudoku.cpp
	g++ $(CFLAGS) -c sudoku.cpp


clean:
	-@rm -rf *~ *.o ssolver 2>/dev/null || true

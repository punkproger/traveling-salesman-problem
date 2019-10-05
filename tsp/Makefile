SRC = src/
FLAGS = -std=c++11

all: main

main: main.o CBruteForceSolver.o FileReader.o
	g++ main.o FileReader.o CBruteForceSolver.o -o main

main.o: $(SRC)main.cpp
	g++ -c $(SRC)main.cpp $(FLAGS)

CBruteForceSolver.o: $(SRC)CBruteForceSolver.cpp
	g++ -c $(SRC)CBruteForceSolver.cpp $(FLAGS)

FileReader.o: $(SRC)FileReader.cpp
	g++ -c $(SRC)FileReader.cpp $(FLAGS)

clean:
	rm -rf *.o main
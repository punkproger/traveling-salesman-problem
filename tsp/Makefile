SRC = src/
FLAGS = -std=c++11

all: main

main: main.o FileReader.o
	g++ main.o FileReader.o -o main

main.o:
	g++ -c $(SRC)main.cpp $(FLAGS)

FileReader.o:
	g++ -c $(SRC)FileReader.cpp $(FLAGS)

clean:
	rm -rf *.o main
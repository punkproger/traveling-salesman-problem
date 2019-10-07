#TODO: start use CMake instead of Makefile 

SRC = src/
COMMON_DIR  = $(SRC)Common
SOLVERS_DIR = $(SRC)Solvers/
SOLVERS_FLAGS = -I./$(SOLVERS_DIR)interface

BRUTE_FORCE_SOLVER_DIR   = $(SOLVERS_DIR)CBruteForceSolver/
BACK_TRACkING_SOLVER_DIR = $(SOLVERS_DIR)CBackTrackingSolver/
CHRISTOFIEDES_SOLVER_DIR = $(SOLVERS_DIR)CChristofidesSolver/

CXX = g++
FLAGS = -std=c++11 -I./$(COMMON_DIR)

OBJECTS = *.o

all: main

main: main.o FileReader.o CBruteForceSolver.o CBackTrackingSolver.o CChristofidesSolver.o
	$(CXX) main.o FileReader.o CBruteForceSolver.o CBackTrackingSolver.o CChristofidesSolver.o -o main

main.o: $(SRC)main.cpp
	$(CXX) -c $(SRC)main.cpp $(FLAGS) -I./$(SOLVERS_DIR) $(SOLVERS_FLAGS)

FileReader.o: $(SRC)FileReader.cpp
	$(CXX) -c $(SRC)FileReader.cpp $(FLAGS)

CBruteForceSolver.o: $(BRUTE_FORCE_SOLVER_DIR)CBruteForceSolver.cpp
	$(CXX) -c $(BRUTE_FORCE_SOLVER_DIR)CBruteForceSolver.cpp $(FLAGS) $(SOLVERS_FLAGS)

CBackTrackingSolver.o: $(BACK_TRACkING_SOLVER_DIR)CBackTrackingSolver.cpp
	$(CXX) -c $(BACK_TRACkING_SOLVER_DIR)CBackTrackingSolver.cpp $(FLAGS) $(SOLVERS_FLAGS)

CChristofidesSolver.o: $(CHRISTOFIEDES_SOLVER_DIR)CChristofidesSolver.cpp
	$(CXX) -c $(CHRISTOFIEDES_SOLVER_DIR)CChristofidesSolver.cpp $(FLAGS) $(SOLVERS_FLAGS)

clean:
	rm -rf *.o main
#include "FileReader/FileReader.hpp" 
#include "CChristofidesSolver/CChristofidesSolver.hpp"
#include "CBruteForceSolver/CBruteForceSolver.hpp"
#include "Optimization/Optimization.hpp"

#include <iostream>
#include <iomanip>
#include <memory>


int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "Not entered path to file" << std::endl;
		std::cout << "tsp [file]" << std::endl;
		return 1;
	}


	size_t optimization_iterations{TSP::Optimization::inf_limit};
	std::unique_ptr<TSP::ITSPSolver> solver;
	for (int i = 2; i < argc; ++i)
	{
		if (argv[i] == std::string("-i") && i+1 < argc)
		{
			optimization_iterations = std::stoi(argv[i+1]);
		}
		else if(argv[i] == std::string("-a") && i+1 < argc)
		{
			if (argv[i+1] == std::string("brute_force"))
			{
				solver.reset(new TSP::CBruteForceSolver());
			}
			else if(argv[i+1] == std::string("christofides"))
			{
				solver.reset(new TSP::CChristofidesSolver());
			}
			else
			{
				std::cout << "Not known algorithm, use default(christofides)" << std::endl;
			}
		}
	}

	TSP::Matrix matrix = TSP::FileReader::readPlateFile(argv[1]);
	if (!solver)
	{
		solver.reset(new TSP::CChristofidesSolver());
	}

	size_t cost{0};
	std::vector<size_t> sequence = solver->solve(matrix, 4);
	sequence = TSP::Optimization::twoOpt(sequence, matrix, optimization_iterations);

	for (size_t i = 0; i < sequence.size(); ++i)
	{
		if (i != sequence.size()-1)
		{
			cost += matrix[sequence[i]][sequence[i+1]];
		}
		std::cout << sequence[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "cost: " << cost << std::endl;

	return 0;
}
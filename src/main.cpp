#include "FileReader.hpp" 
#include "CChristofidesSolver/CChristofidesSolver.hpp"
#include "Optimization.hpp"

#include <iostream>
#include <iomanip>
#include <memory>

int main(int argc, char** argv)
{
	TSP::Matrix matrix = TSP::FileReader::readPlateFile("tsp_example_2.txt");
	std::unique_ptr<TSP::ITSPSolver> solver{new TSP::CChristofidesSolver()};

	size_t cost{0};
	std::vector<size_t> sequence = solver->solve(matrix, 4);
	sequence = TSP::Optimization::twoOpt(sequence, matrix, 1000);

	for (size_t i = 0; i < sequence.size(); ++i)
	{
		if (i != sequence.size()-1)
		{
			cost += matrix[sequence[i]][sequence[i+1]];
		}
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "cost: " << cost << std::endl;

	return 0;
}
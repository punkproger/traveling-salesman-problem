#include "FileReader.hpp" 
#include "CBruteForceSolver/CBruteForceSolver.hpp"
#include "CBackTrackingSolver/CBackTrackingSolver.hpp"
#include "CChristofidesSolver/CChristofidesSolver.hpp"

#include <iostream>
#include <iomanip>
#include <memory>

int main(int argc, char** argv)
{
	TSP::Matrix matrix = TSP::FileReader::readPlateFile("test/TestFile_11_lines.txt");
	std::unique_ptr<TSP::ITSPSolver> solver{new TSP::CBackTrackingSolver()};

	for (const auto& row : matrix)
	{
		for (auto val : row)
		{
			std::cout << std::setw(8) << val << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	size_t cost{0};
	auto sequence = solver->solve(matrix, 4);
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
#include "FileReader.hpp" 
#include "CBruteForceSolver.hpp"

#include <iostream>
#include <iomanip>
#include <memory>

int main(int argc, char** argv)
{
	TSP::Matrix matrix = TSP::FileReader::readPlateFile("test/TestFile.txt");
	std::unique_ptr<TSP::ITSPSolver> solver{new TSP::CBruteForceSolver()};

	auto sequence = solver->solve(matrix, 4);
	for (auto idx : sequence)
	{
		std::cout << idx << " ";
	}
	std::cout << std::endl;
	/*for (const auto& row : matrix)
	{
		for (auto val : row)
		{
			std::cout << std::setw(8) << val << " ";
		}
		std::cout << std::endl;
	}*/

	return 0;
}
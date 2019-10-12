/*
MIT License

Copyright (c) 2019 Vladislav Gusak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "FileReader/FileReader.hpp" 
#include "Common/Functions.hpp"
#include "CChristofidesSolver/CChristofidesSolver.hpp"
#include "CBruteForceSolver/CBruteForceSolver.hpp"
#include "Optimization/Optimization.hpp"
#include "ImageGenerator/ImageGenerator.hpp"

#include <iostream>
#include <iomanip>
#include <memory>

// TODO: Refactor code in main(), add class handler of arguments of main()
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
	std::string output_filename;
	for (int i = 2; i < argc; ++i)
	{
		if (argv[i] == std::string("-i") && i+1 < argc)
		{
			if (argv[i] != std::string("inf"))
			{
				optimization_iterations = std::stoi(argv[i+1]);
			}
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
		else if(argv[i] == std::string("-o") && i+1 < argc)
		{
			output_filename = argv[i+1];
		}
	}

	std::vector<TSP::Point> coordinates = TSP::FileReader::readPlateFile(argv[1]);
	TSP::Matrix matrix = TSP::Common::createMatrix(coordinates);
	if (!solver)
	{
		solver.reset(new TSP::CChristofidesSolver());
	}

	size_t cost{0};
	std::vector<size_t> path = solver->solve(matrix, 4);
	path = TSP::Optimization::twoOpt(path, matrix, optimization_iterations);
	path.push_back(path.front());

	for (size_t i = 0; i < path.size(); ++i)
	{
		if (i != path.size()-1)
		{
			cost += matrix[path[i]][path[i+1]];
		}
		std::cout << path[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "cost: " << cost << std::endl;

	if (!output_filename.empty())
	{
		TSP::ImageGenerator::saveImageFromPath(output_filename, path, coordinates);
	}

	return 0;
}
#include "FileReader.hpp" 

#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
	TSP::Matrix matrix = TSP::FileReader::readPlateFile("test/TestFile.txt");

	for (const auto& row : matrix)
	{
		for (auto val : row)
		{
			std::cout << std::setw(8) << val << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
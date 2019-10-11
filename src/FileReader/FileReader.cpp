#include "FileReader.hpp"

#include <fstream>
#include <sstream> 
#include <exception>

using namespace TSP;

namespace {

	std::vector<double> extractNumbers(const std::string& str)
	{
		std::vector<double> numbers;
		std::stringstream ss;
		std::string tmp;

		ss << str;

		while (!ss.eof())
		{
			ss >> tmp;

			//std::stod throws exceptions
			numbers.push_back(std::stod(tmp));
		}

		return numbers;
	}
}

std::vector<Point> FileReader::readPlateFile(const std::string& filename)
{
	std::ifstream file(filename);
	if(file.fail()){
        throw std::invalid_argument("Filed to open file");
    }

	std::string tmp;

	std::vector<Point> points;

	size_t line_idx{0};

	while(std::getline(file, tmp))
	{
		++line_idx;
		auto numbers = extractNumbers(tmp);

		if (numbers.size() != 2)
		{
			throw std::invalid_argument("There are(is) " + std::to_string(numbers.size()) + " numbers\n" +
								 "On " + std::to_string(line_idx) + "h lane\n" +
								 "Should be 2\n");
		}

		points.push_back(Point{numbers[0], numbers[1]});
	}
	
	return points;	
}
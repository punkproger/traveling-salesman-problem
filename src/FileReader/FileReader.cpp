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
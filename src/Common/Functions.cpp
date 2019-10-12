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
#include "Functions.hpp"

#include <cmath> 

using namespace TSP;

Matrix Common::createMatrix(const std::vector<Point>& points)
{
	Matrix result(points.size());

	for (size_t i = 0; i < points.size(); ++i)
	{
		result[i] = Row(points.size());
		for (size_t j = 0; j < points.size(); ++j)
		{
			result[i][j] = distance(points[i], points[j]);
		}
	}

	return result;
}

double Common::distance(const Point& lhs, const Point& rhs)
{
	return sqrt(pow(lhs.x - rhs.x , 2) + pow(lhs.y - rhs.y, 2));
}
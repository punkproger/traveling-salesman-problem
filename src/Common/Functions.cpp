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
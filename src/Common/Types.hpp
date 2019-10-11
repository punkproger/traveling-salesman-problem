#pragma once

#include <vector>

using std::size_t;

namespace TSP {
	using Row = std::vector<double>;
	using Matrix = std::vector<Row>;

	struct Point
	{
		double x;
		double y;
	};
}
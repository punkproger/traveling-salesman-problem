#pragma once

#include "Types.hpp"

namespace TSP {
	class ITSPSolver
	{
	public:
		virtual std::vector<size_t> solve(const Matrix& matrix, size_t root) = 0;
	};
}
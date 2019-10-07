#pragma once

#include "ITSPSolver.hpp"

namespace TSP {

	class CBruteForceSolver : public ITSPSolver
	{
	public:
		virtual std::vector<size_t> solve(const Matrix& matrix, size_t root) override;
	};
}
#pragma once

#include "ITSPSolver.hpp"

namespace TSP {

    class CBackTrackingSolver : public ITSPSolver
    {
    public:
        virtual std::vector<size_t> solve(const Matrix& matrix, size_t root) override;
    };
}
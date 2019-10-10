#include "Optimization.hpp"

#include <algorithm>
#include <iostream>

using namespace TSP;    

namespace {
    size_t calculateLength(const std::vector<size_t>& path, const Matrix& matrix)
    {
        size_t length{0};

        for (size_t i = 0; i < path.size()-1; ++i)
        {
            length += matrix[path[i]][path[i+1]];
        }

        return length;
    }
}

std::vector<size_t> Optimization::twoOpt(std::vector<size_t> path, const Matrix& matrix, size_t iterations)
{
    size_t best_cost{0}, cost{0}, times{0};
    for (size_t i = 0; i < path.size()-1; ++i)
    {
        best_cost += matrix[path[i]][path[i+1]];
    }
    std::vector<size_t> tmp_path;
    bool changed{false};
    
    do
    {
        changed = false;
        cost = best_cost;
        for (size_t i = 0; i < path.size()-2; ++i)
        {
            for (size_t j = i+1; j < path.size(); ++j)
            {
                if (j-1 == 1)
                {
                    continue;
                }
                tmp_path = path;

                std::reverse(tmp_path.begin()+i, tmp_path.begin()+j);

                cost = calculateLength(tmp_path, matrix);
                if (cost < best_cost)
                {
                    std::cout << best_cost << "->" << cost << std::endl;
                    path = tmp_path;
                    best_cost = cost;
                    changed = true;
                    break;
                }
            }
            if(changed)
            {
                break;
            }
        }
        ++times;

    } while (changed && (iterations == inf_limit || times < iterations));

    return path;
}
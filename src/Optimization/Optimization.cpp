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
                if (j == 2)
                {
                    continue;
                }
                tmp_path = path;

                std::reverse(tmp_path.begin()+i, tmp_path.begin()+j);
                // TODO: Can be optimized
                // a, b, c, d, e
                // reverse (b..d)
                // cost += (length[a, d] + length[b, e]) - (length[a, b] + length[d, e])
                cost = calculateLength(tmp_path, matrix);
                
                if (cost < best_cost)
                {
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
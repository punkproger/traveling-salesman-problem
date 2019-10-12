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
#include "CBackTrackingSolver.hpp"

#include <functional>

using namespace TSP;

std::vector<size_t> CBackTrackingSolver::solve(const Matrix& matrix, size_t root)
{
	std::vector<size_t> min_sequence;
	size_t min_value{0xFFFFFFF};

	std::function<void(size_t, size_t, std::vector<bool>&, std::vector<size_t>)> recursion_function;
	recursion_function = [&matrix, &min_sequence, &min_value, &root, &recursion_function]
	(size_t idx, size_t cost, std::vector<bool>& visited, std::vector<size_t> sequence) 
	{
	    if (sequence.size() == matrix.size() &&
	    	cost + matrix[idx][root] < min_value) {

	        min_sequence = sequence;
	        min_sequence.push_back(root);
	        min_value = cost + matrix[idx][root];

	        return;
	    } 
	  
	    sequence.resize(sequence.size() + 1);
	    for (size_t i = 0; i < matrix.size(); i++) { 
	        if (!visited[i] && matrix[idx][i]) { 
	  
	            // Mark as visited 
	            visited[i] = true;
	            sequence.back() = i;
	            recursion_function(i, cost + matrix[idx][i],visited, sequence); 
	  
	            // Mark ith node as unvisited 
	            visited[i] = false; 
	        }
	    }
	};
	std::vector<size_t> start_sequence{root};
	std::vector<bool> visited(matrix.size(), false);
	visited[root] = true;

	recursion_function(root, 0, visited, start_sequence);
	return min_sequence;
}
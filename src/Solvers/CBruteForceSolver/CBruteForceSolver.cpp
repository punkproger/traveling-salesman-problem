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
#include "CBruteForceSolver.hpp"

#include <algorithm>
#include <numeric>

using namespace TSP;

std::vector<size_t> CBruteForceSolver::solve(const Matrix& matrix, size_t root)
{
	std::vector<size_t> idxes(matrix.size());
	std::iota(idxes.begin(), idxes.end(), 0);

	auto permutation_begin_it = idxes.begin();
	auto permutation_end_it = idxes.end();

	size_t min_length{0xFFFFFFFF};
	std::vector<size_t> min_sequence;
	min_sequence.reserve(idxes.size());

	static auto calculate_length = [&matrix](const std::vector<size_t>& idxes)
	{
		size_t length{0};

		for(size_t i = 0; i < idxes.size()-1; ++i)
		{
			length += matrix[idxes[i]][idxes[i+1]];
		}

		return length;
	};

	do
	{
		size_t length = calculate_length(idxes);
		if (length < min_length)
		{
			min_length = length;
			min_sequence = idxes;
		}
	} while (std::next_permutation(permutation_begin_it, permutation_end_it));

	return min_sequence;
}
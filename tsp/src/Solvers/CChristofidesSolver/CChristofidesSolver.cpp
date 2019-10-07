#include "CChristofidesSolver.hpp"

#include <algorithm>

using namespace TSP;

namespace {
	struct Edge
	{
		size_t from;
		size_t to;
		double distance;
	};

	Matrix createCompleteGraph(const std::vector<Edge>& edges)
	{
		size_t max_idx{0};
		for(const auto& edge : edges)
		{
			max_idx = std::max({edge.from, edge.to, max_idx});
		}

		Matrix result_matrix(max_idx+1);
		for (auto& row : result_matrix)
		{
			row.resize(result_matrix.size(), 0);
		}

		for (const auto& edge : edges)
		{
			result_matrix[edge.from][edge.to] = edge.distance;
			result_matrix[edge.to][edge.from] = edge.distance;
		}

		return result_matrix;
	}

	namespace Kruskal {
		Matrix getMinSpanningTree(const Matrix& matrix)
		{
			std::vector<Edge> edges, min_edges;
			for (size_t i = 0; i < matrix.size(); ++i)
			{
				for (size_t j = i; j < matrix[i].size(); ++j)
				{
					edges.push_back(Edge{i, j, matrix[i][j]});
				}
			}

			std::sort(edges.begin(), edges.end(),
				[](const Edge& lhs, const Edge& rhs) {return lhs.distance > rhs.distance;});
			std::vector<size_t> components(matrix.size());
			std::iota(components.begin(), components.end(), 0);	

			for (const auto& edge : edges)
			{
				if (components[edge.from] != components[edge.to])
				{
					size_t new_component = components[edge.from];
					size_t old_component = components[edge.to];
					min_edges.push_back(edge);

					for (size_t& component : components)
					{
						component = (component == old_component ? new_component 
																: component);
					}
				}
			}

			return createCompleteGraph(min_edges);
		}
	}
}

std::vector<size_t> CChristofidesSolver::solve(const Matrix& matrix, size_t root)
{
	std::vector<size_t> min_sequence;

	Matrix min_matrix = Kruskal::getMinSpanningTree(matrix);

	std::vector<size_t> odd_degree_vertices;
	auto isNotZero = [](size_t value) {return value != 0;};

	for (size_t i = 0; i < min_matrix.size(); ++i)
	{
		size_t degree = std::count_if(min_matrix[i].begin(), min_matrix[i].end(), isNotZero);
		if (degree % 2 != 0)
		{
			odd_degree_vertices.push_back(i);
		}
	}

	return min_sequence;
}
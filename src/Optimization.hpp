#include "Common/Types.hpp"

namespace TSP {
	namespace Optimization {
		constexpr size_t inf_limit{0xFFFFFFFF}; 

		std::vector<size_t> twoOpt(std::vector<size_t> path, const Matrix& matrix, size_t iterations=1000);

	}
}
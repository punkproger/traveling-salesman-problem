#include "Common/Types.hpp"

#include <vector>
#include <string>

namespace TSP {
	namespace ImageGenerator {

		void saveImageFromPath(const std::string& filename,
							   const std::vector<size_t>& path,
							   const std::vector<Point>& points);

	}
}
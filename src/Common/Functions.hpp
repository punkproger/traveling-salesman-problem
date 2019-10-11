#include "Types.hpp"

namespace TSP {
	namespace Common {

		Matrix createMatrix(const std::vector<Point>& points);
		double distance(const Point& lhs, const Point& rhs);

	}
}
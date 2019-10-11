#pragma once

#include <string>

#include "Common/Types.hpp"

namespace TSP {
	namespace FileReader {
		
		std::vector<Point> readPlateFile(const std::string& filename);
	
	}
}
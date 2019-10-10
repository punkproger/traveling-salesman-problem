#pragma once

#include <string>

#include "Common/Types.hpp"

namespace TSP {
	namespace FileReader {
		
		Matrix readPlateFile(const std::string& filename);
	
	}
}
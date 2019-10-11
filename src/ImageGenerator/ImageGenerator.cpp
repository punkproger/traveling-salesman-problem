#include "ImageGenerator/ImageGenerator.hpp"

#include <algorithm>

#include "ThirdParty/Bitmap/bitmap_image.hpp"

using namespace TSP;

constexpr size_t size_x{800};
constexpr size_t size_y{800};

constexpr size_t offset_x{size_x/10};
constexpr size_t offset_y{size_y/10};

constexpr size_t circle_radius{2};

void ImageGenerator::saveImageFromPath(const std::string& filename,
					   				   const std::vector<size_t>& path,
					   				   const std::vector<Point>& points)
{
	double min_x, max_x, min_y, max_y;

	auto set_min_max_coordinates = 
	[&](const Point& point)
	{
		min_x = std::min(point.x, min_x);
		min_y = std::min(point.y, min_y);
		max_x = std::max(point.x, max_x);
		max_y = std::max(point.y, max_y);
	};
	std::for_each(points.begin(), points.end(), set_min_max_coordinates);

	double scale_x = size_x/(max_x-min_x + 2*offset_x);
	double scale_y = size_y/(max_y-min_y + 2*offset_y);

	cartesian_canvas canvas(size_x, size_y);

	canvas.pen_color(255, 0, 0);
	for (size_t i = 0; i < path.size()-1; ++i)
	{
		double origin_x = points[path[i]].x * scale_x;
		double origin_y = points[path[i]].y * scale_y;
		double destination_x = points[path[i+1]].x * scale_x;
		double destination_y = points[path[i+1]].y * scale_y;;

		canvas.line_segment(origin_x, origin_y, destination_x, destination_y);
	}

	double origin_x = points[path.front()].x * scale_x;
	double origin_y = points[path.front()].y * scale_y;
	double destination_x = points[path.back()].x * scale_x;
	double destination_y = points[path.back()].y * scale_y;;
	canvas.line_segment(origin_x, origin_y, destination_x, destination_y);

	canvas.pen_color(0, 0, 0);
	for (const auto& point : points)
	{
		canvas.fill_circle(point.x * scale_x, point.y * scale_y, circle_radius);
	}

	canvas.image().save_image(filename);
}
#include "pch.h"
#include "triangle.h"

#define DEG_TO_RAD(x) (x) / 180.0 * 3.1415926
#define RAD_TO_DEG(x) (x) * 180 / 3.1415926


triangle::triangle(double x, double y, double l, int angle) : start_x(x), start_y(y), side_length(l), rotation_angle(angle) {}

extern void gb_draw_triangle(CDC* pDC, triangle& to_draw, double scale, Point_2D& translation, int screenX, int screenY)
{
	Point_2D actual_start, temp;
	gb_point_convert_from_global_to_screen(actual_start, Point_2D(to_draw.start_x, to_draw.start_y));
	gb_point_convert_from_global_to_screen(temp, Point_2D(to_draw.start_x + to_draw.side_length * cos(DEG_TO_RAD(to_draw.rotation_angle - 30)),
		to_draw.start_y + to_draw.side_length * sin(DEG_TO_RAD(to_draw.rotation_angle - 30))));
	pDC->MoveTo(actual_start.x, actual_start.y);
	pDC->LineTo(temp.x, temp.y);
	gb_point_convert_from_global_to_screen(temp, Point_2D(to_draw.start_x + to_draw.side_length * cos(DEG_TO_RAD(to_draw.rotation_angle + 30)),
		to_draw.start_y + to_draw.side_length * sin(DEG_TO_RAD(to_draw.rotation_angle + 30))));
	pDC->LineTo(temp.x, temp.y);
	pDC->LineTo(actual_start.x, actual_start.y);
}
